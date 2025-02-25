
#pragma once
#include<string>
#include<iostream>
#include"Client.h"
#include"FileManager.h"
using namespace std;
class ClientManger
{
public:
	static int ClientMenu();
	static void ClientOption(Client c);
	static Client login();
	static void updatePassword(Client c, string password);
	static void backOption(Client c);
	static int backMenu();

};