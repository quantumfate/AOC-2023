#include "./main.hpp"

int main(int argc, char** argv) {

  if (argc < 2 || argc > 3) {
    std::cout << "Usage: " << argv[0] << " <day_number> [optional_arguments]" << std::endl;
    return 1;
  }

  AdventOfCode* adventOfCode = nullptr;

  if (argc == 2) {
    if (std::string(argv[1]) == "1") {
      DayOne* dayOne = new DayOne();
      adventOfCode   = dayOne;
    } else {
      std::cout << "Invalid day number." << std::endl;
      return 1;
    }
  } else {
    std::cout << "Too many arguments." << std::endl;
    return 1;
  }

  adventOfCode->run();
  delete adventOfCode;

  return 0;
}
