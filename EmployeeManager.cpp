#include "EmployeeManager.h"
#include<iostream>
#include"ClientManager.h"
#include"FileManager.h"
#include"Client.h"
#include<string>
#include"Screens.h"
using namespace std;

int EmployeeManager::employeeMenue()
{
	int choies = -1;
	while (choies == -1) {
		cout << "\n\n \t >>> EMPLOYEE MENU <<<\n\n";
		cout << "1 - Add new Client\n";
		cout << "2 - Search for A Client\n";
		cout << "3 - Edit client\n";
		cout << "4 - List all client\n";
		cout << "5 - Updata password\n";
		cout << "6 - Display\n";
		cout << "7 - Logout \n";
		cout << "\t Enter your choies: ";
		cin >> choies;
		if (!(1 <= choies && choies <= 7)) {
			cout << "\nInvalid choies. Try again\n";
			choies = -1;
		}
	}
	return choies;
}

void EmployeeManager::newClient(Client c)
{
	FileManager::addClient(c);
}

void EmployeeManager::listAllClients()
{
	vector<Client> v;
	v = FileManager::getAllClients();
	for (int i = 0; i < v.size(); i++) {
		v[i].display();
	}
}

Client EmployeeManager::searchForClient(int id)
{
	Client c;
	c = FileManager::searchForClient(id);
	return c;
}

void EmployeeManager::editClientInfo(Client c)
{
	Employee e;
	e.editClient(c);
}

Employee EmployeeManager::login()
{
	vector<Employee> allEmployee;
	int pos, id;
	string password;
	bool found = false;
	allEmployee = FileManager::getAllEmployees();
	while (!found) {
		cout << "\nEnter ID: ";
		cin >> id;
		cout << "Password: ";
		cin >> password;
		for (int i = 0; i < allEmployee.size(); i++) {
			if (allEmployee[i].getId() == id && allEmployee[i].getPassword() == password) {
				pos = i;
				found = true;
				break;
			}
		}
		if (!found)
			system("cls");
		cout << "Invalid Id or Password. Try again..." << endl;
	}

	return allEmployee[pos];

}

void EmployeeManager::updatePassword(Employee e, string newPassword)
{
	FileManager::removeEmployee(e);
	e.setPassword(newPassword);
	FileManager::addEmployee(e);
}

int EmployeeManager::backMenu()
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

void EmployeeManager::backOptions(Employee e)
{
	int choies = backMenu();
	system("cls");
	switch (choies)
	{
	case 1:
	{
		employeeOptions(e);
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


void EmployeeManager::employeeOptions(Employee e)
{
	int choies = employeeMenue();
	system("cls");
	switch (choies)
	{
	case 1:
	{
		Client c;
		int id;
		double balance;
		string name, password;
		cout << "\n ID: ";
		cin >> id;
		c.setId(id);
		cout << "\n Name: ";
		cin >> name;
		c.setName(name);
		cout << "\n Passowrd: ";
		cin >> password;
		c.setPassword(password);
		cout << "\n Balance: ";
		cin >> balance;
		c.setBalance(balance);
		newClient(c);
		cout << "\tClient Added succesfully." << endl;
		backOptions(e);
	}
	break;
	case 2:
	{
		int id;
		Client c;
		cout << "\nEnter ID for Client to search for: ";
		cin >> id;
		c = searchForClient(id);
		c.display();
		backOptions(e);
	}
	break;
	case 3:
	{
		int id;
		Client c;
		cout << "\nEnter ID for Client to Edit info: ";
		cin >> id;
		c = searchForClient(id);
		editClientInfo(c);
		backOptions(e);
	}
	break;
	case 4:
	{
		listAllClients();
		backOptions(e);

	}
	break;
	case 5:
	{
		string newPassword;
		cout << "\nEnter new password: ";
		cin >> newPassword;
		updatePassword(e, newPassword);
		backOptions(e);
	}
	break;
	case 6:
	{
		cout << "\n\tEmpolyee Info\n";
		e.display();
		backOptions(e);
	}
	break;
	case 7:
	{
		Screens::loginOptions();
	}
	default:
		break;
	};
}
