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
        
        void getQuestion(std::ostream& outs) const;
        void getAnswers(std::ostream& outs);

        void setQuestion(std::string q);
        void setAnswers(int choice);
        int setAnswersMenu();

        void getMenu();
    
    private:
        std::string question;
        Answer *answers;
};

/*class TrueFalse:public QuizQuestion {
    public:
        TrueFalse();
        void setAnswers();
        void setAnswer();
        void getQuestionsAndAnswers(std::ostream& outs) override;
    
    private:
        AnswerData answers[2];
};

class MultipleChoice:public QuizQuestion {
    public:
        MultipleChoice();
        void setAnswers();
        void setAnswer();
        void getQuestionsAndAnswers(std::ostream& outs) override;

    private:
        std::vector<AnswerData> answers;
};

class Text: public QuizQuestion {
    public:
        Text();
        void setAnswer();

    private:
        std::string answer;
};*/

#endif /* Header_h */
