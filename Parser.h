#pragma once
#include<iostream>
#include<vector>
#include"Admin.h"
#include"Employee.h"
#include"Client.h"
#include<string>
using namespace std;
class Parser
{
	string str;
public:
	static vector<string> split(string line);
	static Client parserToClient(string line);
	static Employee parserToEmployee(string line);
	static Admin parserToAdmin(string line);
};



