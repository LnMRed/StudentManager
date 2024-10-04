#pragma once
class Admin
{
	void addStudent(int id, char firstName, char lastName, char birthDate, int age, char group, char username, char password);
	void addTeacher(int id, char firstName, char lastName, char birthDate, int age, int salary, char username, char password);
	void displayStudentList();
	void displayTeacherList();
	void displayReport(); // displays average grades
	void displayReportDetails(); // displays all grades
	void AddReports();
	void modifyReports();
	void findStudent();
	void update();
	void makeAccount(int securityClearance, char username, char password);
};

