#include <unistd.h>
#include <stdlib.h>

#define GRID_SIZE 4

int grid[GRID_SIZE][GRID_SIZE];
int up_clues[GRID_SIZE], down_clues[GRID_SIZE], left_clues[GRID_SIZE], right_clues[GRID_SIZE];

#define COLOR_RESET "\033[0m"
#define COLOR_GREEN "\033[32m"
#define COLOR_BLUE "\033[34m"
#define COLOR_RED "\033[31m"
#define COLOR_YELLOW "\033[33m"

int is_valid(int row, int col, int value);
int solve_puzzle(int row, int col);
void print_grid();
int parse_input(char *input);

void ft_putstr(char *str) {
	    while (*str) {
		            write(1, str++, 1);
			        }
}

void ft_putnbr_colored(int n) {
	    if (n == 1) {
		            ft_putstr(COLOR_YELLOW);
			            write(1, "1", 1);
				        } else if (n == 2) {
						        ft_putstr(COLOR_GREEN);
							        write(1, "2", 1);
								    } else if (n == 3) {
									            ft_putstr(COLOR_BLUE);
										            write(1, "3", 1);
											        } else if (n == 4) {
													        ft_putstr(COLOR_RED);
														        write(1, "4", 1);
															    }
	        ft_putstr(COLOR_RESET);
}

int main(int argc, char **argv) {
	    if (argc != 2 || parse_input(argv[1]) == 0) {
		            ft_putstr("Error\n");
			            return 1;
				        }

	        if (solve_puzzle(0, 0)) {
			        print_grid();
				    } else {
					            ft_putstr("Error\n");
						        }

		    return 0;
}

int parse_input(char *input) {
	    int values[16];
	        int i = 0;

		    while (*input && i < 16) {
			            if (*input >= '0' && *input <= '9') {
					                values[i] = *input - '0';
							            i++;
								            }
				            input++;
					        }

		        if (i != 16) return 0;

			    for (i = 0; i < 4; i++) {
				            up_clues[i] = values[i];
					            down_clues[i] = values[i + 4];
						            left_clues[i] = values[i + 8];
							            right_clues[i] = values[i + 12];
								        }

			        return 1;
}

int is_valid(int row, int col, int value) {
	    for (int i = 0; i < GRID_SIZE; i++) {
		            if (grid[row][i] == value || grid[i][col] == value) {
				                return 0;
						        }
			        }
	        return 1;
}

int solve_puzzle(int row, int col) {
	    if (row == GRID_SIZE) return 1;

	        int next_row = (col == GRID_SIZE - 1) ? row + 1 : row;
		    int next_col = (col == GRID_SIZE - 1) ? 0 : col + 1;

		        for (int value = 1; value <= 4; value++) {
				        if (is_valid(row, col, value)) {
						            grid[row][col] = value;
							                if (solve_puzzle(next_row, next_col)) return 1;
									            grid[row][col] = 0;
										            }
					    }

			    return 0;
}

void print_grid() {
	    for (int i = 0; i < GRID_SIZE; i++) {
		            for (int j = 0; j < GRID_SIZE; j++) {
				                ft_putnbr_colored(grid[i][j]);
						            if (j < GRID_SIZE - 1) {
								                    write(1, " ", 1);
										                }
							            }
			            write(1, "\n", 1);
				        }
}

