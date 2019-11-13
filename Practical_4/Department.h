/*
 * Department.h
 */

#ifndef DEPARTMENT_H_
#define DEPARTMENT_H_

#include <iostream>
#include "Student.h"

class Department {
public:
	Department();
	~Department();

	Department(const Department& other);
	Department(Department&& other);
	Department& operator=(const Department& other);
	Department& operator=(Department&& other);

	// add student to this department
	void addStudent(const string& name, int id);

	// return number of students in this department
	int numOfStudents() const;

	// returns i-th student added to this department.
	// The memory is still owned by this class - caller should not delete after use!
	Student* getStudent(int i) const;

	// print all students
	void print() const;

private:
	Student** students_;
	// for some reason, we store the students as an array of student pointers.
	// The memory pointed to by each such pointer is managed by this class internally.
	// Thus when a student is added you need to "new" a student and store the resulting pointer in this array
	int capacity_; // size of the above array
	int size_; // current number of students
};

const unsigned int INITIALCAPACITY = 10;
const unsigned int MULTIPLIER = 2;

#endif /* DEPARTMENT_H_ */
