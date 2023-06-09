#ifndef Answer_h
#define Answer_h

#include "answerdata.h"

#include <vector>

class Answer {
    public:
        static Answer * Create(int num);
        virtual void showAnswers(std::ostream& outs) = 0;
        virtual void showCorrectAnswer(std::ostream& outs) = 0;
        virtual void setAnswers() = 0;
};

class TrueOrFalse:public Answer {
    public:
        TrueOrFalse();
        void showAnswers(std::ostream& outs) override;
        void showCorrectAnswer(std::ostream& outs) override;
        void setAnswers() override;
    
    private:
        AnswerData answers[2];
};

class MultipleChoice:public Answer {
    public:
        MultipleChoice();
        void showAnswers(std::ostream& outs) override;
        void showCorrectAnswer(std::ostream& outs) override;
        void setAnswers() override;

    private:
        std::vector<AnswerData> answers;
};

class Text:public Answer {
    public:
        Text();
        void showAnswers(std::ostream& outs) override;
        void showCorrectAnswer(std::ostream& outs) override;
        void setAnswers() override;

    private:
        std::string answers;
};

#endif