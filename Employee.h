
#pragma once
#include"Person.h"
#include<string>
#include"Client.h"

class Employee :public Person
{
protected:
	double salary;
public:
	Employee();
	Employee(int id, string name, string password, double salary);
	void setSalary(double s);
	double getSalary();
	void display();
	void addClient(Client& a);
	void removeClient(Client& c);
	Client searchForClient(int id);
	void listClient();
	void editClient(Client& c);
};


