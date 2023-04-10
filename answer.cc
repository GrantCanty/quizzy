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
            p = new Text();
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
        outs << answers[i].getOption() << ": " << answers[i].getAnswer() << std::endl;
    }
}

void TrueOrFalse::setAnswers() {
    answers[0].setAnswer("True");
    answers[1].setAnswer("False");
    
    std::string choice;
    while(true) {
        std::cout << "Is this answer true or false? (t/f) ";
        std::cin >> choice;

        for (int i = 0; i < choice.length(); i++) {
            choice[i] = tolower(choice[i]);
        }
        
        if (choice != "t" && choice != "f") { //neither t nor f, reset and give error message
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
    if (choice == "t") {
        answers[0].setAnswerDetails(Boolean(true));
        answers[1].setAnswerDetails(Boolean(false));
    }
    else {
        answers[0].setAnswerDetails(Boolean(false));
        answers[1].setAnswerDetails(Boolean(true));
    }


}

MultipleChoice::MultipleChoice() {
    answers.push_back(AnswerData('A', Boolean(false)));
    answers.push_back(AnswerData('B', Boolean(false)));
    answers.push_back(AnswerData('C', Boolean(false)));
    answers.push_back(AnswerData('D', Boolean(false)));
}

void MultipleChoice::showAnswers(std::ostream& outs) {
    for(int i = 0; i < answers.size(); i++) {
        outs << answers[i].getOption() << ":" << answers[i].getAnswer() << std::endl;
    }
}

void MultipleChoice::setAnswers() {
    std::string answer;
    for (int i = 0; i < answers.size(); i++) {
        std::cout << "Enter answer for question " << answers[i].getOption() << ": ";
        std::getline(std::cin, answer);
        answers[i].setAnswer(answer);
    }
    
    char finalChoice;
    std::string choice;
    while(true) {
        std::cout << "Which answer is true? (a,b,c,d) ";
        std::cin >> choice;

        for (int i = 0; i < choice.length(); i++) {
            choice[i] = tolower(choice[i]);
        }
        
        if (choice != "a" && choice != "b" && choice != "c" && choice != "d") { //neither t nor f, reset and give error message
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error. char not entered. Please try again" << std::endl;
        }
        else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            finalChoice = choice[0];
            break;
        }
    }

    switch (finalChoice)
    {
    case 'a':
        answers[0].setAnswerDetails(Boolean(true));
        break;
    case 'b':
        answers[1].setAnswerDetails(Boolean(true));
        break;
    case 'c':
        answers[2].setAnswerDetails(Boolean(true));
        break;
    case 'd':
        answers[3].setAnswerDetails(Boolean(true));
        break;
    default:
        break;
    }

}

Text::Text() {
    answers = "";
}

void Text::showAnswers(std::ostream& outs) {
    outs << answers << std::endl;
}

void Text::setAnswers() {
    std::cout << "Enter answer" << std::endl;
    std::string answer;
    std::getline(std::cin, answer);
}