#include <iostream>

#ifndef HEAP_H
#define HEAP_H

enum treeSide {LEFT, RIGHT};

class HeapTree {
  private:
    // Internal array of ints
    int* intArray;

    // Length of the array, currently 100
    int size;

    // Construct the array 
    void ConstructArray();

    // Swap a and b in memory
    void Swap(int& a, int& b);

    // Recursive function that sorts the tree from the bottom up
    void RecursiveSortUp(int currentIndex);

    // Recursive function that sorts the tree from the top down
    void RecursiveSortDown(int currentIndex);

    // Function to return the first unused index
    int GetNextIndex();

    // Function to return the last usec index
    int GetLastIndex();

    // Helper function to get parent index from child index
    int ParentIndex(int childIndex) const ;
    
    // Helper function to get child index from parent index
    int ChildIndex(int parentIndex, treeSide side) const ;

    // Recursive print function to print the list as a tree
    std::ostream& RecursivePrint(std::ostream& os, int currentIndex, int depth) const ;

  public:

    // Default constructor 
    HeapTree();

    // Constructor for a list of numbers
    HeapTree(int* in_intArray, int bufferSize);

    // Constructor for a file
    HeapTree(char* fileName);
    
    // Destructor
    ~HeapTree();

    // Insert a number into the heaptree
    void insert(int num);

    // Remove the first member from the heaptree
    int remove();

    // Remove all members from the heaptree
    void clear();

    // Overload << operator for easier printing
    friend std::ostream& operator<<(std::ostream& os, const HeapTree& heapTree);


};

#endif
