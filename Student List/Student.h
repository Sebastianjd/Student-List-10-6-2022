#include <iostream>

using namespace std;

class Student
{
private:
	//Attributes
	string name;
	string lastName;
	int grade;
public:
	//Setters
	void setName(string name) { this->name = name; }
	void setLastName(string lastName) { this->lastName = lastName; }
	void setGrade(int grade) { this->grade = grade; }
	//Getters
	string getName() { return name; }
	string getLastName() { return lastName; }
	int getGrade() { return grade; }
};