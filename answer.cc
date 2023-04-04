#include "answer.h"
#include "answerdata.h"

#include <iostream>

Answer * Answer::Create(int num) {
    Answer *p;
    switch(num) {
        case 1:
            p = new TrueOrFalse();
            break;
        case 2:
            p = new MultipleChoice();
            break;
        case 3:
            p = new MatchAnswers();
            break;
        default:
            p = NULL;
            break;
    }
    return p;
}

TrueOrFalse::TrueOrFalse() {
    answers[0] = AnswerData('T', Boolean(true));
    answers[1] = AnswerData('F', Boolean(false));
}

void TrueOrFalse::showAnswers(std::ostream& outs) {
    for (int i = 0; i < 2; i++) {
        outs << answers[i].getAnswer() << std::endl;
    }
}

void TrueOrFalse::setAnswers() {
    Boolean b;
    answers[0].setOption('T');
    answers[1].setOption('F');

    std::string choice;
    while(true) {
        std::cout << "Is this answer true or false? (t/f) ";
        std::cin >> choice;

        for (int i = 0; i < choice.length(); i++) {
            choice[i] = tolower(choice[i]);
        }
        
        if (choice != "t" && choice != "f") { //if cin fails, reset and give error message
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error. char not entered. Please try again" << std::endl;
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }

    // if statement to init true and false answers based on cin data
    answers[0].setAnswerDetails(Boolean(true));
    answers[1].setAnswerDetails(Boolean(false));


}

MultipleChoice::MultipleChoice() {
    answers.push_back(AnswerData('A', Boolean(false)));
    answers.push_back(AnswerData('B', Boolean(false)));
    answers.push_back(AnswerData('C', Boolean(false)));
    answers.push_back(AnswerData('D', Boolean(false)));
}

void MultipleChoice::showAnswers(std::ostream& outs) {
    for(int i = 0; i < answers.size(); i++) {
        answers[i].getAnswer();
    }
}

void MultipleChoice::setAnswers() {
    std::cout << "set answers for MultipleChoice class has been called" << std::endl;
}

MatchAnswers::MatchAnswers() {
    answers.push_back(AnswerData('A', Match()));
}

void MatchAnswers::showAnswers(std::ostream& outs) {

}

void MatchAnswers::setAnswers() {
    std::cout << "set answers for MatchAnswers class has been called" << std::endl;
}