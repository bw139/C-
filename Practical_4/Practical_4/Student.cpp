#include "Student.h"
#include <iostream>

Student::Student(const string& name, int id) : name_(name), id_(id),
                                               numModules_(0)
{
//	for(int i = 0; i < NUMBEROFMODULES; ++i)
//		modules_[i] = 0;
}

Student::~Student() {}

// Copy constructor
Student::Student(const Student& other)
{
    id_ = other.id_;
    name_ = other.name_;
    numModules_ = other.numModules_;

    for (int i=0; i<numModules_;i++) modules_[i] = other.modules_[i];

    cout << "Copy constructor" << endl;
    // IMPLEMENT ME
    // Difference between constructor and assignment operator:
    // We don't return *this, we just construct the value.
}

// Move constructor
Student::Student(Student&& other)
{
    cout << "Move constructor" << endl;
        id_ = other.id_;
        name_ = other.name_;
        numModules_ = other.numModules_;
        for (int i=0; i<numModules_; i++) {
            modules_[i] = other.modules_[i];
            other.modules_[i] = 0;
        }
        other.id_ = 0;
        other.name_.clear();

    // IMPLEMENT ME
}

// Copy assignment operator
Student& Student::operator=(const Student& other) {
    id_ = other.id_;
    name_ = other.name_;
    numModules_ = other.numModules_;

    for (int i=0; i < numModules_; i++) modules_[i] = other.modules_[i];
    // IMPLEMENT ME
    cout << "Copy assignment" << endl;
    return *this;
}

// Move assignment operator
Student& Student::operator=(Student&& other) {

    if (this != &other) {

    id_ = 0;
    id_ = other.id_;

    name_ = other.name_;
    numModules_ = other.numModules_;
    other.id_ = 0;
    other.name_.clear();
    other.numModules_ = 0;

    for (int i=0; i<numModules_;i++) {
        modules_[i] = other.modules_[i];
        other.modules_[i] = 0;
    }
    cout << "Move assignment" << endl;

}

    // IMPLEMENT ME
    return *this;
}

void Student::setName(const string& name) {
    name_ = name;
}

string Student::getName() const {
    return name_;
}

int Student::getId() const {
    return id_;
}

void Student::addModule(int module) {
    if (numModules_ == NUMBEROFMODULES) return;
    modules_[numModules_++] = module;
}

void Student::print() const {
    std::cout << name_ << " " << id_ << std::endl;
    for(int i=0;i<numModules_;i++) std::cout << modules_[i] << " ";
    std::cout << std::endl;
}