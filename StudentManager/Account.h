#pragma once
#include <string>
#include <stdlib.h>
class Account 
{
public:
	void quit(); // klaar, maybe nog later in andere classes stoppen
	void showAccounts(); // klaar
	void getAccounts(); // klaar
	void findAccount(); // klaar
	void checkClearance(); // klaar
	void login(); // klaar
	int getclearance() const; // klaar
	void setLogin(); // klaar


private:
	int n;
	int id;
	char firstName;
	char lastName;
	char Birthdate;
	int age;
	char username;
	char password;
	int clearance;
};