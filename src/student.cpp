#include <iostream>
#include "../include/student.h"



std::ostream& operator<< (std::ostream& ofs, const Student& s)
{
    std::cout << "Student ID: " << s.id_number << ", Student Name: " << s.name << ", Student Academic Year: " << s.academic_level << ", Student Grade: " << s.grade << std::endl;
    return ofs;
}

std::istream& operator>> (std::istream& ifs, Student& s)
{

    std::cout << "Enter student ID: ";
    ifs >> s.id_number;

    std::cout << "Enter student name: ";
    ifs >> s.name;

    std::cout << "Enter student academic year: ";
    ifs >> s.academic_level;

    std::cout << "Enter student grade: ";
    ifs >> s.grade;

    return ifs;
}

Student Student::operator= (const Student& s)
{
    this->id_number = s.id_number;
    this->name = s.name;
    this->academic_level = s.academic_level;
    this->grade = s.grade;
    return *this;    
}


// Comparator function for sorting by ID
bool Student::compareByID(const Student& s1, const Student& s2) {
    return s1.id_number > s2.id_number; // Access private member directly
}
// Comparator function for sorting by grade
bool Student::compareByGrade(const Student& s1, const Student& s2) {
    return s1.grade > s2.grade;
}