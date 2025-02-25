#pragma once
#include<iostream>
#include<string>
using namespace std;
class Person
{
protected:
	int id;
	string name;
	string password;
public:
	Person();
	Person(int id, string name, string password);
	void setId(int i);
	void setName(string n);
	void setPassword(string p);
	int getId();
	string getName();
	string getPassword();
	void display();
};



