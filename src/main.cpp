// main.cpp
#include "../include/grid.h"

#include <iostream>
#include <thread>

void printGrid(const Grid& grid) {
  for (int row = 0; row < grid.getRowCount(); ++row) {
    for (int column = 0; column < grid.getColumnCount(); ++column) {
      std::cout << (grid.getCell(row, column) == static_cast<int>(Cell::ALIVE) ? '#' : '.');
    }
    std::cout << '\n';
  }
}

int main() {
  using namespace std::chrono_literals;

  Grid grid(20, 40);

  // Glider
  const int alive = static_cast<int>(Cell::ALIVE);
  grid.setCell(1, 2, alive);
  grid.setCell(2, 3, alive);
  grid.setCell(3, 1, alive);
  grid.setCell(3, 2, alive);
  grid.setCell(3, 3, alive);

  for (int generation = 0; generation < 60; ++generation) {
    std::cout << "\x1b[2J\x1b[H";  // clear the terminal and move the cursor to the top
    std::cout << "Generation " << generation << "\n";
    printGrid(grid);
    grid.generateStep();
    std::this_thread::sleep_for(150ms);
  }
}
