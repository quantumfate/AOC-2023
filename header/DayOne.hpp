// DayOne.hpp
#ifndef DAYONE_HPP
#define DAYONE_HPP

#include "../header/AdventOfCode.hpp"
#include <fstream>
using std::ifstream;
#include <iostream>

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

private:
  /**
   * @brief Retrieves the cipher from a line.
   * @param line
   * @return int cipher
   */
  int retrieveCipher(const std::string& line);
};

#endif // DAYONE_HPP
