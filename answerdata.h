#ifndef AnswerData_h
#define AnswerData_h

#include <string>

class SecondaryAnswer {
    public:
        //SecondaryAnswer * Create(int num);
};

class Boolean:public SecondaryAnswer {
    public:
        Boolean() { answer = false; }
        Boolean(bool b) { answer = b; }
    private:
        bool answer;
};

class Match:public SecondaryAnswer {
    public:
        Match() { 
            option = 'E'; 
            answer = "Test"; 
            }
        Match(char c, std::string s) {
            option = c;
            answer = s;
        }
    private:
        char option;
        std::string answer;
};

class AnswerData {
    public:
        AnswerData();
        AnswerData(char newOption, SecondaryAnswer newAnswer);
        
        char getOption() const;
        std::string getAnswer() const;
        SecondaryAnswer getAnswerDetails() const;
        
        void setOption(char newOption);
        void setAnswer(std::string newAnswer);
        void setAnswerDetails(SecondaryAnswer newDetails);
    
    private:
        char option;
        std::string answer;
        SecondaryAnswer answerDetails;
};

#endif