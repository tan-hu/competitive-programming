# Compile and run the program in any folder.
#
#   make
#   make DIR=hello_world
#   make DIR=hello_world SRC=hello_world/hello_world.cpp
#
# Looks for <folder>/<folder>.cpp, or the only .cpp in that folder.
# The binary is <folder>/a.out (gitignored).

CXX      ?= c++
CXXFLAGS ?= -std=c++17 -O2 -Wall -Wextra
DIR      ?= hello_world

.PHONY: run clean

run:
	@dir="$(DIR)"; \
	if [ -n "$(SRC)" ]; then src="$(SRC)"; \
	elif [ -f "$$dir/$$(basename "$$dir").cpp" ]; then src="$$dir/$$(basename "$$dir").cpp"; \
	else \
	  set -- "$$dir"/*.cpp; \
	  if [ ! -f "$$1" ]; then echo "No .cpp file in $$dir"; exit 1; fi; \
	  if [ -n "$$2" ] && [ -f "$$2" ]; then echo "Multiple .cpp files in $$dir; set SRC=<file>"; exit 1; fi; \
	  src="$$1"; \
	fi; \
	$(CXX) $(CXXFLAGS) "$$src" -o "$$dir/a.out" && "$$dir/a.out"

clean:
	find . -type f -name a.out -delete
