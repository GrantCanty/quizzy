#include "answerdata.h"
#include "answer.h"
#include "quizquestion.h"

#include <iostream>
#include <fstream>
#include <vector>

QuizQuestion::QuizQuestion() {
    question = "";
}

QuizQuestion::QuizQuestion(int num) {
    question = "";
    //Answer *a;
    answers = Answer::Create(num);
    //std::cout << "int num: " << num << std::endl;
}

void QuizQuestion::getQuestion(std::ostream& outs) const {
    //return question;
    outs << question << std::endl;
}

void QuizQuestion::getAnswers(std::ostream& outs) {
    //return answers;
}

void QuizQuestion::setQuestion(std::string q) {
    question = q;
}

void QuizQuestion::setAnswers(int choice) {
        switch(choice) {
            case 1:
                TrueOrFalse *t;
                t = new TrueOrFalse();
                
                answers = t;
                answers->setAnswers();
                break;
            case 2:
                MultipleChoice *mc;
                mc = new MultipleChoice();
                
                answers = mc;
                mc->setAnswers();
                break;
            case 3:
                MatchAnswers *ma;
                ma = new MatchAnswers();
                
                answers = ma;
                ma->setAnswers();
                break;
        }
}

int QuizQuestion::setAnswersMenu() {
    int choice;

    std::cout << std::endl;
    std::cout << "1) Create True/False question" << std::endl;
    std::cout << "2) Create Mutliple Choice question" << std::endl;
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

void QuizQuestion::getMenu() {
    std::string q;
    
    std::cout << "Enter question" << std::endl;
    
    std::cin.ignore(100, '\n');
    std::getline(std::cin, q);
    question = q;

}