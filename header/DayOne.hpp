// DayOne.hpp
#ifndef DAYONE_HPP
#define DAYONE_HPP

#include "../header/AdventOfCode.hpp"
#include <fstream>
#include <list>
using std::ifstream;
#include <iostream>

#define ZERO_ASCII 48
#define NINE_ASCII 57

/**
 * @brief The DayOne class
 * https://adventofcode.com/2023/day/1
 */
class DayOne : public AdventOfCode
{
public:
  DayOne();
  /**
   * @brief Calculates the sum of all ciphers in the input file.
   * @param inputFilePath
   */
  void run() override;

public:
  /**
   * @brief Retrieves the cipher from a line.
   * @param line
   * @return int cipher
   */
  int retrieveCipher(const std::string& line);
};

#endif // DAYONE_HPP
