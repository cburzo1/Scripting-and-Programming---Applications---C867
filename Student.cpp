#include "Student.h"
#include <iostream>
//
// Created by gmcbu on 2/15/2024.
//

Student::Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age,
                 std::vector<int> numberOfDaysToCompleteCourse, std::string degreeProgram){
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    this->numberOfDaysToCompleteCourse = numberOfDaysToCompleteCourse;
    this->degreeProgram = degreeProgram;
}

const std::string & Student::getStudentId() const {
    return studentID;
}

void Student::setStudentId(std::string &studentId) {
    studentID = studentId;
}

const std::string &Student::getFirstName() const {
    return firstName;
}

void Student::setFirstName(const std::string &firstName) {
    Student::firstName = firstName;
}

const std::string &Student::getLastName() const {
    return lastName;
}

void Student::setLastName(const std::string &lastName) {
    Student::lastName = lastName;
}

const std::string &Student::getEmailAddress() const {
    return emailAddress;
}

void Student::setEmailAddress(const std::string &emailAddress) {
    Student::emailAddress = emailAddress;
}

int Student::getAge() const {
    return age;
}

void Student::setAge(int age) {
    Student::age = age;
}



const std::string &Student::getDegreeProgram() const {
    return degreeProgram;
}

void Student::setDegreeProgram(const std::string &degreeProgram) {
    Student::degreeProgram = degreeProgram;
}

void Student::print(){
    std::cout<<"StudentID: "<<getStudentId()<<std::endl;
    std::cout<<"First Name: "<<getFirstName()<<std::endl;
    std::cout<<"Last Name: "<<getLastName()<<std::endl;
    std::cout<<"Email Address: "<<getEmailAddress()<<std::endl;
    std::cout<<"Age: "<<getAge()<<std::endl;
    std::cout<<"Number of Days to Complete Each Course: "<<std::endl;
    std::cout<<"1: "<<getNumberOfDaysToCompleteCourse()[0]<<std::endl;
    std::cout<<"2: "<<getNumberOfDaysToCompleteCourse()[1]<<std::endl;
    std::cout<<"3: "<<getNumberOfDaysToCompleteCourse()[2]<<std::endl;
    std::cout<<"Degree Program: "<<getDegreeProgram()<<std::endl;
}

void Student::setNumberOfDaysToCompleteCourse(const std::vector<int> &numberOfDaysToCompleteCourse) {
    Student::numberOfDaysToCompleteCourse = numberOfDaysToCompleteCourse;
}

const std::vector<int> &Student::getNumberOfDaysToCompleteCourse() const {
    return numberOfDaysToCompleteCourse;
}

Student::~Student() {
    std::cout<<"Object Purged"<<std::endl;
}
