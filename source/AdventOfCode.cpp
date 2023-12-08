// AdventOfCode.cpp
#include "../header/AdventOfCode.hpp"
#include <iostream>

AdventOfCode::AdventOfCode(const std::string& relativePath) : relativePath(relativePath) {
  std::cout << "AdventOfCode constructor" << std::endl;
  initLinkedList();
  inputFile.open(relativePath);
  if (inputFile.is_open()) {
    std::string inputText;
    while (getline(inputFile, inputText)) {
      this->addLine(inputText);
    }
  } else {
    std::cerr << "Error: Unable to open file " << relativePath << std::endl;
  }
  inputFile.close();
}

void AdventOfCode::printList(bool withIndex) {
  std::string   output;
  linkedLines*  current = this->head;
  unsigned long i       = 0;
  while (current->next != nullptr) {
    withIndex ? output += std::to_string(i) + ": " + current->next->value + "\n" : output += current->next->value + "\n";
    current = current->next;
    i++;
  }
  std::cout << output;
}

void AdventOfCode::initLinkedList() {
  this->head       = new linkedLines;
  this->head->next = nullptr;
}

linkedLines* AdventOfCode::getHead() {
  return this->head;
}

linkedLines* AdventOfCode::addLine(const std::string& line) {
  linkedLines* current = this->head;
  while (current->next != nullptr) {
    current = current->next;
  }
  current->next        = new linkedLines;
  current->next->next  = nullptr;
  current->next->value = line;
  return current->next;
}

linkedLines* AdventOfCode::removeLine(linkedLines* line) {
  linkedLines* current = head;
  while (current->next != line) {
    current = current->next;
  }
  current->next = line->next;
  delete line;
  return current->next;
}

linkedLines* AdventOfCode::removeLastLine() {
  linkedLines* current = head;
  while (current->next->next != nullptr) {
    current = current->next;
  }
  delete current->next;
  current->next = nullptr;
  return current;
}

linkedLines* AdventOfCode::freeList() {
  linkedLines* current = head;
  while (current->next != nullptr) {
    current = removeLine(current->next);
  }
  delete head;
  return nullptr;
}

void AdventOfCode::run() {
  std::cout << "Missing Implementation of Day" << std::endl;
}
