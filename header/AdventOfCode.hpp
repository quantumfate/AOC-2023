// Advent of Code.hpp
#ifndef ADVENTOFCODE_HPP
#define ADVENTOFCODE_HPP

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

struct linkedLines {
  std::string  value;
  linkedLines* next;
};

class AdventOfCode
{
public:
  explicit AdventOfCode();
  explicit AdventOfCode(const std::string& relativePath);
  /**
     * Runs the current day's code or prints an error message if the day is not implemented
     * @brief run
     */
  virtual void run();
  virtual ~AdventOfCode() = default;

private:
  std::string   relativePath;
  std::ifstream inputFile;
  linkedLines*  head;

protected:
  /**
   * Prints the linked list
   * @brief printList
   * @param withIndex
   */
  void printList(bool withIndex = false);
  /**
   * Initializes the linked list
   * @brief initLinkedList
   */
  void initLinkedList();
  /**
   * Returns the head of the linked list
   * @brief getHead
   * @return linkedLines* head
   */
  linkedLines* getHead();
  /**
   * Adds a line to the linked list
   * @brief addLine
   * @param line
   * @return linkedLines* current
   */
  linkedLines* addLine(const std::string& line);
  /**
   * Removes a line from the linked list
   * @brief removeLine
   * @param line
   * @return linkedLines* current
   */
  linkedLines* removeLine(linkedLines* line);
  /**
   * Removes the last line from the linked list
   * @brief removeLastLine
   * @return linkedLines* current
   */
  linkedLines* removeLastLine();
  /**
   * Frees the linked list
   * @brief freeList
   * @return linkedLines* nullptr
   */
  linkedLines* freeList();
};

#endif // ADVENTOFCODE_HPP
