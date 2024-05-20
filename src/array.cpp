
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

void Array::bubbleSort(std::function<bool(const Student&, const Student&)> comparator) 
{
    for (int i = 0; i < currentSize - 1; ++i) {  // Acts as outer loop, outer index will iterate from 0 to the end of the loop
        for (int j = 0; j < currentSize - i - 1; ++j) {  // Inner loop, the inner loop must go from 0 to the size - i - 1. We have to subtract i because those indicies are considered "sorted" as the largest values
            if (comparator(studentArray[j], studentArray[j + 1])) {  // Use function library to help choose which comparator function we want to use 
                // Swap elements if they are out of order
                swap(studentArray[j], studentArray[j + 1]);
            }
        }
    }
}

void Array::insertionSort(std::function<bool(const Student&, const Student&)> comparator)
{  
    // The first element of the array is assumed to be sorted, so we start by setting the key to the second element in the array (index)
    for (int key = 1; key < currentSize; key++){ // What this look does is go through the array from the inital key value 1 to the very end of the array
        Student temp = studentArray[key];
        int j = key - 1;  // Set up a j value to act as a counter, it will go from the key index back down to index 0
        while (j >= 0 && (comparator(studentArray[j], temp))){  // We're looking for the point where the values are no longer smaller than the value at key
            studentArray[j+1] = studentArray[j];  // If the value is bigger, then shift the elements down. Here we are overwriting key because we stored the student in temp first
            --j; // Decrement j first, since doing it after would mean our loop would be moving 1 index behind
        }   
        studentArray[j + 1] = temp;  // Set the value at j+1 to the original value at key, because we decremented it one too many times using --j
    }
}

void Array::selectionSort(std::function<bool(const Student&, const Student&)> comparator)
{  
    // Select the first value to be the minimum
    for (int i = 0; i< currentSize-1; i++){  // This outer loop will iterate from the first element to the last
        int min_idx = i;  // Set the minimum to the current step's index, we are assuming that everything before this point is sorted
        for (int j = i+1; j < currentSize; j++){  // The inner loop handles looking for the minimum of the rest of the array
            if (comparator(studentArray[min_idx], studentArray[j]))  // If the min element is bigger than the current element, then save the new min index
                min_idx = j;
        }
        swap(studentArray[min_idx], studentArray[i]); // swap the newest min index
    }
}

int Array::partition(std::function<bool(const Student&, const Student&)> comparator, int low, int high)
{
    Student pivot = studentArray[high];
    int j = (low - 1);

    for (int i = low; i < high; i++ ){
        if(comparator(pivot, studentArray[i])){
            j++;
            swap(studentArray[j], studentArray[i]);
        }
    }
    swap(studentArray[j+1], studentArray[high]);
    return (j + 1);
}

void Array::quickSort(std::function<bool(const Student&, const Student&)> comparator, int low, int high)
{
    if (low < high){
        int pi = partition(comparator, low, high);
        quickSort(comparator, low, pi - 1);
        quickSort(comparator, pi + 1, high);
    }
}

void Array::merge(std::function<bool(const Student&, const Student&)> comparator, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays
    Student* leftArray = new Student[n1];
    Student* rightArray = new Student[n2];

    // Copy data to temporary arrays
    for (int i = 0; i < n1; ++i)
        leftArray[i] = studentArray[left + i];
    for (int i = 0; i < n2; ++i)
        rightArray[i] = studentArray[mid + 1 + i];

    // Merge the temporary arrays back into studentArray[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (comparator(leftArray[i], rightArray[j])) {
            studentArray[k] = leftArray[i];
            ++i;
        } else {
            studentArray[k] = rightArray[j];
            ++j;
        }
        ++k;
    }

    // Copy the remaining elements of leftArray, if any
    while (i < n1) {
        studentArray[k] = leftArray[i];
        ++i;
        ++k;
    }

    // Copy the remaining elements of rightArray, if any
    while (j < n2) {
        studentArray[k] = rightArray[j];
        ++j;
        ++k;
    }

    // Clean up
    delete[] leftArray;
    delete[] rightArray;
}

void Array::mergeSort(std::function<bool(const Student&, const Student&)> comparator, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Recursively sort the first and second halves
        mergeSort(comparator, left, mid);
        mergeSort(comparator, mid + 1, right);

        // Merge the sorted halves
        merge(comparator, left, mid, right);
    }
}
