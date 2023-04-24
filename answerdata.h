#ifndef AnswerData_h
#define AnswerData_h

#include <string>

class Boolean {
    public:
        Boolean() { isCorrectAnswer = false; }
        Boolean(bool b) { isCorrectAnswer = b; }
        bool isCorrect() { return isCorrectAnswer; }
    private:
        bool isCorrectAnswer;
};

/*class Match:public AnswerDetails {
    public:
        Match() { 
            option = ' '; 
            answer = " "; 
            }
        Match(char c, std::string s) {
            option = c;
            answer = s;
        }
    private:
        char option;
        std::string answer;
};*/

class AnswerData {
    public:
        AnswerData();
        AnswerData(char newOption, Boolean newSecAnswer);
        
        char getOption() const;
        std::string getAnswer() const;
        Boolean getAnswerDetails() const;

        
        void setOption(char newOption);
        void setAnswer(std::string newAnswer);
        void setAnswerDetails(Boolean newDetails);
    
    private:
        char option;
        std::string answer;
        Boolean answerDetails;
};

#endif