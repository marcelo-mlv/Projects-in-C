#include <stdio.h>
typedef struct cell cell;

struct cell {
    int number;  // Represents the cell's number. If 0, then the cell can represent more than 1 value
    int set_iteration; // Keeps track of which iteration the cell's number was set
    int possible[9];
    // Boolean array
    // If possible[3] == 0, this cell can't be the number 4
    // If possible[5] == 1, this cell can be the number 6
    // If this array has only one value set to one, then a number can be assigned to the cell
};

cell grid[9][9];  // Grid used in the main file

/// Program initializing

void initialize() {
    int i, j, k;
    for(i = 0; i < 9; i++)
        for(j = 0; j < 9; j++) {
            grid[i][j].number = 0;
            for(k = 0; k < 9; k++)
                grid[i][j].possible[k] = 1; // Initially any cell can assume any number
            grid[i][j].set_iteration = -1;  // It marks that the cell hasn't had its value set yet
        }
}

/// Visuals

void printGrid() {
    int i, j;
    for(i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {
            int num = grid[i][j].number;
            if(num == 0)
                printf("  ");
            else printf(" %d", grid[i][j].number);
            if(j == 2 || j == 5)
                printf(" |");
        }
        printf("\n");
        if(i == 2 || i == 5)
            printf("-----------------------\n");
    }
}

///

int isCenter(int *coord) {
    // Checks whether a coordinate is one of the 3x3 box centers
    if((coord[0] == 1 || coord[0] == 4 || coord[0] == 7) && (coord[1] == 1 || coord[1] == 4 || coord[1] == 7))
        return 1;
    return 0;
}

int getCenterBoxX(int x, int y) {
    // Get the center cell X coordinate of the 3x3 box the cell (x, y) is in
    int ans[2];
    int i, j;
    for(i = -1; i <= 1; i++)
        for(j = -1; j <= 1; j++) {
            ans[0] = x+i;
            ans[1] = y+j;
            if(isCenter(ans))
                return ans[0];
        }
}

int getCenterBoxY(int x, int y) {
    // Get the center cell Y coordinate of the 3x3 box the cell (x, y) is in
    int ans[2];    int i, j;
    for(i = -1; i <= 1; i++)
        for(j = -1; j <= 1; j++) {
            ans[0] = x+i;
            ans[1] = y+j;
            if(isCenter(ans))
                return ans[1];
        }
}
