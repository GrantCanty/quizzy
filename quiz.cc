#include "quiz.h"
#include "quizquestion.h"


#include <iomanip>
#include <iostream>
#include <fstream>

void Quiz::showAllQuestions(std::ostream& outs) {
    for (int i = 0; i < questions.size(); i++) {
        //std::cout << questions[i].getQuestion() << std::endl;
        std::cout << "i: " << i << std::endl;
        questions[i].showQuestion(outs);
        questions[i].showAnswers(outs);
        //questions[i].
    }
}

void Quiz::setQuestions() {
    int choice;

    do {
        choice = getMenu();
        switch(choice) {
            case 1: // true/false
                questions.push_back(QuizQuestion(1));
                questions[questions.size()-1].getMenu();
                questions[questions.size()-1].setAnswers(choice);
                break;
            case 2: // multiple choice
                questions.push_back(QuizQuestion(2));
                break;
            case 3: // matching
                questions.push_back(QuizQuestion(3));
                break;
        }
    } while (choice != 0);
}

int Quiz::getMenu() {
    int choice;

    std::cout << std::endl;
    std::cout << "1) Add True/False question" << std::endl;
    std::cout << "2) Add Mutliple Choice question" << std::endl;
    std::cout << "3) Add Matching question" << std::endl;
    std::cout << "0) Back" << std::endl;

    std::cin >> choice;
    if (std::cin.fail()) { //if cin fails, reset and give error message
        std::cout << "Error. Integer not entered.";
        std::cin.clear();
        std::cin.ignore(256, '\n');
        std::cin.ignore(100, '\n');
    }
    return choice; 
}