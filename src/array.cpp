
#include "../include/array.h"

void Array::swap(Student& s1, Student& s2) {
    Student temp = s1; // Create a temporary copy of s1
    s1 = s2;           // Assign s2 to s1
    s2 = temp;         // Assign the temporary copy to s2
}

void Array::addStudent(Student s)
{
    if(currentSize == arrSize){  // Before adding student to the end, make sure that the array isn't full
        arrSize*=2;  // If array is full, double the array size capacity (this is just standard practice and easy to understand)
        Student* newStudentArray = new Student[arrSize];  // Create a new student array with double the size of the last

        for(int i = 0; i< currentSize ; i++)  // Copy array contents to new array up to arrSize/2 (length of previous array)
            newStudentArray[i] = studentArray[i];
            
        delete[] studentArray;  // Delete the pointer to original student array
        studentArray = newStudentArray;  // Update pointer to student array with newStudentArray
    }
    studentArray[currentSize] = s;  // Use operator overload to set empty student object
    currentSize++;  // Increment currentSize indexing
}

void Array::bubbleSort(std::function<bool(const Student&, const Student&)> comparator) {
    for (int i = 0; i < currentSize - 1; ++i) {
        for (int j = 0; j < currentSize - i - 1; ++j) {
            if (comparator(studentArray[j], studentArray[j + 1])) {
                // Swap elements if they are out of order
                swap(studentArray[j], studentArray[j + 1]);
            }
        }
    }
}


