#ifndef Quiz_h
#define Quiz_h

#include "quizquestion.h"

#include <iostream>
#include <fstream>
#include <vector>

class Quiz {
    public:
        void showAllQuestions(std::ostream& outs);
        //void outputAllQuestions(std::ofstream& ofs);
        void setQuestions();
        int getMenu();

    private:
        std::vector<QuizQuestion> questions;
};

#endif