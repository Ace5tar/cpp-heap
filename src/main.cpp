#include <iostream>
#include <cstring>
#include "HeapTree.h"

int main() {

  char* in = new char[80];
  HeapTree* heapPtr;
  char useFile;
  std::cout << "Would you like to import from file? (y/n) ";
  std::cin >> useFile;
  std::cin.ignore();

  if (useFile == 'y') {
    std::cout << "Input file name: ";
    std::cin.getline(in, 80);
    heapPtr = new HeapTree(in);
  } else {
    heapPtr = new HeapTree();
  }

  bool running = true;

  while(running) {

    std::cout << " > ";
    std::cin.getline(in, 80);

    // Quit program
    if(std::strcmp(in, "QUIT") == 0) {
      running = false;
    }
    // Add number command
    if(std::strcmp(in, "ADD") == 0) {\
      int num;
      std::cout << "Number to add: ";
      std::cin >> num;
      std::cin.ignore();
      heapPtr->insert(num);
    }
    // Print command
    if(std::strcmp(in, "PRINT") == 0) {
      std::cout << *heapPtr << std::endl;
    }
    // Remove command
    if(std::strcmp(in, "REMOVE") == 0) {
      heapPtr->remove();
    }
    // Clear command
    if(std::strcmp(in, "CLEAR") == 0) {
      heapPtr->clear();
    }

  }


  delete heapPtr;


  return 0;
}
