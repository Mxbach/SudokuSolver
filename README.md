# Sudoku Vision Solver

A C++ Sudoku solver with OCR capabilities that reads puzzles from images, displays them in the terminal, and solves them with live in-place animation.

## Features

- 🎯 Real-time terminal display with in-place updates
- 🔢 9x9 grid representation and rendering
- 🎬 Animated solving visualization (coming soon)
- 📷 Image-based puzzle input via OCR (planned)

## Current Status

**Implemented:**
- Terminal rendering with in-place grid updates
- Basic grid data structure
- Animation demonstration

**Roadmap:**
- Sudoku solving algorithm
- Image processing and OCR integration
- Screenshot capture support

## Building
```bash
make build
```

## Usage
```bash
./bin/solver
```

## Requirements

- C++ compiler with C++11 support or later
- Make

## Project Structure
```
.
├── src/           # Source files
├── bin/           # Compiled binaries
└── README.md
```