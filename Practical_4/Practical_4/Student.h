/*
 * Student.h
 *
 */

#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>
using namespace std;

const int NUMBEROFMODULES = 9;

class Student {
public:

	Student() = delete;
	Student(const string& name, int id);
	~Student();

	Student(const Student& other);
	Student(Student&& other);
	Student& operator=(const Student& other);
	Student& operator=(Student&& other);

	void setName(const string& name);
	string getName() const;

	int getId() const;

	void addModule(int module);
	void print() const;

private:

	string name_;
	int id_;
	int modules_[NUMBEROFMODULES];
	int numModules_;
};

#endif /* STUDENT_H_ */
