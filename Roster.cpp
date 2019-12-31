#include "Roster.h";

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
}