#include "Quiz.h"

int main() {    
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(std::time(0));
    
    SetConsoleTextAttribute(hConsole, yellow);
    cout << "Добро пожаловать на IT-квиз!" << endl;
    std::string userName;
    SetConsoleTextAttribute(hConsole, Green);
    cout << "Введите ваше имя: ";
    std::cin >> userName;

    loading(userName);   
    displayQuestion(userName);
    
    system("pause");
    return 0;
}