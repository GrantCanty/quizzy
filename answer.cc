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

void TrueOrFalse::getAnswers(std::ostream& outs) {
    /*for (int i = 0; i < answers.length(); i++) {
        outs << i << std::endl;
    }*/
}

void TrueOrFalse::setAnswers() {
    Boolean b;
    answers[0].setOption('T');
    answers[1].setOption('F');

    std::cout << "Is this answer true or false? (t/f) ";
    
    /*do {
        // cin in get if question is t or false
    } while(false);*/

    // if statement to init true and false answers based on cin data
    answers[0].setAnswerDetails(Boolean(true));
    answers[1].setAnswerDetails(Boolean(false));


}

MultipleChoice::MultipleChoice() {
    answers.push_back(AnswerData('A', Boolean(false)));
}

void MultipleChoice::getAnswers(std::ostream& outs) {

}

void MultipleChoice::setAnswers() {
    std::cout << "set answers for MultipleChoice class has been called" << std::endl;
}

MatchAnswers::MatchAnswers() {
    answers.push_back(AnswerData('A', Match()));
}

void MatchAnswers::getAnswers(std::ostream& outs) {

}

void MatchAnswers::setAnswers() {
    std::cout << "set answers for MatchAnswers class has been called" << std::endl;
}