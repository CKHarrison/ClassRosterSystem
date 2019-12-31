#pragma once
#include <string>
#include "degree.h"
class Student
{
public:
	const static int number_of_days_size = 3; //using this to control the size of the number of days array

protected:
	std::string studentID;
	std::string first_name;
	std::string last_name;
	std::string email_address;
	int age;
	int number_of_days[number_of_days_size];
	Degree degree_type; //going to use for a virtual method
public:
	Student(); //no args constructor
	Student(std::string studentID, std::string first_name, std::string last_name, std::string email_address,
		int age, int number_of_days[]); //full constructor

	//getter and setter methods
	std::string get_studentID();
	std::string get_first_name();
	std::string get_last_name();
	std::string get_email_address();
	int get_age();
	int* get_number_of_days();
	virtual Degree get_degree_type() = 0; //virtual method

	void set_student_id(std::string studentID);
	void set_first_name(std::string first_name);
	void set_last_name(std::string last_name);
	void set_email_address(std::string email_address);
	void set_age(int age);
	void set_number_of_days(int number_of_days[]);

	//print method
	virtual void print() = 0;

	//destructor
	~Student();
};

