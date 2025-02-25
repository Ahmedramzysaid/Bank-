#include"Admin.h"
#include"Client.h"
#include"Employee.h"
#include<string>
#include "FileManager.h"
#include<vector>
#include<iostream>
using namespace std;

Admin::Admin() :Employee()
{

};
Admin::Admin(int id, string name, string password, double salary) :Employee(id, name, password, salary) {

}
void Admin::display() {
	Employee::display();
};
void Admin::addClient(Client& c) {
	FileManager::addClient(c);
}
Client Admin::searchClient(int id) {
	vector<Client> v;
	v = FileManager::getAllClients();
	int pos = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].getId() == id) {
			pos = i;
			break;
		}
	}
	return v[pos];
}
void Admin::listClient() {
	vector<Client> v;
	v = FileManager::getAllClients();
	for (int i = 0; i < v.size(); i++) {
		v[i].display();
	}
}
void Admin::editClient(Client c) {
	FileManager::removeClient(c);
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
	FileManager::addClient(c);
}
void Admin::addEmployee(Employee& e) {
	FileManager::addEmployee(e);
}
Employee* Admin::searchEmployee(int id) {
	vector<Employee> v;
	v = FileManager::getAllEmployees();
	int pos = 0;
	for (int i = 0; i < v.size(); i++) {
		if (v[i].getId() == id) {
			pos = i;
			break;
		}
	}
	return &v[pos];
}
void Admin::listEmployee() {
	vector<Employee> v;
	v = FileManager::getAllEmployees();
	for (int i = 0; i < v.size(); i++) {
		v[i].display();
	}
}
void Admin::editEmployee(Employee e) {
	FileManager::removeEmployee(e);
	int id, salary;
	string name, password;
	cout << "\nId: ";
	cin >> id;
	e.setId(id);
	cout << "\nName: ";
	cin >> name;
	e.setName(name);
	cout << "\nPassword: ";
	cin >> password;
	e.setPassword(password);
	cout << "\nBalance: ";
	cin >> salary;
	e.setSalary(salary);
	FileManager::addEmployee(e);
}