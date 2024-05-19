#ifndef ARRAY_H
#define ARRAY_H

#include "student.h"
#include <functional> // for std::function

class Array
{
private:
    Student* studentArray; // Array type setup
    int arrSize;  // The maximum number of values storable in the array
    int currentSize;  // The current size of the array, for indexing purposes
public:

    Array(int arrSize)
    {
        this->arrSize = arrSize;  // Initialize arrSize based on input
        this->currentSize = 0;  // Initialize current indexing to 0
        this->studentArray = new Student[arrSize];  // Create studentArray for this specific object
        // An interesting thing about this is that it requires a default constructor
        // That is because all of the space in the array is initialized at once, and without proper data, the code doesn't know how to fill the array
    }

    void swap(Student& s1, Student& s2);

    int findStudent_linear(const Student s);
    int findStudent_binary(const Student s);
    void addStudent(const Student s);
    void deleteStudent(Student s);

    void bubbleSort(std::function<bool(const Student&, const Student&)> comparator);
    void insertionSort();
    void selectionSort();
    void quickSort();
    void mergeSort();


    ~Array() {
        delete[] studentArray; // Deallocate the memory for the dynamic array
    }
};



// What is a dynamic array?
// A dynamic array is a one that resizes when we try to make an insertion and the capacity "arrSize" is full. 
// A fixed array and dynamic array can have equal timing for access (due to direct indexing), and insertion/deletion.
// Dynamic arrays can be more efficient in terms of memory, as there's little chance of having a large base of unused indices.
// Dynamic arrays have complexity to manage, but can be more efficient in that the resizing doesn't have to explicitly be managed by the programmer (me!)
// A commonly known point is that dynamic arrays can have sizes that are unknown at compile time, which is convenient when you have user inputs.

#endif