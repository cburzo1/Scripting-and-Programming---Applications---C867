//
// Created by gmcbu on 2/15/2024.
//

#ifndef PROJECTS_ROSTER_H
#define PROJECTS_ROSTER_H

#include "Student.h"
#include "degree.h"

class Roster{
public:
    //Student *classRosterArray[30];
    std::vector<Student *> classRosterArray;
    void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, std::string degreeprogram);
    void remove(std::string studentID);
    void printAll();
    void printAverageDaysInCourse(std::string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
};

#endif //PROJECTS_ROSTER_H
