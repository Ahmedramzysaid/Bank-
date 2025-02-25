#include"Person.h"
#include <string>
#include<iostream>
#include"Validation.h"
using namespace std;

Person::Person()
{
	id = 0;
	name = password = " ";
};
Person::Person(int id, string name, string password)
{
	setId(id);
	setName(name);
	setPassword(password);
};
void Person::setId(int i) {
	id = i;
};
void Person::setName(string n) {
	if (Validation::nameValid(n))
		name = n;
	else if (n.size() < 5)
		cout << "You entered less than 5 characters" << endl;
	else if (n.size() > 20)
		cout << "You entered more than 20 characters" << endl;
	else
		cout << "Not valid enterd" << endl;
};
void Person::setPassword(string p) {
	if (Validation::passValid(p))
		password = p;
	else if (p.size() < 8) {
		cout << " You password should be more than 8. Try again" << endl;
		string pass;
		while (!Validation::passValid(pass))
		{
			cout << " Password: ";
			cin >> pass;
		}
		password = pass;
	}
	else
	{
		cout << "You password should be less than 20. Try again" << endl;
		string pass;
		while (!Validation::passValid(pass))
		{
			cout << " Password: ";
			cin >> pass;
		}
		password = pass;
	}

};
int Person::getId() {
	return id;
};
string Person::getName() {
	return name;
};
string Person::getPassword() {
	return password;
};
void Person::display() {
	cout << " ID: " << getId() << endl;
	cout << " Name: " << getName() << endl;
	cout << " Password: " << getPassword() << endl;
};