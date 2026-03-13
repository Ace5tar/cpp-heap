#include <iostream>
#include <fstream>
#include "HeapTree.h"


void HeapTree::ConstructArray() {
  size = 100;
  intArray = new int[size]{};
}

HeapTree::HeapTree() {
  ConstructArray();
}

HeapTree::HeapTree(int* in_intArray, int bufferSize) {
  ConstructArray();
  for (int i = 0; i < bufferSize; ++i) {
    insert(in_intArray[i]);
  }
}

HeapTree::HeapTree(const char* fileName) {
  ConstructArray();
  std::ifstream numbersFile(fileName);
  int curNumber = 0;
  while (numbersFile >> curNumber) {
    insert(curNumber);
  }
  numbersFile.close();
}

HeapTree::~HeapTree(){
  delete[] intArray;
}

void HeapTree::Swap(int& a, int& b) {
  int aTemp = a;
  int bTemp = b;
  a = bTemp;
  b = aTemp;
}

int HeapTree::ParentIndex(int childIndex) const {
  return (childIndex - 1) / 2;
}

int HeapTree::ChildIndex(int parentIndex, treeSide side) const {
  if (side == LEFT) {
    return (2 * parentIndex) + 1;
  } else {
    return (2 * parentIndex) + 2;
  }
}

std::ostream& HeapTree::RecursivePrint(std::ostream& os, int currentIndex, int depth) const {

  if (intArray[currentIndex] == 0 || currentIndex > size - 1) { return os; }

  RecursivePrint(os, ChildIndex(currentIndex, LEFT), depth + 1);

  for (int i = 0; i < depth; ++i) {
    os << "    ";
  }

  os << intArray[currentIndex] << std::endl;

  RecursivePrint(os, ChildIndex(currentIndex, RIGHT), depth + 1);

  return os;

}

std::ostream& operator<<(std::ostream& os, const HeapTree& heapTree) {
  heapTree.RecursivePrint(os, 0, 0);
  return os;
}

int HeapTree::GetNextIndex() {
  for (int i = 0; i < size; ++i) {
    if (intArray[i] == 0) { return i; }
  }

  return -1;
}

int HeapTree::GetLastIndex() {
  int lastIndex = 0;
  for (int i = 0; i < size; ++i) {
    if (intArray[i] != 0) { lastIndex = i; }
  }

  return lastIndex;
}

void HeapTree::RecursiveSortUp(int currentIndex) {

  if  (intArray[ParentIndex(currentIndex)] > intArray[currentIndex]) {
    return;
  }

  if (currentIndex == 0) {
    return;
  }

  Swap(intArray[ParentIndex(currentIndex)], intArray[currentIndex]);
  RecursiveSortUp(ParentIndex(currentIndex));

}

void HeapTree::RecursiveSortDown(int currentIndex) {

  int& currentValue = intArray[currentIndex];

  int leftChildIndex = ChildIndex(currentIndex, LEFT);
  int& leftChild = intArray[leftChildIndex];

  int rightChildIndex = ChildIndex(currentIndex, RIGHT);
  int& rightChild = intArray[rightChildIndex];

  if (leftChild <= currentValue && rightChild <= currentValue) {
    return;
  }


  if (leftChild > rightChild) {
    Swap(leftChild, currentValue);
    RecursiveSortDown(leftChildIndex);
  } else {
    Swap(rightChild, currentValue);
    RecursiveSortDown(rightChildIndex);
  }
}

void HeapTree::insert(int num) {
  int index = GetNextIndex();

  intArray[index] = num;

  RecursiveSortUp(index);
}

int HeapTree::remove() {
  int removedValue = intArray[0];

  if (removedValue == 0) {return 0;}

  intArray[0] = 0;

  Swap(intArray[0], intArray[GetLastIndex()]);
  
  RecursiveSortDown(0);

  std::cout << removedValue << std::endl;

  return removedValue;
}

void HeapTree::clear() {
  while(intArray[0] != 0) {
    remove();
  }
}
