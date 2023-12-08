CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra
SRCDIR = source
INCDIR = header
OBJDIR = obj
BINDIR = bin

# List your header and source files here
HEADERS = $(wildcard $(INCDIR)/*.hpp)
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Output executable name
EXECUTABLE = aoc

all: $(BINDIR)/$(EXECUTABLE)

$(BINDIR)/$(EXECUTABLE): $(OBJECTS)
	@mkdir -p $(BINDIR)
	$(CXX) $(CXXFLAGS) $^ -o $@

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.cpp $(HEADERS)
	@mkdir -p $(OBJDIR)
	$(CXX) $(CXXFLAGS) -I$(INCDIR) -c $< -o $@

run:
	@cd $(BINDIR) && ./$(EXECUTABLE) $(DAY)

clean:
	@rm -rf $(OBJDIR) $(BINDIR)

.PHONY: all clean

