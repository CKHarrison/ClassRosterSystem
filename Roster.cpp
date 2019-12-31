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



void Roster::convert_and_add_data(std::string row) {
	if (last_element_position < size_of_array) {
		last_element_position++;

	

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

		//degree
		left_hand_side = right_hand_side + 1;
		right_hand_side = row.find(",", left_hand_side);
		std::string degree = row.substr(left_hand_side, right_hand_side - left_hand_side);

		Degree degree_choice;
		if (degree == "SECURITY") {
			degree_choice = SECURITY;
		}
		else if (degree == "SOFTWARE") {
			degree_choice = SOFTWARE;
		}
		else {
			degree_choice = NETWORKING;
		}


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
		classRosterArray[last_element_position] = new SoftwareStudent(student_id, first_name, last_name, email, age, number_of_days, degree_choice);
	}
	else if (degree_choice == SECURITY) {
		classRosterArray[last_element_position] = new SecurityStudent(student_id, first_name, last_name, email, age, number_of_days, degree_choice);
	}
	else {
		classRosterArray[last_element_position] = new NetworkStudent(student_id, first_name, last_name, email, age, number_of_days, degree_choice);
	}
}

void Roster::printAll() {
	for (int i = 0; i <= this->last_element_position; i++) (this->classRosterArray[i])->print();
}


void Roster::remove(std::string ID) {
	bool student_exists = false;
	for (size_t i{ 0 }; i <= last_element_position; i++) {
		if (this->classRosterArray[i]->get_studentID() == ID) {
			student_exists = true;
			delete this->classRosterArray[i];
			//move last book to this position so there isn't a gap in the array
			this->classRosterArray[i] = this->classRosterArray[last_element_position];
			last_element_position--;

		}
	}
	if (student_exists) {
		std::cout << "Student with ID of: " << ID << " was removed from the roster" << std::endl;
	}
	else {
		std::cout << "No Student matching that ID was found" << std::endl;
	}

}

void Roster::printAverageDaysInCourse(std::string studentID) {
	bool found_student = false;
	for (size_t i{ 0 }; i <= last_element_position; i++) {
		if (this->classRosterArray[i]->get_studentID() == studentID) {
			found_student = true;
			int *ptr = classRosterArray[i]->get_number_of_days();
			std::cout << "The average number of days left in the student " << studentID << " is: "
				<< (ptr[0] + ptr[1] + ptr[2]) / 3 << std::endl;
		}
	}
	if (!found_student) {
		std::cout << "A student with that ID was not found";
	}
}
//returning the pointer to the student
Student * Roster::getStudentAt(int index) {
	return classRosterArray[index];
}



void Roster::printInvalidEmails() {
	bool any = false;
	//loop through all of the emails in the array
	for (size_t i{ 0 }; i < last_element_position; i++) {
		any = false;
		//pick out email
		std::string  email = classRosterArray[i]->get_email_address();

		//check to see if that email is invalid
		if (email.find('@') != std::string::npos && email.find('.') != std::string::npos && email.find(" ") == std::string::npos) {

		}
		else {
			std::cout << email << std::endl;
		}

	}
}

void Roster::printByDegreeProgram(int degree) {
	Degree degree_version = (Degree) degree;
	for (int i = 0; i <= last_element_position; i++) {
		if (this->classRosterArray[i]->get_degree_type() == degree_version) {
			this->classRosterArray[i]->print();
		}
	}
}

Roster::~Roster() {
	for (int i = 0; i <= last_element_position; i++) {
		delete this->classRosterArray[i];
	}
	delete classRosterArray;
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
	//displaying students
	std::cout << "\n";
	std::cout << "Displaying all students" << std::endl;
	classRoster->printAll();

	std::cout << "\n";

	//printing invalid emails
	std::cout << "Printing invalid emails" << std::endl;
	std::cout << "\n";
	classRoster->printInvalidEmails();

	//average day to completion
	std::cout << "\n";
	std::cout << "Average days to completion per student" << std::endl;
	for (int i = 0; i < numStudents; i++) {
		classRoster->printAverageDaysInCourse(classRoster->getStudentAt(i)->get_studentID());
	}

	std::cout << "\n";
	//print students based on degree type
	std::cout << "Students with the Software degree: " << std::endl;
	classRoster->printByDegreeProgram(2);


	//removing student from roster
	std::cout << "\n";
	std::cout << "Removing Student with id A3 from roster" << std::endl;
	classRoster->remove("A3");
	classRoster->remove("A3");

	system("pause");
	return 0;


}