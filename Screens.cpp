#include "Screens.h"
#include<iostream>
#include "ClientManager.h"
#include"EmployeeManager.h"
#include"AdminManager.h"
#include<string>
#include<Windows.h>
using namespace std;



void Screens::bankName()
{

	int row, col, k, space = 0;
	cout << "\n\n\n\n\n\n";
	for (row = 1; row <= 5; row++) {
		for (space = 1; space <= 35; space++) {
			cout << " ";
		}

		for (col = 1; col <= 5; col++)
		{
			if (col == 1 || row == 1 || row == 3 || row == 5 || col == 5)
				cout << "* ";
			else
				cout << "  ";

		}

		for (space = 1; space <= 3; space++) {
			cout << " ";
		}
		for (col = 1; col <= 5; col++)
		{
			if (col == 1 || col == 5 || row == 1 || row == 3)
				cout << "* ";
			else
				cout << "  ";

		}
		for (space = 1; space <= 3; space++) {
			cout << " ";
		}
		for (col = 1; col <= 5; col++)
		{
			if (col == 1 || col == 5 || col == row)
				cout << "* ";
			else
				cout << "  ";

		}
		for (space = 1; space <= 3; space++) {
			cout << " ";
		}
		for (col = 1; col <= 5; col++)
		{
			if (col == 1 || (col == row && row >= 3) || (((col + row) == (5 + 1)) && row <= 3) || row == 3 && col == 2)
				cout << "* ";
			else
				cout << "  ";

		}
		Sleep(60);
		cout << endl;

	}
	cout << endl;
	for (row = 1; row <= 5; row++) {

		for (space = 1; space <= 37; space++) {
			cout << " ";
		}
		for (col = 1; col <= 5; col++)
		{
			if (col == 1 || (col == row && row <= 3) || (((col + row) == (5 + 1)) && row <= 3) || col == 5)
				cout << "* ";
			else
				cout << "  ";

		}
		for (space = 1; space <= 3; space++) {
			cout << " ";
		}
		for (col = 1; col <= 5; col++)
		{
			if (col == 3 || row == 1 && (col >= 2 && col <= 4) || row == 5 && (col >= 2 && col <= 4))
				cout << "* ";
			else
				cout << "  ";

		}
		for (space = 1; space <= 3; space++) {
			cout << " ";
		}
		for (col = 1; col <= 5; col++)
		{
			if (row == 1 || row == 3 || row == 5 || col == 1 && row < 4 || col == 5 && row > 3)
				cout << "* ";
			else
				cout << "  ";

		}
		for (space = 1; space <= 3; space++) {
			cout << " ";
		}
		for (col = 1; col <= 5; col++)
		{
			if (col == 1 || row == 1 || row == 3 || col == 5 && row < 3 || row == col && row>3)
				cout << "* ";
			else
				cout << "  ";

		}
		cout << endl;
		Sleep(60);

	}
	cout << "\n\t\t\t\t\t\t";
	string str = "Welcom To Our Bank System...";
	for (int i = 0; i < str.size(); i++) {
		cout << str[i];
		Sleep(50);
	}
	Sleep(2000);
};

int Screens::loginAs()
{
	int choies = -1;
	while (choies == -1) {
		cout << "\n\n\t>>> LOGIN AS <<<\n\n";
		cout << "1 - Client.\n";
		cout << "2 - Employee.\n";
		cout << "3 - Admin.\n\n";
		cout << "\t Enter Your choies: ";
		cin >> choies;
		if (!(1 <= choies && choies <= 3))
		{
			choies = -1;
			system("cls");
			cout << "Invalid input. Try again..." << endl;
		}
	}
	return choies;
}
void Screens::loginOptions()
{
	int choies = Screens::loginAs();
	system("cls");
	switch (choies) {
	case 1:
	{
		Client c;
		c = ClientManger::login();
		system("cls");
		ClientManger::ClientOption(c);
	}
	break;
	case 2:
	{
		Employee e;
		e = EmployeeManager::login();
		system("cls");
		EmployeeManager::employeeOptions(e);
	}
	break;
	case 3:
	{
		Admin a;
		a = AdminManager::login();
		system("cls");
		AdminManager::adminOptions(a);
	}
	default:
		break;

	}
}

void Screens::runApp()
{
	Screens::bankName();
	system("cls");
	Screens::loginOptions();
}