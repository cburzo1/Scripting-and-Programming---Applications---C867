//
// Created by gmcbu on 2/15/2024.
//

#include "Roster.h"
#include "Student.h"
#include <iostream>

//Add appends the new student at the end of the Roster
void Roster::add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, std::string degreeprogram){
    std::vector<int> daysInCourseArr = {daysInCourse1, daysInCourse2, daysInCourse3};

    Student *student = new Student(studentID, firstName,lastName,emailAddress, age, daysInCourseArr, degreeprogram);

    classRosterArray.push_back(student);
}

void Roster::remove(std::string studentID){
    bool flag = false;
    int idxCount = -1;

    for(int i = 0; i < classRosterArray.size(); i++){
        if(classRosterArray[i]->getStudentId() == studentID){
            flag = true;
            idxCount = i;
            break;
        }
    }

    if(flag == 0){
        std::cout<<"CANNOT REMOVE::Student Does Not Exist!"<<std::endl;
    }else{
        classRosterArray.erase(classRosterArray.cbegin() + idxCount);
        std::cout<<"Student Removed!"<<std::endl;
    }
}

void Roster::printAll() {
    for(int i = 0; i < classRosterArray.size(); i++){
        classRosterArray[i]->print();
        std::cout<<std::endl;
    }
}

void Roster::printAverageDaysInCourse(std::string studentID){
    bool flag = false;
    int idxCount = -1;

    for(int i = 0; i < classRosterArray.size(); i++){
        if(classRosterArray[i]->getStudentId() == studentID){
            flag = true;
            idxCount = i;
            break;
        }
    }

    if(flag == 0){
        std::cout<<"CANNOT GET AVERAGE::Student Does Not Exist!"<<std::endl;
    }else {
        int num1 = classRosterArray[idxCount]->getNumberOfDaysToCompleteCourse()[0];
        int num2 = classRosterArray[idxCount]->getNumberOfDaysToCompleteCourse()[1];
        int num3 = classRosterArray[idxCount]->getNumberOfDaysToCompleteCourse()[2];
        int avg = (num1 + num2 + num3) / 3;

        std::cout << classRosterArray[idxCount]->getStudentId() << " Average: " << avg << std::endl;
    }
}

void Roster::printInvalidEmails(){

    std::vector<std::string> arr;

    for(int i = 0; i < classRosterArray.size(); i++){
        bool flagDot = 0;
        bool flagAt = 0;
        bool flagSpace = 0;
        for(int j = 0; j < classRosterArray[i]->getEmailAddress().size(); j++){
            if(classRosterArray[i]->getEmailAddress()[j] == '.'){
                flagDot = 1;
            }else if(classRosterArray[i]->getEmailAddress()[j] == '@'){
                flagAt = 1;
            }else if(classRosterArray[i]->getEmailAddress()[j] == ' '){
                flagSpace = 1;
            }
        }
        if(flagAt == 0 || flagDot == 0 || flagSpace == 1){
            arr.push_back(classRosterArray[i]->getEmailAddress());
        }
    }

    for(int i = 0; i < arr.size(); i++) {
        std::cout<<arr[i]<<std::endl;
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram){
    if(degreeProgram == 0){
        for(int i = 0; i < classRosterArray.size(); i++){
            if(classRosterArray[i]->getDegreeProgram() == "SECURITY"){
                classRosterArray[i]->print();
            }
        }
    }

    if(degreeProgram == 1){
        for(int i = 0; i < classRosterArray.size(); i++){
            if(classRosterArray[i]->getDegreeProgram() == "NETWORK"){
                classRosterArray[i]->print();
            }
        }
    }

    if(degreeProgram == 2){
        for(int i = 0; i < classRosterArray.size(); i++){
            if(classRosterArray[i]->getDegreeProgram() == "SOFTWARE"){
                classRosterArray[i]->print();
            }
        }
    }
}