#include"FileManager.h"
#include"Parser.h"
#include"Client.h"
#include"Employee.h"
#include"Admin.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
void FileManager::addClient(Client& c) {
	fstream f;
	f.open("Clients.txt", ios::out | ios::app);
	if (f.is_open()) {
		f << c.getId() << " " << c.getName() << " " << c.getPassword() << " " << c.getBalance() << endl;
	}
	else
		cout << "file not open" << endl;

	f.close();
};

void FileManager::addEmployee(Employee& e) {
	fstream f;
	f.open("Employees.txt", ios::out | ios::app);
	if (f.is_open()) {
		f << e.getId() << " " << e.getName() << " " << e.getPassword() << " " << e.getSalary() << endl;
	}
	else
		cout << "file not open" << endl;
	f.close();
};

void FileManager::addAdmin(Admin& a) {
	fstream f;
	f.open("Admins.txt", ios::out | ios::app);
	if (f.is_open()) {
		f << a.getId() << " " << a.getName() << " " << a.getPassword() << " " << a.getSalary() << endl;
	}
	else
		cout << "file not open" << endl;
	f.close();
}
void FileManager::removeClient(Client c)
{
	fstream f, f2;
	string line;
	Client client;
	f.open("Clients.txt", ios::in | ios::out);
	if (f.is_open()) {
		while (getline(f, line)) {
			client = Parser::parserToClient(line);
			if (client.getId() != c.getId()) {
				f2.open("Client.txt", ios::out | ios::app);
				if (f2.is_open()) {
					f2 << client.getId() << " " << client.getName() << " " << client.getPassword() << " " << client.getBalance() << endl;
				}
				
				f2.close();
			}
		}

	}
	f.close();
	remove("Clients.txt");
	if (rename("Client.txt", "Clients.txt") != 0)
		cout << "Error renaming file" << endl;
	/*else
		cout << "File renamed successfully";*/
}
void FileManager::removeEmployee(Employee e) {
	fstream f, f2;
	string line;
	Employee employee;
	f.open("Employees.txt", ios::in | ios::out);
	if (f.is_open()) {
		while (getline(f, line)) {
			employee = Parser::parserToEmployee(line);
			if (employee.getId() != e.getId()) {
				f2.open("employee.txt", ios::out | ios::app);
				if (f2.is_open()) {
					f2 << employee.getId() << " " << employee.getName() << " " << employee.getPassword() << " " << employee.getSalary() << endl;
				}
				else
				{
					exit(0);
				}
				f2.close();
			}
		}

	}
	f.close();
	remove("Employees.txt");
	if (rename("Employee.txt", "Employees.txt") != 0)
		perror("Error renaming file");
	/*else
		cout << "File renamed successfully";*/
}
void FileManager::removeAdmin(Admin a)
{
	fstream f, f2;
	string line;
	Admin admin;
	f.open("Admins.txt", ios::in | ios::out);
	if (f.is_open()) {
		while (getline(f, line)) {
			admin = Parser::parserToAdmin(line);
			if (admin.getId() != a.getId()) {
				f2.open("employee.txt", ios::out | ios::app);
				if (f2.is_open()) {
					f2 << admin.getId() << " " << admin.getName() << " " << admin.getPassword() << " " << admin.getSalary() << endl;
				}
				else
				{
					exit(0);
				}
				f2.close();
			}
		}

	}
	f.close();
	remove("Admins.txt");
	if (rename("Admin.txt", "Admins.txt") != 0)
		cout << "Error renaming file" << endl;
	/*else
		cout << "File renamed successfully";*/
}
Client FileManager::searchForClient(int id)
{
	vector<Client> v;
	int pos = 0;
	v = FileManager::getAllClients();
	for (int i = 0; i < v.size(); i++) {
		if (v[i].getId() == id) {
			pos = i;
			break;
		}
	}
	return v[pos];
}
Employee FileManager::searchForEmployee(int id)
{
	vector<Employee> v;
	int pos = 0;
	v = FileManager::getAllEmployees();
	for (int i = 0; i < v.size(); i++) {
		if (v[i].getId() == id) {
			pos = i;
			break;
		}
	}
	return v[pos];
};

vector<Client> FileManager::getAllClients() {
	vector<Client> v;
	fstream f;
	f.open("Clients.txt", ios::in);
	if (f.is_open()) {
		string line;
		while (getline(f, line)) {
			Client c;
			c = Parser::parserToClient(line);
			v.push_back(c);
		}
	}
	f.close();
	return v;
};

vector<Employee> FileManager::getAllEmployees() {
	vector<Employee> v;
	fstream f;
	f.open("Employees.txt", ios::in);
	if (f.is_open()) {
		string line;
		while (getline(f, line)) {
			Employee e;
			e = Parser::parserToEmployee(line);
			v.push_back(e);
		}
	}
	f.close();
	return v;
};

vector<Admin> FileManager::getAllAdmins() {
	vector<Admin> v;
	fstream f;
	f.open("Admins.txt", ios::in);
	if (f.is_open()) {
		string line;
		while (getline(f, line)) {
			Admin a;
			a = Parser::parserToAdmin(line);
			v.push_back(a);
		}
	}
	f.close();
	return v;
};
void FileManager::removeAllClients() {

	remove("Clients.txt");
	fstream f;
	f.open("Client.txt", ios::out);
	f.close();
	if (rename("Client.txt", "Clients.txt") != 0)
		perror("Error renaming file");
	/*else
		cout << "File renamed successfully";*/

};
void FileManager::removeAllEmployees() {

	remove("Employees.txt");
	fstream f;
	f.open("Employees.txt", ios::out);
	f.close();
};
void FileManager::removeAllAdmins() {

	remove("Admins.txt");
	fstream f;
	f.open("Admins.txt", ios::out);
	f.close();
};

