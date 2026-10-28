#pragma once
#include <cstddef>
#include <vector>
#include <utility>
#include <memory>
#include "cell.h"
#include <stdexcept>
#include <chrono>

/* A fixed-size 2D grid of cells, stored row by row in one vector. */
class Grid {
public:
  Grid(int rows, int columns);

  [[nodiscard]] int getRowCount() const;

  [[nodiscard]] int getColumnCount() const;

  [[nodiscard]] std::vector<int>  getGridVector() const;

  [[nodiscard]] int getCell(int row, int column) const;

  [[nodiscard]] int getLiveNeighborCount(int row, int column) const;

  void setCell(int row, int column, int state);

  std::vector<int> generateStep();

private:
  /* Converts (row, column) to a position in cells, throwing if out of bounds.  */
  [[nodiscard]] bool isInBounds(int row, int column) const;

  [[nodiscard]] int index(int row, int column) const;

  int rows;
  int columns;
  std::vector<int> cells;
  std::vector<int> nextCells;
};
