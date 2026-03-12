#include <iostream>
#include <cstring>
#include "HeapTree.h"

int main() {

  HeapTree heap = HeapTree("numbers.txt");

  bool running = true;

  while(running) {

    char* in = new char[80];
    std::cout << " > ";
    std::cin.getline(in, 80);

    if(std::strcmp(in, "QUIT") == 0) {
      running = false;
    }
    if(std::strcmp(in, "ADD") == 0) {

    }
    if(std::strcmp(in, "PRINT") == 0) {
      std::cout << heap << std::endl;
    }
  }




  return 0;
}
