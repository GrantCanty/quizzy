//#include "question.h"
#include "quiz.h"

#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>

int menu() {
    int choice;

    std::cout << std::endl;
    std::cout << "Enter a number to choose the following options" << std::endl;
    std::cout << "1) Add questions" << std::endl;
    std::cout << "2) View all questions" << std::endl;
    std::cout << "3) Output all quiz question to a file" << std::endl;
    std::cout << "0) Quit" << std::endl;

    std::cin >> choice;
    if (std::cin.fail()) { //if cin fails, reset and give error message
                std::cout << "Error. Integer not entered.";
                std::cin.clear();
                std::cin.ignore(256, '\n');
                std::cin.ignore(100, '\n');
    }
    return choice;
}

int main() {
    int choice;

    std::ofstream ofs;

    Quiz quiz;
    
    do {
        choice = menu();
        switch(choice) {
            case 1:
                quiz.setQuestions();
                break;
            case 2:
                quiz.showAllQuestions(std::cout);
                break;
            case 3:
                quiz.outputAllQuestions(ofs);
        }
    } while(choice != 0);
    
    return 0;
}

