CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
SRCDIR = source
INCDIR = header
OBJDIR = obj
BINDIR = bin

MAINDIR = main
TESTDIR = tests

# List your header and source files here
HEADERS = $(wildcard $(INCDIR)/*.hpp)
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

MAIN_HEADER = $(MAINDIR)/main.hpp
MAIN_SOURCE = $(MAINDIR)/main.cpp
MAIN_OBJECT = $(MAIN_SOURCE:$(MAINDIR)/%.cpp=$(OBJDIR)/%.o)

TEST_HEADER = $(TESTDIR)/test.hpp
TEST_SOURCE = $(TESTDIR)/test.cpp
TEST_OBJECT = $(TEST_SOURCE:$(TESTDIR)/%.cpp=$(OBJDIR)/%.o)

# Output executable names
MAIN_EXECUTABLE = aoc_main
TEST_EXECUTABLE = aoc_test

all: main test

main: $(BINDIR)/$(MAIN_EXECUTABLE)

test: $(BINDIR)/$(TEST_EXECUTABLE)

$(BINDIR)/$(MAIN_EXECUTABLE): $(OBJECTS) $(MAIN_OBJECT)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(BINDIR)/$(TEST_EXECUTABLE): $(OBJECTS) $(TEST_OBJECT)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp $(HEADERS)
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

$(MAIN_OBJECT): $(MAIN_SOURCE) $(MAIN_HEADER) $(HEADERS)
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

$(TEST_OBJECT): $(TEST_SOURCE) $(TEST_HEADER) $(HEADERS)
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

run_main:
	@cd $(BINDIR) && ./$(MAIN_EXECUTABLE)

run_test:
	@cd $(BINDIR) && ./$(TEST_EXECUTABLE)

clean:
	@rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all clean run_main run_test
