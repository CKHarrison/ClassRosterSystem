#pragma once
#include <string>
#include <iostream>
#include "Student.h"
#include "NetworkStudent.h"
#include "SoftwareStudent.h"
#include "SecurityStudent.h"


class Roster
{
private:
	int last_element_position;
	int size_of_array;
	Student** classRosterArray;
public:
	Roster();
	Roster(int size_of_array);
	void convert_and_add_data(std::string data);
	void add(std::string studentID, std::string firstName, std::string lastName, std::string emailAddress, int age,
		int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree);
	void remove(std::string studentID);
	void printAll();
	void printAverageDaysInCourse(std::string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(Degree degreeProgram);
	Student* getStudentAt(int index);

	~Roster();
};

