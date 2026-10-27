#include <format>
#include <iostream>
#include <string>
#include <vector>

/* Cell state enum class */
enum class Cell : int { DEAD, ALIVE };

/* Grid Class where the grid logic lives */
class Grid {
private:
    /* User chooses grid height and grid width */
    int gridRows;
    int gridColumns;
    std::vector<int> gridVector;

public:
    /* Creates grid based off given height and width */
    explicit Grid(int gridRows, int gridColumns) {
        this->gridRows = gridRows;
        this->gridColumns = gridColumns;
        this->gridVector = std::vector<int>(gridRows * gridColumns, static_cast<int>(Cell::DEAD)
        );
    }

     [[nodiscard]]  int getGridRowCount() {
        return gridRows;
    }

     [[nodiscard]]  int getGridColumnCount() {
        return gridColumns;
    }

    [[nodiscard]] int getCellStatus(int rowChoice, int columnChoice) {
        return gridVector[rowChoice * gridColumns + columnChoice];
    }

    void setCellStatus(int rowChoice, int columnChoice, int status) {
        int index = rowChoice * gridColumns + columnChoice;
        if (gridVector[index] == status) {
            return;
        }
        gridVector[index] = status;
    }
};

int main() {
    Grid grid(5, 5);
    grid.setCellStatus(1, 2, static_cast<int>(Cell::ALIVE));
    std::cout << grid.getCellStatus(1, 2) << '\n';
    return 0;
}
