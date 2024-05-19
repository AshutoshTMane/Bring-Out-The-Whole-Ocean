#ifndef STUDENT_H // These are called "include guards", they will avoid re-declarations of a class.
// For example, if you have an Animal class, and you want to make a child class called Dog, then you would inadvertently be calling the same class.
// So in a main.cpp file when you include the parent and child class, you would have a redefinition of the Animal class, so the ifndef checks if Animals is already declared.
// Stands for "If not defined"
#define STUDENT_H // This defines the class declaration if the above command is false

#include <string>
#include <iostream>

class Student
{

friend std::ostream& operator<< (std::ostream& ofs, const Student& s);
friend std::istream& operator>> (std::istream& ifs, Student& s);

// These are the iostream operator overloading functions.
// We set these as friends to simplify how they access private members; they could also be class members if we need them to be
// We have to call the ostream and istream for printing purposes, and takes a student object as a parameter.
// We pass these using the addressing operator to ensure that we don't make edits to the values directly

private: // The private keyword tells the computer that these variables or methods should not be available to access from outside this class
// This I initially thought was for safety, but this can actually be used to reduce code complexity
    int id_number;  // School-given identification number for each student, unique
    std::string name;  // Student's first and last name
    std::string academic_level;  // Student's "grade level" i.e. senior, junior, etc.
    int grade;  // Class grade that student has earned in numerical format, 0-100 in percentage

public:

    Student() {}  // Default constructor
    // We can have multiple constructors with different names because of a type of function overloading

    Student(int id_number, std::string name, std::string academic_level, int grade)  // Constructor for creating a student object
    {
         // These assignments use the 'this' pointer.
        // Each object in a class has a copy of the class variables, so we can use "this" to differentiate between the member variable and local variables in the constructor
        this->id_number = id_number;  
        this->name = name; 
        this->academic_level = academic_level;  
        this->grade = grade;  
    }

    Student operator= (const Student& s);
    // The = operator overloading function, used to easy copy over data from one student object to another

    // Class mutators, allow for other files to get or update data indirectly
    int get_id_number(){ return id_number; }
    std::string get_name(){ return name; }
    std::string get_academic_level(){ return academic_level; }
    int get_grade(){ return grade; }

    void set_id_number(int id_number) { this->id_number = id_number; }
    void set_name(std::string name) { this->name = name; }
    void set_academic_level(std::string academic_level) { this->academic_level = academic_level; }
    void set_grade(int grade) { this->grade = grade; }

    void setStudent(int id_number, std::string name, std::string academic_level, int grade);
    // This function is to be used in the data structure classes for assigning a student object passed into a function to a default student object
};



#endif // Simply ends the "IF" block from above, in the ifndef command
// These are preprocessor directives, which is why they use the #
// Preprocessor directives process code before the actual compilation, in a general sense, they help make sure that code can compile easily.
// They help us in modularization for this reason, and can make things run more efficiently
// In terms of ifdef and ifndef, you would use ifndef because you just want to make sure that the class declaration doesn't already exist.