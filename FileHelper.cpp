#include "FileHelper.h"
#include<string>
#include<iostream>
#include<fstream>
#include"FileManager.h"
#include<vector>
using namespace std;

void FileHelper::saveLast(string fileName, int id)
{
	fstream f;
	f.open(fileName, ios::in | ios::app);
	f.close();
}
int FileHelper::getLast(string fileName)
{
	return 0;
}

void FileHelper::saveClient(Client c)
{
	FileManager::addClient(c);
}
void FileHelper::getClients()
{
	vector<Client> v;
	v = FileManager::getAllClients();
	for (int i = 0; i < v.size(); i++) {
		v[i].display();
	}
}

void FileHelper::getEmployees()
{
	vector<Employee> v;
	v = FileManager::getAllEmployees();
	for (int i = 0; i < v.size(); i++) {
		v[i].display();
	}
}


void FileHelper::getAdmins()
{
	vector<Admin> v;
	v = FileManager::getAllAdmins();
	for (int i = 0; i < v.size(); i++) {
		v[i].display();
	}
}
