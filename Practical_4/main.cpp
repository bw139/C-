#include <iostream>
#include "Student.h"
#include "Department.h"

using std::cout;
using std::endl;

int main() {

	// Create a few students
//	Student s("John Smith", 123);
//	s.addModule(3105);
//	s.addModule(3002);
//	s.addModule(3099);
//	cout << "Student s:" << endl;
//	s.print();
//
//	Student t = s; // copy con
//	cout << "Student t, a copy of s:" << endl;
//	t.print();
//	cout << "Student s after being copied:" << endl;
//	s.print();
//
//	Student u = std::move(t); // move con
//	cout << "Student u, a move of t:" << endl;
//	u.print();
//	cout << "Student t after being moved:" << endl;
//	t.print();
//
//	Student v("Joe Biggs", 456);
//	v.addModule(7105);
//	cout << "Student v:" << endl;
//	v.print();
//	v = u; // copy asg
//	cout << "Student v after copying from u:" << endl;
//	v.print();
//	cout << "Student u after being copied:" << endl;
//	u.print();
//	///
//	Student w("blah", 789);
//	w = std::move(v); // move asg
//	cout << "Student w, a move of v:" << endl;
//	w.print();
//	cout << "Student v after being moved:" << endl;
//	v.print();

	// Create a department and add a student to it
	Department informatics;
	informatics.addStudent("John Smith", 123);
	informatics.addStudent("Joe Biggs", 456);
	informatics.getStudent(0)->addModule(3105);
	informatics.getStudent(0)->addModule(3002);
	informatics.getStudent(0)->addModule(3099);
	informatics.getStudent(1)->addModule(7105);
	cout << "Informatics students" << endl;
	informatics.print();
	for(int i=0;i<informatics.numOfStudents();++i)
		informatics.getStudent(i)->print();

	// Copy constructor
    Department another_department = informatics;
    cout << "Another_department after copy constructor" << endl;
    for(int i=0;i<another_department.numOfStudents();++i) {
        another_department.getStudent(i)->print();
        }

    Department copy_assigned_department;
    copy_assigned_department = informatics;
    cout << "copy_assigned_department after copy assignment" << endl;
    for(int i=0;i<copy_assigned_department.numOfStudents();++i) {
        copy_assigned_department.getStudent(i)->print();
    }

    cout << "Move_constructed_department after move constructor" << endl;
    Department move_constructed_department = std::move(another_department);
    for(int i=0;i<move_constructed_department.numOfStudents();++i) {
        move_constructed_department.getStudent(i)->print();
    }

    cout << "Another_department after move constructor used (should print blanks)" << endl;
    for(int i=0;i<another_department.numOfStudents();++i) {
        another_department.getStudent(i)->print();
    }

    cout << "Moved_assigned_department after move assignment" << endl;
    Department move_assigned_department;
    move_assigned_department = std::move(move_constructed_department);
    for(int i=0;i<move_assigned_department.numOfStudents();++i) {
        move_assigned_department.getStudent(i)->print();
    }

    cout << "Move_constructed_department after before move assignment of it (should print blanks)" << endl;
    for(int i=0;i<move_constructed_department.numOfStudents();++i) {
        move_constructed_department.getStudent(i)->print();
    }


	/// TODO !!
	// try writing test code for Department similar to those for Students above

	return 0;
}

