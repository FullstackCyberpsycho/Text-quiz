#pragma once
#include "Quiz.h"
#include <iostream>
#include <vector>
#include <Windows.h>
#include <ctime>
#include <conio.h>
#include <stdio.h>
using namespace std;

enum ColorConsole {
    Green = 2,
    Red = 4,
    LightGreen = 10,
    yellow = 14,
    darkGray = 8,
    lightBlue = 11,
    LightGray = 7,
    LightBlue = 9
};

class Question {
private:
    string text;
    vector<string> answers;
    int8_t correct_id;

public:
    Question(const string& text, const vector<string>& answers, const int8_t& correct_id) {
        this->text = text;
        this->answers = answers;
        this->correct_id = correct_id;
    }
    friend class Quiz;
};

class Quiz {
private:
    vector<Question> questions;
    string userName;
    short score;

public:
    Quiz(const string& userName) : userName(userName), score(0) {};
    void addQuestion(Question question);
   
    void displayQuestion(const int8_t& index);      

    int getUserAnswer();
    short userAnswer;
  
    bool checkAnswer(const int8_t& index, const short& userAnswer);

    void runQuiz();      
};

void loading(const string& userName);
    
void displayQuestion(const string& userName);