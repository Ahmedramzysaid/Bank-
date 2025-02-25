#pragma once
#include"Employee.h"
#include"Client.h"
#include<string.h>
using namespace std;
class Admin : public Employee
{
public:
	Admin();
	Admin(int id, string name, string password, double salary);
	void display();
	void addClient(Client& c);
	Client searchClient(int id);
	void listClient();
	void editClient(Client c);
	void addEmployee(Employee& e);
	Employee* searchEmployee(int id);
	void listEmployee();
	void editEmployee(Employee e);
};