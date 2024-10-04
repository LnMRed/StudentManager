#include "Teacher.h"
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

void Teacher::addStudent() // also has to check if student already has grades if thats not the case give him a line in student file with 0's
{
    std::string id;
    std::string firstName;
    std::string lastName;
    std::string birthDate;
    std::string age;
    std::string group;
    std::cout << "id" << " " << " " << "first name" << " " << "last name" << "birthdate dd/m/y" << " " << "age" << " " << "group" << std::endl;
    std::cin >> id >> firstName >> lastName >> birthDate >> age >> group;
    std::ofstream studentFile("student_data.txt", std::ios::app);
    std::ofstream studentGrades("student_grades.txt", std::ios::app); //file met alle cijfers van studenten
    
    if (studentFile.is_open() && studentGrades.is_open())
    {
        studentFile << id << " " << firstName << " " << lastName<< " " << birthDate << " " << age << " " << group << std::endl;
        studentGrades << id << " " << firstName << " " << lastName << " " << birthDate << " " << age << " " << group << " " << 0 << " " << 0 << " " << 0 << " " << 0 << std::endl;
        studentFile.close();
        studentGrades.close();
        std::cout << "Registration of student successful." << std::endl;
    }
    else {
        std::cerr << "Error: Unable to open student_data.txt for writing." << std::endl;
    }
}

void Teacher::removeStudent(std::string iid)
{
    // verwijderen van grades op dezelfde manier moet nog gerefactored worden
    std::string id = iid;
    std::ifstream studentdata("student_data.txt");
    std::ofstream studentdataTemp("student_data_temp.txt");

    std::string line;
    if (studentdata.is_open() && studentdataTemp.is_open())
    {
        while (getline(studentdata, line))
        {
            std::istringstream iss(line);
            std::string compareID;
            iss >> compareID;
            if (id != compareID)
            {
                studentdataTemp << line << '\n';
            }
        }
        studentdata.close();
        studentdataTemp.close();

        std::remove("student_data.txt");
        if (std::rename("student_data_temp.txt", "student_data.txt") != 0) 
        {
            std::cerr << "error opening files.\n";
        }
    }
    else
    {
        std::cerr << "file unable to be opened" << std::endl;
    }
}

void Teacher::removeGrades(std::string iid) // moet later id laten doorpasen
{
    std::string id = iid;
    std::ifstream studentgrades("student_grades.txt");
    std::ofstream studentgradesTemp("student_grades_temp.txt");

    std::string line;

    if (studentgrades.is_open() && studentgradesTemp.is_open())
    {
        while (getline(studentgrades, line))
        {
            std::istringstream iss(line);
            std::string compareID;
            iss >> compareID;
            if (id != compareID)
            {
                studentgradesTemp << line << '\n';
            }
        }
        studentgrades.close();
        studentgradesTemp.close();

        std::remove("student_grades.txt");
        if (std::rename("student_grades_temp.txt", "student_grades.txt") != 0) 
        {
            std::cerr << "error renaming file.\n";
        }
    }
    else
    {
        std::cerr << "file unable to be opened" << std::endl;
    }
}

void Teacher::displayReports()
{
    std::ifstream studentGrades("student_grades.txt");
    if (studentGrades.is_open())
    {
        std::string line;
        // alles van student data word per line geprint
        while (getline(studentGrades, line))
        {
            std::cout << line << std::endl;
        }
        if (!studentGrades.eof()) 
        {
            std::cerr << "error reading file" << std::endl;
        }
        studentGrades.close();
    }
    else
    {
        std::cerr << "unable to open file" << std::endl;
    }   
}

void Teacher::modReports()
{
    std::string subc;
    std::string subcpp;
    std::string subjava;
    std::string subruby;

    std::string rsubc;
    std::string rsubcpp;
    std::string rsubjava;
    std::string rsubruby;
    std::string id;

    std::string line;

    std::cout << "Enter student ID and the grades c, cpp, java, ruby: ";
    std::cin >> id >> subc >> subcpp >> subjava >> subruby;

    std::ifstream studentgrades("student_grades.txt");
    std::ofstream studentgradesTemp("student_grades_temp.txt");

    if (studentgrades.is_open() && studentgradesTemp.is_open()) {
        while (getline(studentgrades, line)) {

            std::string firstName;
            std::string lastName;
            std::string birthDate;
            std::string age;
            std::string group;

            std::istringstream iss(line);
            std::string compareID;
            iss >> compareID >> firstName >> lastName >> birthDate >> age >> group >> rsubc >> rsubcpp >> rsubjava >> rsubruby;

            // If the IDs match, update the line with new grades
            if (id == compareID) {
                studentgradesTemp << id << " " << firstName << " " << lastName << " " << birthDate << " " << age << " "<< group << subc << " " << subcpp << " " << subjava << " " << subruby << '\n';
            }
            else {
                // Otherwise, write the original line to the temporary file
                studentgradesTemp << line << '\n';
            }
        }

        studentgrades.close();
        studentgradesTemp.close();

        // Replace the original file with the modified content
        std::remove("student_grades.txt");
        std::rename("student_grades_temp.txt", "student_grades.txt");

        std::cout << "Modification of grades is successful." << std::endl;
    }
    else {
        std::cerr << "Error: Unable to open student_grades.txt for reading or writing." << std::endl;
    }
}

