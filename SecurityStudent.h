#pragma once
#include <string>
#include "Student.h"
class SecurityStudent :
	public Student
{
public:
	SecurityStudent();
	SecurityStudent(std::string studentID, std::string first_name, std::string last_name, std::string email_address,
		int age, int number_of_days[], Degree degree); //full constructor

	Degree get_degree_type() override;
	void print() override;

	~SecurityStudent();
};

