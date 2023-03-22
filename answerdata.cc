#include "answerdata.h"

#include <iostream>

AnswerData::AnswerData() {
    option = 'A';
    answer = "Test";
    answerDetails = SecondaryAnswer();
}

AnswerData::AnswerData(char newOption, SecondaryAnswer newAnswer) {
    option = newOption;
    answer = "Test";
    answerDetails = newAnswer;
}

char AnswerData::getOption() const {
    return option;
}

std::string AnswerData::getAnswer() const {
    return answer;
}

SecondaryAnswer AnswerData::getAnswerDetails() const {
    return answerDetails;
}

void AnswerData::setOption(char newOption) {
    option = newOption;
}

void AnswerData::setAnswer(std::string newAnswer) {
    answer = newAnswer;
}

void AnswerData::setAnswerDetails(SecondaryAnswer newDetails) {
    answerDetails = newDetails;
}

/*SecondaryAnswer * SecondaryAnswer::Create(int num) {
    SecondaryAnswer * p_item(NULL);
    switch(num) {
        case 1:
            p_item = new Boolean();
            break;
        case 2:
            p_item = new Match();
            break;
        default:
            p_item = NULL;
            break;
    }
    return p_item;
}*/

/*void AnswerData::setData(char optionChar) {
    std::string answerData;
    
    setOption(optionChar);
    std::cout << "Enter question" << std::endl;
    std::getline(std::cin, answerData);
    setAnswer(answerData);

    std::cout << "Is this answer correct? (y/n)" << std::endl;
    
    std::cin >> answerData;
    do {

    } while (answerData != "y" || )
}*/