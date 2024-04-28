#include "utils.h"


int main() {
    int i, j, k, l;  // Used only in iterations
    int iteration_no = 0;
    initialize();

    // Input receiving
    int input;
    for(i = 0; i < 9; i++)
    for(j = 0; j < 9; j++) {
        scanf("%d", &input);
        if(input != 0) {
            for(k = 0; k < 9; k++)
                grid[i][j].possible[k] = 0;
            grid[i][j].possible[input-1] = 1;
            grid[i][j].number = input;
            grid[i][j].set_iteration = iteration_no;
        }
    }

    // For each number in input, make sure every cell in the same row, column or 3x3 box
    // can't have the same value. If there's only one possible number that a given cell can be
    // (solved cell), change its value and repeat the process. Otherwise, a solution won't
    // be found by this algorithm, or it doesn't exist at all, terminating the program.

    int grid_changed = 1; // Checks if any cell is solved
    printf("\nStarting point:\n\n");
    printGrid();
    while(grid_changed == 1) {
        grid_changed = 0;
        // Evaluating possible numbers in each cell
        for(i = 0; i < 9; i++)
        for(j = 0; j < 9; j++)
            if(grid[i][j].number != 0) {  // If there isn't an assigned number to the cell
                int index = grid[i][j].number-1; // index regarding cell.possible array
                // Evaluate row/column
                for(k = 0; k < 9; k++) {
                    grid[k][j].possible[index] = 0;
                    grid[i][k].possible[index] = 0;
                }
                // Evaluate 3x3 box
                int center[2];
                center[0] = getCenterBoxX(i, j);
                center[1] = getCenterBoxY(i, j);
                for(k = -1; k <= 1; k++)
                    for(l = -1; l <= 1; l++)
                        grid[center[0]+k][center[1]+l].possible[index] = 0;
                grid[i][j].possible[index] = 1;
            }
        // Checks if a cell can be solved.
        // If so, it binds the cell to its respective number
        for(i = 0; i < 9; i++)
        for(j = 0; j < 9; j++) {
            int qty_possible_values = 0;
            int possible_number;
            for(k = 0; k < 9; k++)
                if(grid[i][j].possible[k] == 1) {
                    possible_number = k+1;
                    qty_possible_values++;
                }
            if(qty_possible_values == 1) {
                grid[i][j].number = possible_number;
                if(grid[i][j].set_iteration == -1) {
                    // This cell was solved in <<this>> iteration
                    grid[i][j].set_iteration = iteration_no;
                    grid_changed = 1;
                }
            }
        }
        if(grid_changed == 1) {
            iteration_no++;
            printf("\nIteration No. %d:\n\n", iteration_no);
            printGrid();
        }
    }
    printf("\nFinished in %d iterations!\n", iteration_no);
    return 0;
}
