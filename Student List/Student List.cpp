//Sebastian Diaz
//10/1/2022

#include <iostream>
#include <string>
#include <fstream>
#include "Student.h"
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int main()
{	
	int total = 0;
	int avg;
	string name;
	string lastName;

	//Student list 
	vector <Student> studentList;

	vector <Student>sortedList;

	vector <int>grades;

	string currentLine;

	//File to open
	ifstream file("example.txt");

	if (file.is_open())
	{
		//Looping every line in the file
		while (getline(file, currentLine))
		{
			Student student;

			vector <string> tokens;

			string info;

			stringstream studentInfo(currentLine);
			
			//Tokenizing each line in the file by an space
			while (getline(studentInfo, info, ' '))
			{
				tokens.push_back(info);
			}

			//Setting the attributes of each student with the corresponding information
			student.setName(tokens[0]);
			student.setLastName(tokens[1]);
			student.setGrade(stoi(tokens[2]));

			//Sending the student object to the vector studentList
			studentList.push_back(student);
		}

		file.close();
	}

	else
	{
		cout << "Unable to open file";
	}

	//Size of studentList vector
	int n = studentList.size();

	//Creating a list of grades
	for (int i = 0; i < n; ++i)
	{
		Student s = studentList[i];
		grades.push_back(s.getGrade());
		total += s.getGrade();
	}

	//Calculating the average of the student grades
	avg = total / n;

	//Sorting the list of grades from highest to lowest
	sort(grades.begin(), grades.end(), greater<int>());

	vector <int> check;

	//Comparing the grade vector with the studentList grades to fill the sortedList
	for (int j = 0; j < n; ++j)
	{
		for (int i = 0; i < n; ++i)
		{
			Student s = studentList[i];
			if (grades[j] == s.getGrade() && !(find(check.begin(), check.end(), i) != check.end()))
			{
				check.push_back(i);
				sortedList.push_back(s);
			}
		}
	}

	//Swapping the sortedList with the studentList
	studentList.swap(sortedList);

	//Printing the student name, last name, and grade in decending order
	for (int i = 0; i < n; ++i)
	{
		Student s = studentList[i];
		cout << s.getName() << " " << s.getLastName() << ": " << s.getGrade() << endl;
	}

	//Printing the average of the grades
	cout << "\nAverage: " << avg << endl;
}
