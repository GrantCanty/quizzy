#ifndef QuizQuestion_h
#define QuizQuestion_h

#include "answerdata.h"
#include "answer.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

class QuizQuestion {
    public:
        QuizQuestion();
        QuizQuestion(int num);
        
        void showQuestion(std::ostream& outs) const;
        void showAnswers(std::ostream& outs);

        void setQuestion(std::string q);
        void setAnswers(int choice);
        //int setAnswersMenu();

        void getMenu();
    
    private:
        std::string question;
        Answer *answers;
};

#endif /* Header_h */
