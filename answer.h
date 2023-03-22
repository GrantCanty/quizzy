#ifndef Answer_h
#define Answer_h

#include "answerdata.h"

#include <vector>

class Answer {
    public:
        static Answer * Create(int num);
        virtual void getAnswers(std::ostream& outs) = 0;
        virtual void setAnswers() = 0;
};

class TrueOrFalse:public Answer {
    public:
        TrueOrFalse();
        void getAnswers(std::ostream& outs) override;
        void setAnswers() override;
    
    private:
        AnswerData answers[2];
};

class MultipleChoice:public Answer {
    public:
        MultipleChoice();
        void getAnswers(std::ostream& outs) override;
        void setAnswers() override;

    private:
        std::vector<AnswerData> answers;
};

class MatchAnswers:public Answer {
    public:
        MatchAnswers();
        void getAnswers(std::ostream& outs) override;
        void setAnswers() override;

    private:
        std::vector<AnswerData> answers;
};

#endif