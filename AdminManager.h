#pragma once
#include<iostream>
#include"Admin.h"
using namespace std;
class AdminManager
{
public:
	static int adminMenu();
	static Admin login();
	static void updatePassword(Admin a, string newPassword);
	static void adminOptions(Admin a);
	static int backMenu();
	static void backOptions(Admin a);
};