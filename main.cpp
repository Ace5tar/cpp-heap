#include <iostream>
#include <cstring>
#include "HeapTree.h"

int main() {

  char* in = new char[80];
  
  HeapTree heap = HeapTree("numbers.txt");

  bool running = true;

  while(running) {

    std::cout << " > ";
    std::cin.getline(in, 80);

    if(std::strcmp(in, "QUIT") == 0) {
      running = false;
    }
    if(std::strcmp(in, "ADD") == 0) {\
      int num;
      std::cout << "Number to add: ";
      std::cin >> num;
      heap.insert(num);
    }
    if(std::strcmp(in, "PRINT") == 0) {
      std::cout << heap << std::endl;
    }
    if(std::strcmp(in, "REMOVE") == 0) {
      heap.remove();
    }
    if(std::strcmp(in, "CLEAR") == 0) {
      heap.clear();
    }

  }




  return 0;
}
