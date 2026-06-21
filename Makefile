CC      := gcc
CFLAGS  := -std=gnu11 -Wall -Wextra -O2
LDLIBS  := -lm

SRC_DIR := src
BIN_DIR := bin

SOURCES := $(wildcard $(SRC_DIR)/*.c)
TARGETS := $(patsubst $(SRC_DIR)/%.c,$(BIN_DIR)/%,$(SOURCES))

REPORT_DIR := report
REPORT_TEX := main.tex
REPORT_PDF := $(REPORT_DIR)/main.pdf

.PHONY: all clean run report report-clean docs docs-clean list help

## Build all C programs into bin/
all: $(TARGETS)

$(BIN_DIR)/%: $(SRC_DIR)/%.c | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $< $(LDLIBS)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

## Build and run a single task, e.g. `make run T=t05`
run: $(BIN_DIR)/$(T)
	@./$(BIN_DIR)/$(T)

## Compile the LaTeX report (requires a LaTeX distribution, e.g. TeX Live)
report:
	cd $(REPORT_DIR) && latexmk -pdf -interaction=nonstopmode $(REPORT_TEX)

## Remove LaTeX auxiliary/build files
report-clean:
	cd $(REPORT_DIR) && latexmk -C

## Generate Doxygen API documentation into docs/
docs:
	doxygen Doxyfile

## Remove generated Doxygen documentation
docs-clean:
	rm -rf docs

## List all available task names
list:
	@echo "Available tasks:"
	@for f in $(SOURCES); do basename $$f .c; done

## Remove compiled binaries
clean:
	rm -rf $(BIN_DIR)

help:
	@echo "Targets:"
	@echo "  make            - build all C programs into bin/"
	@echo "  make run T=t05  - build and run a single task (e.g. t05)"
	@echo "  make report     - compile the LaTeX report (report/main.pdf)"
	@echo "  make report-clean - clean LaTeX build artifacts"
	@echo "  make docs       - generate Doxygen API documentation (docs/)"
	@echo "  make docs-clean - remove generated documentation"
	@echo "  make list       - list all available task names"
	@echo "  make clean      - remove compiled binaries"
