#include <iomanip>
#include <iostream>
#include <string>
#include "degree.h"
#include "Student.h"

Student::Student() { //empty constructor
	this->studentID = "";
	this->first_name = "";
	this->last_name = "";
	this->email_address = "";
	this->age = 0;
	//setting the number of days to complete array to 0
	for (size_t i{ 0 }; i < number_of_days_size; i++) {
		this->number_of_days[i] = 0;
	}
}

//full cosntructor
Student::Student(std::string studentID, std::string first_name, std::string last_name, std::string email_address,
	int age, int number_of_days[]) {

	this->studentID = studentID;
	this->first_name = first_name;
	this->last_name = last_name;
	this->email_address = email_address;
	this->age = age;
	for (size_t i{ 0 }; i < number_of_days_size; ++i) {
		this->number_of_days[i] = number_of_days[i];
	}
}

//getter methods
std::string Student::get_studentID() {
	return studentID;
}

std::string Student::get_first_name() {
	return first_name;
}

std::string Student::get_last_name() {
	return last_name;
}

std::string Student::get_email_address() {
	return email_address;
}

int Student::get_age() {
	return age;
}

int * Student::get_number_of_days() {
	return number_of_days;
}

//Setter methods

void Student::set_student_id(std::string studentID) {
	this->studentID = studentID;
}

void Student::set_first_name(std::string first_name) {
	this->first_name = first_name;
}

void Student::set_last_name(std::string last_name) {
	this->last_name = last_name;
}

void Student::set_email_address(std::string email_address) {
	this->email_address = email_address;
}

void Student::set_age(int age) {
	this->age = age;
}

void Student::set_number_of_days(int number_of_days[]) {
	for (size_t i{ 0 }; i < number_of_days_size; ++i) {
		this->number_of_days[i] = number_of_days[i];
	}
}

void Student::print() {
	std::cout << std::left  << studentID;
	std::cout << std::left << "\t" << first_name;
	std::cout << std::left << "\t" << last_name;
	std::cout << std::left << "\t" << email_address;
	std::cout << std::left << "\t" << age;
	std::cout << std::left << "\t" << "{" << number_of_days[0];
	std::cout << std::left << "\t" << number_of_days[1];
	std::cout << std::left << "\t" << number_of_days[2] << "} ";
}

Student::~Student() {

}