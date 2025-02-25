#pragma once
#include<iostream>
#include<string>
using namespace std;
class Validation
{
public:
	static bool nameValid(string name);
	static bool passValid(string password);
	static bool balanceValid(double balance);
	static bool salaryValid(double salary);

};




