# Commands
#
#   make                         Compile and run hello_world.
#   make dir=<folder>            Compile and run <folder>/<folder>.cpp.
#   make dir=<folder> SRC=<file> Compile and run one specific source file.
#   make create=<name>           Create <name>/<name>.cpp from template.cpp.
#   make clean                   Delete every a.out binary.
#
# If a folder has a single .cpp file with another name, that file is used.
# If it has several, pass SRC=.

CXX      ?= c++
CXXFLAGS ?= -std=c++17 -O2 -Wall -Wextra
dir      ?= hello_world

.PHONY: run create-exercise clean

# `make create=<name>` sets a variable and does not name a target, so Make
# would otherwise run the first target. Switch the default only in that case.
ifeq ($(origin create),command line)
.DEFAULT_GOAL := create-exercise
endif

# Compile the folder's source to <folder>/a.out, then run it.
run:
	@set -e; \
	folder="$(dir)"; \
	if [ -n "$(SRC)" ]; then \
		src="$(SRC)"; \
	elif [ -f "$$folder/$$(basename "$$folder").cpp" ]; then \
		src="$$folder/$$(basename "$$folder").cpp"; \
	else \
		set -- "$$folder"/*.cpp; \
		if [ ! -f "$$1" ]; then \
			echo "No .cpp file in $$folder"; \
			exit 1; \
		fi; \
		if [ -n "$$2" ] && [ -f "$$2" ]; then \
			echo "Multiple .cpp files in $$folder. Pass SRC=<file>."; \
			exit 1; \
		fi; \
		src="$$1"; \
	fi; \
	$(CXX) $(CXXFLAGS) "$$src" -o "$$folder/a.out"; \
	"$$folder/a.out"

# Copy template.cpp into a new exercise folder.
create-exercise:
	@set -e; \
	name="$(create)"; \
	if [ -z "$$name" ]; then \
		echo "Usage: make create=<exercise_name>"; \
		exit 1; \
	fi; \
	if [ ! -f template.cpp ]; then \
		echo "Missing template.cpp"; \
		exit 1; \
	fi; \
	dest="$$name/$$(basename "$$name").cpp"; \
	if [ -e "$$dest" ]; then \
		echo "Already exists: $$dest"; \
		exit 1; \
	fi; \
	mkdir -p "$$name"; \
	cp template.cpp "$$dest"; \
	echo "Created $$dest"

clean:
	find . -type f -name a.out -delete
