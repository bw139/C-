/*
 * Department.cpp
 */

#include "Department.h"

Department::Department() : students_(new Student*[INITIALCAPACITY]),
	capacity_(INITIALCAPACITY), size_(0)
{}

Department::~Department() {
	for(int i = 0; i < size_; ++i)
		delete students_[i];
	delete [] students_;
}

// Copy constructor
Department::Department(const Department& other)
{
    cout << "copy constructor" << endl;
    capacity_ = other.capacity_;
    size_ = other.size_;
    // Pointer of pointers
    students_ = new Student*[capacity_];
    for (int i=0; i<capacity_; i++) {
        // This utilises the copy assignment operator
        // Should we not use the pointer *students[i]
        students_[i] = other.students_[i];
    }
	// IMPLEMENT ME
}

// Move constructor
Department::Department(Department&& other)
{
    cout << "move constructor" << endl;
    this->size_ = other.size_;
    this->capacity_ = other.capacity_;
    students_ = new Student*[capacity_];

    for (int i=0; i<capacity_; i++) {
        students_[i] = other.students_[i];
        // We don't want to have pointers to invalid memory so point to nullptr
        other.students_[i] = nullptr;
    }
    delete [] other.students_;
    other.students_ = nullptr;
    other.capacity_ = 0;
    other.size_ = 0;

	// IMPLEMENT ME
}


// Copy assignment operator
Department& Department::operator=(const Department& other)
{
    cout << "copy assignment" << endl;
    capacity_ = other.capacity_;
    size_ = other.size_;
    // Pointer of pointers
    students_ = new Student*[capacity_];
    for (int i=0; i<capacity_; i++) {
        // This utilises the copy assignment operator
        // Should we not use the pointer *students[i]
        students_[i] = other.students_[i];
    }
	return *this;
}

// Move assignment operator
Department& Department::operator=(Department&& other)
{

    cout << "move assignment" << endl;
    this->size_ = other.size_;
    this->capacity_ = other.capacity_;
    students_ = new Student*[capacity_];

    for (int i=0; i<capacity_; i++) {
        students_[i] = other.students_[i];
        // We don't want to have pointers to invalid memory so point to nullptr
        other.students_[i] = nullptr;
    }
    delete [] other.students_;
    other.students_ = nullptr;
    other.capacity_ = 0;
    other.size_ = 0;
	// IMPLEMENT ME
	return *this;
}

void Department::addStudent(const string& name, int id)
{
	Student* s = new Student(name,id);

	if(size_ == capacity_) {

		Student** temp = new Student* [MULTIPLIER * capacity_];
		for(int i = 0; i < size_; ++i)
			temp[i] = students_[i];

		delete [] students_;
		students_ = temp;
		capacity_ = MULTIPLIER * capacity_;
	}

	students_[size_] = s;
	size_++;

}

int Department::numOfStudents() const
{
	return size_;
}

Student* Department::getStudent(int i) const
{
	if (i < size_) return students_[i];
	else return nullptr;
}

void Department::print() const
{
	std::cout << "The students are:" << std::endl;
	for(int i = 0; i < size_; ++i)
		std::cout << i+1 << ") " << students_[i]->getName() << std::endl;
}
