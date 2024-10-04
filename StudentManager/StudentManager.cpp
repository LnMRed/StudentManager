// StudentManager.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <string>
#include <fstream>
#include <iostream>
#include "Account.h"
#include "Admin.h"
#include "Student.h"
#include "Teacher.h"
/*
    to do:
    1. be able to display reports // done
    2. modify
    3. add reports
    4. if a new student is created set report details to zero // done
    5. make individual student or teacher files
*/
int main()
{
    char Decision = 0;
    bool repeat = true;
    std::string iid;
    Account account1;
    Teacher teacher;
    char username[] = "";
    char password[] = "";
    char decision[] = "";
    while (1)
    {
        std::cout << "welcome to the student manager\n";
        std::cout << "please enter your details\n";

        account1.login();
       
        std::cout << "Enter a character to make a decision" << std::endl;
        if (account1.getclearance() == 1)
        {
            while (repeat == true) 
            {
                std::cout << "s to show all students" << std::endl;
                std::cout << "q to quit" << std::endl;
                std::cin >> Decision;
                switch (Decision)
                {
                case 's':
                    account1.showAccounts();
                    break;
                case 'q':
                    account1.quit();
                    repeat = false;
                    break;
                }
            }
        }
        else if (account1.getclearance() == 2)
        {
            // hier komen switch cases van de leraar moet later nog in functies gerefactored worden
            while (repeat == true)
            {
                std::cout << "a to add a student" << std::endl;
                std::cout << "s to show all students" << std::endl;
                std::cout << "f to find student by id" << std::endl;
                std::cout << "v to remove student via id" << std::endl;
                std::cout << "r to display all grades" << std::endl;
                std::cout << "m to modify grades via id" << std::endl;
                std::cout << "q to quit" << std::endl;
                std::cin >> Decision;
                switch (Decision)
                {
                case 'a': // hier alle opties
                    teacher.addStudent();
                    break;
                case 's':
                    account1.showAccounts();
                    break;
                case 'f':
                    account1.findAccount();
                    break;
                case 'v':
                    std::cout << "type in id of student you want to remove" << std::endl; // kan allemaal hier in andere functies zetten
                    std::cin >> iid;
                    teacher.removeStudent(iid);
                    teacher.removeGrades(iid);
                    break;
                case 'r':
                    teacher.displayReports();
                    break;
                case 'm':
                    teacher.modReports();
                    break;
                case 'q':
                    account1.quit();
                    repeat = false;
                    break;
                }
            }
        }
        else if (account1.getclearance() == 3)
        {
            // hier komen switch cases van de admin moet later nog in functies gerefactored worden
            while (repeat == true)
            {
                std::cout << "a to add account" << std::endl;
                std::cout << "q to quit" << std::endl;
                std::cin >> Decision;
                switch (Decision)
                {
                case 'a': // hier alle opties

                    account1.setLogin();
                    break;

                case 'q':
                    account1.quit();
                    repeat = false;
                    break;
                }
            }
        }
        
    }
    repeat = true;
}

