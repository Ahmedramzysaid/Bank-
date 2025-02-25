#include"ClientManager.h"
#include<iostream>
#include"Client.h"
#include"FileManager.h"
#include"Employee.h"
#include<vector>
#include<Windows.h>
#include"Screens.h"
using namespace std;

int ClientManger::ClientMenu() {
	int choies = -1;
	while (choies == -1) {
		cout << "\n\n \t >>> CLIENT MENU <<<\n\n";
		cout << "1 - Check my balance\n";
		cout << "2 - Deposit\n";
		cout << "3 - Withdraw\n";
		cout << "4 - Transfar To\n";
		cout << "5 - Updata password\n";
		cout << "6 - Display\n";
		cout << "7 - Back \n";
		cout << "\t Enter your choies: ";
		cin >> choies;
		if (!(1 <= choies && choies <= 7)) {
			cout << "\nInvalid choies. Try again\n";
			choies = -1;
		}
	}
	return choies;
}
void ClientManger::ClientOption(Client c) {
	int choies = ClientMenu();
	system("cls");
	switch (choies)
	{
	case 1:
	{
		c.checkBalance();
		backOption(c);
	}
	break;
	case 2:
	{
		FileManager::removeClient(c);
		int amount;
		cout << "Amount: ";
		cin >> amount;
		c.deposit(amount);
		FileManager::addClient(c);
		backOption(c);
	}
	break;
	case 3:
	{
		FileManager::removeClient(c);
		int amount;
		cout << "\nAmount: ";
		cin >> amount;
		c.withdraw(amount);
		FileManager::addClient(c);
		backOption(c);
	}
	break;
	case 4:
	{
		int id, amount;
		Client recipient;
		cout << "\nAmount: ";
		cin >> amount;
		cout << "Enter Id for Client: ";
		cin >> id;
		recipient = FileManager::searchForClient(id);
		FileManager::removeClient(c);
		FileManager::removeClient(recipient);
		c.transferTo(amount, recipient);
		FileManager::addClient(c);
		FileManager::addClient(recipient);
		backOption(c);
	}
	break;
	case 5:
	{
		string newPassword;
		cout << "\nEnter new password: ";
		cin >> newPassword;
		updatePassword(c, newPassword);
		backOption(c);
	}
	break;
	case 6:
	{
		c.display();
		backOption(c);
	}
	break;
	default:
		break;
	};
}
Client ClientManger::login()
{
	vector<Client> allClient;
	int pos, id;
	string password;
	bool found = false;
	allClient = FileManager::getAllClients();
	while (!found) {
		cout << "\nEnter ID: ";
		cin >> id;
		cout << "Password: ";
		cin >> password;
		for (int i = 0; i < allClient.size(); i++) {
			if (allClient[i].getId() == id && allClient[i].getPassword() == password) {
				pos = i;
				found = true;
				break;
			}
		}
		if (!found)
			system("cls");
		cout << "Invalid Id or Password. Try again..." << endl;
	}

	return allClient[pos];

}
;

void ClientManger::updatePassword(Client c, string newPassword) {
	FileManager::removeClient(c);
	c.setPassword(newPassword);
	FileManager::addClient(c);
}

void ClientManger::backOption(Client c)
{
	int choies = backMenu();
	system("cls");
	switch (choies)
	{
	case 1:
	{
		ClientOption(c);
	}
	break;
	case 2:
	{
		Screens::loginOptions();
	}
	default:
		break;
	}
}

int ClientManger::backMenu()
{
	int choies = -1;
	while (choies == -1) {
		cout << "\n\n\t\t\t1 - Back To Menu...";
		cout << "\t\t\t2 - Logout...";
		cout << "\n\n\tEnter Your choies: ";
		cin >> choies;
		if (!(1 <= choies && choies <= 2))
		{
			choies = -1;
			cout << "Invalid input. Try again." << endl;
		}

	}
	return choies;
}