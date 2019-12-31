#pragma once
#include <string>
#include "Student.h"
class SoftwareStudent :
	public Student
{
public:
	SoftwareStudent();
	SoftwareStudent(std::string studentID, std::string first_name, std::string last_name, std::string email_address,
		int age, int number_of_days[], Degree degree);

	//overridden virtual methods from Student class
	Degree get_degree_type() override;
	void print() override;

	//Destructor
	~SoftwareStudent();
};

