#include"Employee.h"
#include"FileManager.h"
#include"Validation.h"
#include<string>
#include"Client.h"
#include<vector>
#include<iostream>
#include<fstream>
#include"Parser.h"
#include<filesystem>
using namespace std;


Employee::Employee() :Person() {
	salary = 0 ;
};
Employee::Employee(int id, string name, string password, double salary) :Person(id, name, password) {
	setSalary(salary);
};
void Employee::setSalary(double s) {
	if (Validation::salaryValid(s))
		salary = s;
	else
	{
		cout << "\aYour salary is less than 5000" << endl;
		
	}
};
double Employee::getSalary() {
	return salary;
};
void Employee::display() {
	Person::display();
	cout << " Salary: " << getSalary() << endl;
	cout << "\n**************************\n";
};
void Employee::addClient(Client& a) {
	FileManager::addClient(a);
}
Client Employee::searchForClient(int id) {
	Client c;
	c = FileManager::searchForClient(id);
	return c;
}
void Employee::listClient() {
	vector<Client> v;
	v = FileManager::getAllClients();
	for (int i = 0; i < v.size(); i++) {
		v[i].display();
	}
}
void Employee::removeClient(Client& c) {
	FileManager::removeClient(c);
}

void Employee::editClient(Client& c) {
	removeClient(c);
	int id, balance;
	string name, password;
	cout << "\nId: ";
	cin >> id;
	c.setId(id);
	cout << "\nName: ";
	cin >> name;
	c.setName(name);
	cout << "\nPassword: ";
	cin >> password;
	c.setPassword(password);
	cout << "\nBalance: ";
	cin >> balance;
	c.setBalance(balance);
	addClient(c);
}