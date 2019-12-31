#include <iostream>
#include "NetworkStudent.h"

//empty constructor with student base initlization
NetworkStudent::NetworkStudent() : Student() {
	degree_type = NETWORKING;
}
//full constructor
NetworkStudent::NetworkStudent(std::string studentID, std::string first_name, std::string last_name,
	std::string email_address, int age, int number_of_days[], Degree degree)
	: Student(studentID, first_name, last_name, email_address, age, number_of_days) {
	degree_type = NETWORKING;
}

Degree NetworkStudent::get_degree_type() {
	return  NETWORKING;
}

void NetworkStudent::print() {
	Student::print();
	std::cout << "Degree Program: NETWORKING" << std::endl;
}
//destructor
NetworkStudent::~NetworkStudent() {
	Student::~Student();
}