#include <iostream>
#include <string>
#include "Student.h"
#include "Roster.h"

int main() {

    std::cout<<"Scripting and Programming - Applications - C867"<<std::endl;
    std::cout<<"-----------------------------------------------"<<std::endl;
    std::cout<<"C++"<<std::endl;
    std::cout<<"011825393"<<std::endl;
    std::cout<<"Christopher Burzo"<<std::endl;
    std::cout<<"-----------------------------------------------"<<std::endl;

    Roster roster;
    const std::string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
                                       "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
                                       "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
                                       "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
                                       "A5,Chris,Burzo,cburzo@wgu.edu,33,10,1,3,SOFTWARE"};

    //Data Parser:: My Parsing strategy is to stop at every comma in the string and grab the whole sub string before it.
    //I use the variable commaCount to keep track of my comma index and to serve as an ID of which variable to store the data.
    //I then take the data in the variables and create a new student with them. Then I store them into the roster. I nest this
    //whole process in two loops and repeat for each string of data in Student Table.

    //The nested for loop will parse and ADD each student to the student roster
    for(int j = 0; j < 5; j++){
        int i = 0;
        int commaCount = 0;
        std::string collect;

        std::string sID;
        std::string fN;
        std::string lN;
        std::string eM;
        int age;
        int arrOfCourse[3];
        std::string dP;

        while(i < studentData[j].size()){

            if(studentData[j][i] != ','){
                collect += studentData[j][i];
            }

            if(studentData[j][i] == ','){
                commaCount = commaCount + 1;

                if(commaCount == 1){
                    sID = collect;
                    collect.erase (0, collect.size());
                }
                if(commaCount == 2){
                    fN = collect;
                    collect.erase (0, collect.size());
                }
                if(commaCount == 3){
                    lN = collect;
                    collect.erase (0, collect.size());
                }
                if(commaCount == 4){
                    eM = collect;
                    collect.erase (0, collect.size());
                }
                if(commaCount == 5){
                    age = stoi(collect);
                    collect.erase (0, collect.size());
                }
                if(commaCount == 6){
                    arrOfCourse[0] = stoi(collect);
                    collect.erase (0, collect.size());
                }
                if(commaCount == 7){
                    arrOfCourse[1] = stoi(collect);
                    collect.erase (0, collect.size());
                }
                if(commaCount == 8){
                    arrOfCourse[2] = stoi(collect);
                    collect.erase (0, collect.size());
                }
            }
            if(commaCount == 8){
                dP = collect;
            }
            i++;
        }
        roster.add(sID, fN, lN, eM, age, arrOfCourse[0], arrOfCourse[1], arrOfCourse[2], dP);

    }

    roster.printAll();
    std::cout<<std::endl;
    roster.printInvalidEmails();
    std::cout<<std::endl;

    for(int i = 0; i < roster.classRosterArray.size(); i++){
        roster.printAverageDaysInCourse(roster.classRosterArray[i]->getStudentId());
    }
    std::cout<<std::endl;

    roster.printByDegreeProgram(SOFTWARE);

    std::cout<<std::endl;

    roster.remove("A3");

    roster.printAll();

    roster.remove("A3");

    for (int i = 0; i < roster.classRosterArray.size(); ++i) {
        roster.classRosterArray[i]->~Student();
    }

    return 0;
}
