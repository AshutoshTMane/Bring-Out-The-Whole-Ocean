#ifndef STUDENT_H // These are called "include guards", they will avoid re-declarations of a class.
// For example, if you have an Animal class, and you want to make a child class called Dog, then you would inadvertently be calling the same class.
// So in a main.cpp file when you include the parent and child class, you would have a redefinition of the Animal class, so the ifndef checks if Animals is already declared.
// Stands for "If not defined"
#define STUDENT_H // This defines the class declaration if the above command is false

#include <string>

class Student
{
private: // The private keyword tells the computer that these variables or methods should not be available to access from outside this class
// This I initially thought was for safety, but this can actually be used to reduce code complexity
    int id_number;  // School-given identification number for each student, unique
    std::string name;  // Student's first and last name
    std::string academic_level;  // Student's "grade level" i.e. senior, junior, etc.
    int grade;  // Class grade that student has earned in numerical format, 0-100 in percentage

public:
    Student(int id_number, std::string name, std::string academic_level, int grade)  // Constructor for creating a student object
    {
         // These assignments use the 'this' pointer.
        // Each object in a class has a copy of the class variables, so we can use "this" to differentiate between the member variable and local variables in the constructor
        this->id_number = id_number;  
        this->name = name; 
        this->academic_level = academic_level;  
        this->grade = grade;  
    }

    // Class mutators, allow for other files to get or update data indirectly
    int get_id_number(){ return id_number; }
    std::string get_name(){ return name; }
    std::string get_academic_level(){ return academic_level; }
    int get_grade(){ return grade; }

    void set_id_number(int id_number) { this->id_number = id_number; }
    void set_name(std::string name) { this->name = name; }
    void set_academic_level(std::string academic_level) { this->academic_level = academic_level; }
    void set_grade(int grade) { this->grade = grade; }
};



#endif // Simply ends the "IF" block from above, in the ifndef command
// These are preprocessor directives, which is why they use the #
// Preprocessor directives process code before the actual compilation, in a general sense, they help make sure that code can compile easily.
// They help us in modularization for this reason, and can make things run more efficiently
// In terms of ifdef and ifndef, you would use ifndef because you just want to make sure that the class declaration doesn't already exist.