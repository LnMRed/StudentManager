#include "Account.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "Student.h"
#include "Teacher.h"

void Account::quit()
{
    exit(0);
}

void Account::showAccounts()
{
    // moet vgm die fstream gebruiken om te kijken
    getAccounts();
}

void Account::getAccounts()
{
    std::ifstream studentdata("student_data.txt");
    if (studentdata.is_open()) 
    {
        std::string line;
        // alles van student data word per line geprint
        while (getline(studentdata, line)) 
        {
            std::cout << line << std::endl;
        }
        studentdata.close();
    }
    else
    {
        std::cerr << "unable to open file" << std::endl;
    }
}

void Account::findAccount()
{
    std::ifstream studentdata("student_data.txt");
    std::string id;
    std::string line;
    std::cin >> id;
    if(studentdata.is_open())
    {
        while (getline(studentdata, line)) 
        {
            std::istringstream iss(line);
            std::string compareID;
            iss >> compareID;
            if (id == compareID) 
            {
                std::cout << line << std::endl;
            }
        }
        studentdata.close();
    }
    else 
    {
        std::cerr << "file unable to be opened" << std::endl;
    }
    
}

void Account::checkClearance()
{
    switch (getclearance())
    {
    case 1:
          std::cout << "you have student permissions" << std::endl;
          break;
    case 2:
          std::cout << "you have teacher permissions" << std::endl;
          break;
    case 3:
          std::cout << "you have admin permissions" << std::endl;
          break;            
    }
}

void Account::login() {
    std::string attemptuser;
    std::string pass;
    int localclearance = 0;
    bool correct = false;

    std::cout << "Enter username: ";
    std::cin >> attemptuser;
    std::cout << "Enter password: ";
    std::cin >> pass;

    std::ifstream userFile("user_data.txt");
    if (userFile.is_open())
    {
        std::string storedUser, storedPass;
        while (userFile >> storedUser >> storedPass >> localclearance)
        {
            if (attemptuser == storedUser && pass == storedPass)
            {

                correct = true;
                this->clearance = localclearance;
                std::cout << "Login successful." << std::endl;
                checkClearance();
                break;
            }
        }
        userFile.close();
        if (!correct) {
            std::cout << "username or password is incorrect" << std::endl;
        }
    }
}

int Account::getclearance() const
{
    return clearance;
}

void Account::setLogin()
{
    std::string username;
    std::string password; 
    int clearance;
    std::cin >> username >> password >> clearance;
    std::ofstream userFile("user_data.txt", std::ios::app);
    if(userFile.is_open())
    {
        userFile << username << " " << password << " " << clearance << std::endl;
        userFile.close();
        std::cout << "Registration successful." << std::endl;
    }
    else {
        std::cerr << "Error: Unable to open user_data.txt for writing." << std::endl;
    }  
}