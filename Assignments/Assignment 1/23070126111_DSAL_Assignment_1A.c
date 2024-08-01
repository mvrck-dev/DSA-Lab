// 1A. Problem: Find the smallest positive integer missing from an unsorted array of integers. 
// Description: You are given an array of integers, which may contain both positive and negative numbers.
// However, the array does not contain any duplicate elements. 
// Your task is to write a C program to find the smallest positive integer that is missing from the array.

// Write a function int findMissingInteger(int arr[], int size) that takes the following parameters:

//  arr: An array of integers.
//  size: The size of the array.
// The function should return the smallest positive integer that is missing from the array. 
// If no positive integer is missing, the function should return the next positive integer 
// after the maximum element in the array.

#include <stdio.h>

int findMissingInteger(int arr[], int size) {  
    int i, j;
    int max = 0;
    
    // Iterating to find the maximum element in the array
    for (i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    
    // Creating a boolean array to check the presence of elements
    int present[max + 1];
    
    // Initializing the boolean array with zeros
    for (i = 0; i <= max; i++) {
        present[i] = 0;
    }
    
    // Marking the presence of elements in the array, for efficient searching and checking that we account for duplicates
    for (i = 0; i < size; i++) {
        if (arr[i] > 0) {
            present[arr[i]] = 1;
        }
    }
    
    // Finding the smallest +ve integer missing from the array
    for (j = 1; j <= max + 1; j++) {
        if (present[j] == 0) {
            return j;
        }
    }
    
    // If no +ve integer is missing, return the next +ve int after the max element
    return max + 1;
}

int main() {
    int arr[] = {93, 2321, -234, -232};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    int missingInteger = findMissingInteger(arr, size);
    printf("The smallest positive integer missing from the array is: %d\n", missingInteger);
    
    return 0;
}

// Algorithm

// 1. Finding the maximum element in the array.
// 2. Creatimg a boolean array to mark the presence of elements.
// 3. Marking the presence of elements in the array.
// 4. Find the smallest positive integer missing from the array.
// 5. If no positive integer is missing, return the next positive integer after the maximum element.

// Complexity Analysis

// The time complexity of this approach is O(n), where n is the size of the array.
// The space complexity of this approach is O(max), where max is the maximum element in the array.

// Test Case 1:

// Input: arr = {93, 2321, -234, -232}
// Output: The smallest positive integer missing from the array is: -234