#include "../include/grid.h"

Grid::Grid(int rows, int columns)
  : rows(rows),
    columns(columns),
    cells(static_cast<int>(rows) * columns, static_cast<int>(Cell::DEAD)),
    nextCells(cells) {}

int Grid::getRowCount() const { return rows; }

int Grid::getColumnCount() const { return columns; }

std::vector<int> Grid::getGridVector() const { return cells; }

int Grid::getCell(int row, int column) const {
  return cells[index(row, column)];
}

void Grid::setCell(int row, int column, int state) {
  cells[index(row, column)] = state;
}

int Grid::getLiveNeighborCount(int row, int column) const {
  int count = 0;

  for (int directionR = -1; directionR <= 1; directionR++) {
    for (int directionC = -1; directionC <= 1; directionC++) {
      if (directionR == 0 && directionC == 0) {
        continue;
      }
      int neighbourRow = row + directionR;
      int neighbourColumn = column + directionC;

      if (isInBounds(neighbourRow, neighbourColumn) &&
        getCell(neighbourRow, neighbourColumn) == static_cast<int>(Cell::ALIVE)) {
        count++;
      }
    }
  }
  return count;
}
std::vector<int> Grid::generateStep() {
  for (int row = 0; row < getRowCount(); row++) {
    for (int column = 0; column < getColumnCount(); column++) {
      int cellLiveNeighborCount = getLiveNeighborCount(row, column);
      int currentCell = getCell(row, column);

      if (cellLiveNeighborCount < 2 && currentCell == static_cast<int>(Cell::ALIVE)) {
        this->nextCells[index(row, column)] = static_cast<int>(Cell::DEAD);
      } else if ((cellLiveNeighborCount == 2 || cellLiveNeighborCount == 3) &&
                 currentCell == static_cast<int>(Cell::ALIVE)) {
        this->nextCells[index(row, column)] = static_cast<int>(Cell::ALIVE);
      } else if (cellLiveNeighborCount > 3 && currentCell == static_cast<int>(Cell::ALIVE)) {
        this->nextCells[index(row, column)] = static_cast<int>(Cell::DEAD);
      } else if (cellLiveNeighborCount == 3 && currentCell == static_cast<int>(Cell::DEAD)) {
        this->nextCells[index(row, column)] = static_cast<int>(Cell::ALIVE);
      } else {
        this->nextCells[index(row, column)] = currentCell;
      }
    }
  }
  this->cells.swap(this->nextCells);
  return this->cells;
}


bool Grid::isInBounds(int row, int column) const {
  return row >= 0 && row < rows && column >= 0 && column < columns;
}

int Grid::index(int row, int column) const {
  if (!isInBounds(row, column)) {
    throw std::out_of_range("Grid: cell position out of range");
  }
  return static_cast<int>(row) * columns + column;
}
