//
// Created by gmcbu on 2/15/2024.
//

#ifndef PROJECTS_STUDENT_H
#define PROJECTS_STUDENT_H

#include <string>
#include <vector>

class Student{
    private:
        std::string studentID;
        std::string firstName;
        std::string lastName;
        std::string emailAddress;
        int age;
        std::vector<int> numberOfDaysToCompleteCourse;
        std::string degreeProgram;

    public:

        Student(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age,
                std::vector<int> numberOfDaysToCompleteEachCourse, std::string degreeProgram);

        void print();

    void setNumberOfDaysToCompleteCourse(const std::vector<int> &numberOfDaysToCompleteCourse);

    const std::string & getStudentId() const;

    void setStudentId(std::string &studentId);

    const std::string &getFirstName() const;

    void setFirstName(const std::string &firstName);

    const std::string &getLastName() const;

    void setLastName(const std::string &lastName);

    const std::string &getEmailAddress() const;

    void setEmailAddress(const std::string &emailAddress);

    int getAge() const;

    void setAge(int age);

    const std::vector<int> &getNumberOfDaysToCompleteCourse() const;

    const std::string &getDegreeProgram() const;

    void setDegreeProgram(const std::string &degreeProgram);

    virtual ~Student();
};

#endif //PROJECTS_STUDENT_H
