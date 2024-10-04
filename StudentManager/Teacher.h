#pragma once
#include <string>
class Teacher 
{
public:
	void addStudent(); // moet ook een line maken met student data
	void removeStudent(std::string id); // use id with the cin
	void removeGrades(std::string id); // ook klaar
	void displayReports(); // ook klaar
	void modReports(); // finally klaar
	

private:
	int id;
	char firstName;
	char lastName;
	char birthDate;
	int age;
	int salary; // kijken of die late nog nodig is
	char username;
	char password; 
};