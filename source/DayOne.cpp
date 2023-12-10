#include "../header/DayOne.hpp"

DayOne::DayOne() : AdventOfCode("../resources/day1.txt") {
  std::cout << "Day One Input File loaded." << std::endl;
}

int DayOne::retrieveCipher(const std::string& line) {
  int  first         = 0;
  int  second        = 0;
  int* firstPointer  = nullptr;
  int* secondPointer = &second;

  for (int i = 0; i < (int)line.length(); ++i) {
    int code = static_cast<int>(line[i]);
    if (code >= ZERO_ASCII && code <= NINE_ASCII) {
      second = code;
      if (firstPointer == nullptr) {
        first        = code;
        firstPointer = &first;
      }
    }
  }
  if (first == 0 && second == 0) {
    return 0;
  }
  return &firstPointer == &secondPointer ? first - ZERO_ASCII : (first - ZERO_ASCII) * 10 + (second - ZERO_ASCII);
}

void DayOne::run() {
  int          sum     = 0;
  linkedLines* current = this->getHead();

  while (current->next != nullptr) {
    sum += this->retrieveCipher(current->next->value);
    current = current->next;
  }

  printf("Sum of cipher %d", sum);
}
