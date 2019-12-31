#include "Roster.h"

Roster::Roster() {
	this->size_of_array = 0;
	this->last_element_position = -1;
	this->classRosterArray = nullptr;
}

Roster::Roster(int size_of_array) {
	this->size_of_array = size_of_array;
	this->last_element_position = -1;
	this->classRosterArray = new Student*[size_of_array];
}

Student *Roster::getStudentAt(int index) {
	return classRosterArray[index];
}

void Roster::convert_and_add_data(std::string row) {
	if (last_element_position < size_of_array) {
		last_element_position++;

		Degree degree_choice;
		if (row.find("SOFTWARE")) {
			degree_choice = SOFTWARE;
		}
		else if(row.find("SECURITY")){
			degree_choice = SECURITY;
		}
		else if (row.find("NETWORK")) {
			degree_choice = NETWORKING;
		}
		else {
			std::cout << "Invalid Degree" << std::endl;
			exit(-1);
		}

		//assign student id
		int right_hand_side = row.find(",");
		std::string student_id = row.substr(0, right_hand_side);

		//first name
		int left_hand_side = right_hand_side + 1;
		right_hand_side = row.find(",", left_hand_side);
		std::string first_name = row.substr(left_hand_side, right_hand_side - left_hand_side);

		//last name 
		left_hand_side = right_hand_side + 1;
		right_hand_side = row.find(",", left_hand_side);
		std::string last_name = row.substr(left_hand_side, right_hand_side - left_hand_side);

		//email address
		left_hand_side = right_hand_side + 1;
		right_hand_side = row.find(",", left_hand_side);
		std::string email = row.substr(left_hand_side, right_hand_side - left_hand_side);

		//age 
		left_hand_side = right_hand_side + 1;
		right_hand_side = row.find(",", left_hand_side);
		int age = stoi(row.substr(left_hand_side, right_hand_side - left_hand_side));

		//day1
		left_hand_side = right_hand_side + 1;
		right_hand_side = row.find(",", left_hand_side);
		int day1 = stoi(row.substr(left_hand_side, right_hand_side - left_hand_side));

		//day2
		left_hand_side = right_hand_side + 1;
		right_hand_side = row.find(",", left_hand_side);
		int day2 = stoi(row.substr(left_hand_side, right_hand_side - left_hand_side));

		//day3
		left_hand_side = right_hand_side + 1;
		right_hand_side = row.find(",", left_hand_side);
		int day3 = stoi(row.substr(left_hand_side, right_hand_side - left_hand_side));

		//add everything together
		add(student_id, first_name, last_name, email, age, day1, day2, day3, degree_choice);
	}
	else {
		std::cout << "Array has exceeded max capacity";
		exit(-1);
	}
}

void Roster::add(std::string student_id, std::string first_name, std::string last_name, std::string  email, 
	int age, int day1, int day2, int day3, Degree degree_choice) {
	//create array
	int number_of_days[Student::number_of_days_size];
	number_of_days[0] = day1;
	number_of_days[1] = day2;
	number_of_days[2] = day3;
	if (degree_choice == SOFTWARE) {
		classRosterArray[last_element_position] = new SecurityStudent(student_id, first_name, last_name, email, age, number_of_days, degree_choice);
	}
	else if (degree_choice == SECURITY) {
		classRosterArray[last_element_position] = new SecurityStudent(student_id, first_name, last_name, email, age, number_of_days, degree_choice);
	}
	else {
		classRosterArray[last_element_position] = new SecurityStudent(student_id, first_name, last_name, email, age, number_of_days, degree_choice);
	}
}

void Roster::printAll() {
	for (int i = 0; i <= this->last_element_position; i++) {
		(this->classRosterArray[i])->print();
	}
}





	


int main() {
	int numStudents = 5;

	const std::string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Chris,Harrison,char363@wgu.edu,29,10,20,30,SOFTWARE" };

	Roster *classRoster = new Roster(numStudents);
	std::cout << "Adding students" << std::endl;

	for (int i = 0; i < numStudents; i++) {
		classRoster->convert_and_add_data(studentData[i]);
	}

	std::cout << "\n";
	std::cout << "Displaying all students" << std::endl;
	classRoster->printAll();
}