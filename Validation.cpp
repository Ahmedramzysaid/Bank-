#include"Validation.h"
#include<string>
#include<iostream>
using namespace std;

bool Validation::nameValid(string name)
{
	bool valid = false;
	if (name.size() >= 5 && name.size() <= 20)
	{
		for (int i = 0; i < name.size(); i++)
		{
			if (isalpha(name[i]))
			{
				valid = true;
			}
			else
			{
				valid = false;
				break;
			}
		};
		return valid;
	}
	return valid;
};
bool Validation::passValid(string password)
{
	return (password.size() >= 8 && password.size() <= 20);
};
bool Validation::balanceValid(double balance)
{
	if (balance >= 1500)
		return true;
	else
		return false;
}
bool Validation::salaryValid(double salary)
{
	if (salary >= 5000)
		return true;
	else
		return false;
}