#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>
#include <algorithm>

void print_field(std::vector<std::vector<int>> &field, bool first = false) {
    std::string field_string = "";
    std::string horizontal_line = "-------------------------";
    for (int i = 0; i < field.size(); i++) {
        if (i % 3 == 0) {
            field_string += horizontal_line + "\n";
        }
        for (int j = 0; j < field[i].size(); j++) {
            if (j % 3 == 0) {
                field_string += "| ";
            }
            field_string += std::to_string(field[i][j]) + " ";
        }
        field_string += "|\n";
    }
    field_string += horizontal_line + "\n";
    if (!first) {
        std::cout << "\033[13A";
    }
    std::cout << "\r" << field_string << std::flush;
}

bool is_valid(std::vector<std::vector<int>> &field, int row, int col, int num) {
    for (int i = 0; i < field[row].size(); i++) {
        if (field[row][i] == num) {
            return false;
        }
    }
    for (int i = 0; i < field.size(); i++) {
        if (field[i][col] == num) {
            return false;
        }
    }

    int startRow = row - (row % 3);
    int startCol = col - (col % 3);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (field[i + startRow][j + startCol] == num)
                return false;
            
    return true;
}

bool solve_sudoku(std::vector<std::vector<int>> &field) {
    for (int i = 0; i < field.size(); i++) {
        for (int j = 0; j < field[i].size(); j++) {
            if (field[i][j] == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (is_valid(field, i, j, num)) {
                        field[i][j] = num;
                        print_field(field, false);
                        std::this_thread::sleep_for(std::chrono::milliseconds(2));
                        if (solve_sudoku(field)) {
                            return true;
                        }
                        field[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main() {

    std::vector<std::vector<int>> field = {  
        { 5, 3, 0, 0, 7, 0, 0, 0, 0 },
        { 6, 0, 0, 1, 9, 5, 0, 0, 0 },
        { 0, 9, 8, 0, 0, 0, 0, 6, 0 },
        { 8, 0, 0, 0, 6, 0, 0, 0, 3 },
        { 4, 0, 0, 8, 0, 3, 0, 0, 1 },
        { 7, 0, 0, 0, 2, 0, 0, 0, 6 },
        { 0, 6, 0, 0, 0, 0, 2, 8, 0 },
        { 0, 0, 0, 4, 1, 9, 0, 0, 5 },
        { 0, 0, 0, 0, 8, 0, 0, 7, 9 }
    };

    print_field(field, true);
    solve_sudoku(field);
    return 0;
}