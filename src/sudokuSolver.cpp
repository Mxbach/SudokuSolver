#include <iostream>
#include <vector>
#include <string>
#include <chrono>
#include <thread>

void print_field(std::vector<std::vector<int>> field, bool first = false) {
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

    for (int k = 0; k < 5; k++) {
        if (k == 0) {
            print_field(field, true);
        } else {
            print_field(field);
        }
        for (int i = 0; i < field.size(); i++) {
            for (int j = 0; j < field[i].size(); j++) {
                if (field[i][j] < 9) {
                    field[i][j] += 1;
                }
            }
            
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    }
    std::cout << std::endl; // Final newline when done
    return 0;
}