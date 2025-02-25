#include "AdminManager.h"
#include<iostream>
#include <vector>
#include"FileManager.h"
#include"Admin.h"
#include"Screens.h"
using namespace std;


int AdminManager::adminMenu()
{
	int choies = -1;
	while (choies == -1) {
		cout << "\n\n \t >>> ADMIN MENU <<<\n\n";
		cout << "1 - Add new Client\n";
		cout << "2 - Search for A Client\n";
		cout << "3 - Edit Client\n";
		cout << "4 - List all Clients\n";
		cout << "5 - Add new Employee\n";
		cout << "6 - Search for An Employee\n";
		cout << "7 - Edit Employee\n";
		cout << "8 - List all Employees\n";
		cout << "9 - Updata password\n";
		cout << "10 - Display\n";
		cout << "11 - Logout \n";
		cout << "\t Enter your choies: ";
		cin >> choies;
		if (!(1 <= choies && choies <= 11)) {
			cout << "\nInvalid choies. Try again\n";
			choies = -1;
		}
	}
	return choies;
}

Admin AdminManager::login()
{
	vector<Admin> allAdmin;
	int pos, id;
	string password;
	bool found = false;
	allAdmin = FileManager::getAllAdmins();
	while (!found) {
		cout << "\nEnter ID: ";
		cin >> id;
		cout << "Password: ";
		cin >> password;
		for (int i = 0; i < allAdmin.size(); i++) {
			if (allAdmin[i].getId() == id && allAdmin[i].getPassword() == password) {
				pos = i;
				found = true;
				break;
			}
		}
		if (!found)
			system("cls");
		cout << "Invalid Id or Password. Try again..." << endl;
	}

	return allAdmin[pos];

}

void AdminManager::updatePassword(Admin a, string newPassword)
{
	FileManager::removeAdmin(a);
	a.setPassword(newPassword);
	FileManager::addAdmin(a);
}

int AdminManager::backMenu()
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

void AdminManager::backOptions(Admin a)
{
	int choies = backMenu();
	system("cls");
	switch (choies)
	{
	case 1:
	{
		adminOptions(a);
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

void AdminManager::adminOptions(Admin a)
{
	int choies = adminMenu();
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
		FileManager::addClient(c);
		cout << "\tClient Added succesfully." << endl;
		backOptions(a);
	}
	break;
	case 2:
	{
		int id;
		Client c;
		cout << "\nEnter ID for Client to search for: ";
		cin >> id;
		c = FileManager::searchForClient(id);
		c.display();
		backOptions(a);
	}
	break;
	case 3:
	{
		int id;
		Client c;
		cout << "\nEnter ID for Client to Edit info: ";
		cin >> id;
		c = FileManager::searchForClient(id);
		a.editClient(c);
		backOptions(a);
	}
	break;
	case 4:
	{
		cout << "\n\tAll Client Info\n";
		a.listClient();
		backOptions(a);
	}
	break;
	case 5:
	{
		Employee e;
		int id;
		double salary;
		string name, password;
		cout << "\n ID: ";
		cin >> id;
		e.setId(id);
		cout << "\n Name: ";
		cin >> name;
		e.setName(name);
		cout << "\n Passowrd: ";
		cin >> password;
		e.setPassword(password);
		cout << "\n Salary: ";
		cin >> salary;
		e.setSalary(salary);
		FileManager::addEmployee(e);
		cout << "\Employee Added succesfully." << endl;
		backOptions(a);
	}
	break;
	case 6:
	{
		int id;
		Employee e;
		cout << "\nEnter ID for Employee to search for: ";
		cin >> id;
		e = FileManager::searchForEmployee(id);
		e.display();
		backOptions(a);
	}
	break;
	case 7:
	{
		int id;
		Employee e;
		cout << "\nEnter ID for Client to Edit info: ";
		cin >> id;
		e = FileManager::searchForEmployee(id);
		a.editEmployee(e);
		backOptions(a);
	}
	break;
	case 8:
	{
		cout << "\n\tAll Employee Info\n";
		a.listEmployee();
		backOptions(a);
	}
	break;
	case 9:
	{
		string newPassword;
		cout << "\nEnter new password: ";
		cin >> newPassword;
		updatePassword(a, newPassword);
		backOptions(a);

	}
	break;
	case 10:
	{
		cout << "\n\t Admin Info\n";
		a.display();
		backOptions(a);
	}
	break;
	case 11:
	{
		Screens::loginOptions();
	}
	default:
		break;
	}
}