#pragma once
#include<iostream>
#include "Person.h"
#include<string>
using namespace std;

class Client : public Person
{
private:
	double balance;
public:
	Client();
	Client(int id, string name, string password, double balance);
	void setBalance(double b);
	double getBalance();
	void deposit(double amount);
	void withdraw(double amount);
	void transferTo(double amount, Client& recipient);
	void checkBalance();
	void display();

};