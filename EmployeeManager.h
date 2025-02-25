#pragma once
#include<iostream>
#include"Client.h"
#include"FileManager.h"
#include"ClientManager.h"
#include"Employee.h"
#include<string>
using namespace std;
class EmployeeManager
{
public:
	static int employeeMenue();
	static void newClient(Client c);
	static void listAllClients();
	static Client searchForClient(int id);
	static void editClientInfo(Client c);
	static Employee login();
	static void employeeOptions(Employee e);
	static void updatePassword(Employee e, string newPassword);
	static int backMenu();
	static void backOptions(Employee e);
};
