#include "Quiz.h"
HANDLE hConsole;

void Quiz::addQuestion(Question question) {
    questions.push_back(question);
}

void Quiz::displayQuestion(const int8_t & index) {
    SetConsoleTextAttribute(hConsole, darkGray);
    cout << "������ " << index + 1 << "/" << questions.size() << endl;
    SetConsoleTextAttribute(hConsole, lightBlue);
    cout << questions[index].text << endl;
    SetConsoleTextAttribute(hConsole, LightGray);

    for (short i = 0; i < questions[index].answers.size(); ++i) {
        cout << i + 1 << ") " << questions[index].answers[i] << endl;
    }
}

int Quiz::getUserAnswer() {
    SetConsoleTextAttribute(hConsole, darkGray);
    cout << "������� ����� (1-4): ";
    cin >> userAnswer;

    while (userAnswer < 1 || userAnswer > 9) {
        SetConsoleTextAttribute(hConsole, Red);
        cout << "�������� �����! ������� ����� 1-4: ";
        cin >> userAnswer;
    }

return userAnswer;
}

bool Quiz::checkAnswer(const int8_t & index, const short& userAnswer) {
    return userAnswer == questions[index].correct_id;
}

void Quiz::runQuiz() {
    for (short i = 0; i < questions.size(); ++i) {
        displayQuestion(i);
        int8_t userAnswer = getUserAnswer();
        if (checkAnswer(i, userAnswer)) {
            system("cls");
            SetConsoleTextAttribute(hConsole, LightGreen);
            cout << "����� ��� ����������!" << endl;
            score++;
        } else {
            system("cls");
            SetConsoleTextAttribute(hConsole, Red);
            cout << "����� ��� ��������!" << endl;
        }
    }

    system("cls");
    SetConsoleTextAttribute(hConsole, LightGreen);
    cout << "��������� ���������! " << endl << userName << ", ��� ����: "; 
    SetConsoleTextAttribute(hConsole, darkGray);
    cout << score << "/" << questions.size() << endl
        << "����������� - ����� �������!" << endl;
    SetConsoleTextAttribute(hConsole, 0);
}

void loading(const string & userName) {
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    short time = rand() % 290 + 310;
    for (short i = 0; i <= 100; i++) {
        
        Sleep(time);
        system("cls");
        SetConsoleTextAttribute(hConsole, Red);
        cout << userName << ", ����������, ��������� �������..." << endl;
        SetConsoleTextAttribute(hConsole, Green);
        cout << "��������... " << i << "%" << " �� 100%" << endl;

        if (i == 20) {
            time = rand() % 40 + 50;
        } else if (i == 50) {
            time = rand() % 3 + 1;
        } else if (i == 100) {
            system("cls");
            SetConsoleTextAttribute(hConsole, LightGreen);
            cout << userName << ", �������� �� ��������!" << endl;
            break;
        }
    }
}

void displayQuestion(const string& userName) {
Quiz quiz(userName);

Question q1("����� �������� �������� ���������� �������������� ���������� � ����?"
    , { "Samsung", "Apple", "Huawei", "Xiaomi" }, 2);

Question q2("����� ������������ ������� �������� ����� ���������� � ����?"
    , { "Android", "iOS", "Windows", "Linux" }, 1);

Question q3("����� ���� ���������������� �������� ����� ���������� � ����?"
    , { "Python", "Java", "JavaScript", "C++" }, 1);

Question q4("����� ������� �������� ����� ���������� � ����?"
    , { "Mozilla Firefox", "Safari", "Internet Explorer", "Google Chrome" }, 4);

Question q5("����� ������ ������ �������� ����� ���������� ��� �����������?"
    , { "SVG", "PNG", "JPEG", "GIF" }, 3);

Question q6("����� ������ ������ �������� ����� ���������� ��� �����?"
    , { "AVI", "MP4", "MKV", "FLV" }, 2);

Question q7("����� ������ ������ �������� ����� ���������� ��� �����?"
    , { "MP3", "WAV", "AAC", "FLAC" }, 1);

Question q8("����� ���� ���������������� �������� ����� ���������� ��� ���-����������?"
    , { "C++", "Python", "Java", "JavaScript" }, 4);

Question q9("����� ���� ���������������� �������� ����� ���������� ��� ���������� ��������� ����������?"
    , { "Python", "Java", " C++", "JavaScript" }, 2);

Question q10("����� ���� ���������������� �������� ����� ���������� ��� ���������� ���?"
    , { "Python", "JavaScript", "C++", "C#" }, 3);

quiz.addQuestion(q1);
quiz.addQuestion(q2);
quiz.addQuestion(q3);
quiz.addQuestion(q4);
quiz.addQuestion(q5);
quiz.addQuestion(q6);
quiz.addQuestion(q7);
quiz.addQuestion(q8);
quiz.addQuestion(q9);
quiz.addQuestion(q10);

quiz.runQuiz();
}