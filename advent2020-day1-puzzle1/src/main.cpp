//include classes and headers
#include "../inc/common.hpp"

int checkData(std::vector<int>&);
void errorExit(std::ifstream&, std::string);

int main() {
    //std::cout << "Hello" << std::endl;

    // Initialize variables.
    std::vector<int> input{};

    int tmp1;

    // Set up file input.
    std::ifstream inFile{"input"};

    // Check for file.
    if(!inFile) {
        // Error message, close file and exit program.
        errorExit(inFile, "Error: No File Found.");
    }

    // Get file input.
    while(!inFile.eof()) {
        inFile >> tmp1;
        input.push_back(tmp1);
    }

    // Check for match.
    if(checkData(input) == -1) {
        // Error message, close file and exit program.
        errorExit(inFile, "Error: No Number Combination Found.");
    }

    std::cout << checkData(input) << std::endl;

    // Close file and exit program.
    inFile.close();
    return 0;
}

void errorExit(std::ifstream& inFile, std::string error) {
    // Error message, close file and exit program.
    std::cerr << error << std::endl;
    inFile.close();
    exit(-1);
}

int checkData(std::vector<int>& input) {
    // Check all combinations of numbers that equal 2020.
    for(int i{0}; i < input.size(); i++) {
        for(int j{0}; j < input.size(); j++) {
            if(input[i] + input[j] == 2020) {
                // Print results.
                //std::cout << input[i] << " + " << input[j] << " = " << input[i] + input[j] << std::endl;
                //std::cout << input[i] << " * " << input[j] << " = " << input[i] * input[j] << std::endl;

                // Break the loop.
                return input[i] * input[j];
            }
        }
    }

    return -1;

    // Attempt at recursion. Unfinished and unnecessary
    /*
    int checkData(std::vector<int>& input, int iter1, int iter2);

    for(int i{0}; i < input.size(); i++) {
        if(iter2 == 1) {
            if(input[i] + input[j] == 2020) {
                std::cout << input[i] << " + " << input[iter1] << " = " << input[i] + input[iter1] << std::endl;
                std::cout << input[i] << " * " << input[iter1] << " = " << input[i] * input[iter1] << std::endl;

                return input[i] * input[iter1];
            }
        } else {
            checkData(input, i, 1);
        }
    }

    return 0;
    */
}
