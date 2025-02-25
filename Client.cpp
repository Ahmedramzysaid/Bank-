#include"Client.h"
#include <string.h>
#include<iostream>
#include"Validation.h"

using namespace std;

Client::Client() :Person()
{
	balance = 1500;
}
Client::Client(int id, string name, string password, double balance) : Person(id, name, password)
{
	setBalance(balance);
}
void Client::setBalance(double b)
{
	if (Validation::balanceValid(b))
		balance = b;
	else
	{
		cout << "\aYou should Enter Balance more than 1500" << endl;
		exit(0);
	}

}
double Client::getBalance()
{
	return balance;
}
void Client::deposit(double amount)
{
	balance += amount;

}
void Client::withdraw(double amount)
{
	if (balance - amount > 1500)
		balance -= amount;
	else {
		cout << "\aCan Not withdraw. Your balanc is less than 1500" << endl;
		exit(0);
	}
}
void Client::transferTo(double amount, Client& recipient)
{
	withdraw(amount);
	recipient.balance += amount;
}
void Client::checkBalance()
{
	if (Validation::balanceValid(balance))
		cout << "Your Balance is: " << balance << ". So you can withdraw and transfer to" << endl;
	else
		cout << "Your Balance is: " << balance << ". You can't withdraw and transfer to" << endl;
}
void Client::display()
{
	Person::display();
	cout << "Balance: " << getBalance() << endl;
	cout << "\n*************************************\n";
}
;