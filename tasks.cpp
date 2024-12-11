#include <iostream>
#include <vector>
#include <limits>
bool isValidBinaryString(const std::string &input) {
        for (char ch : input) {
            if (ch != '0' && ch != '1') return false;
        }
        return true;
    }
bool isValidInput(const std::string& input) {
    return !input.empty();
}


class task_1 {
public:
void Menu(){
    std::cout << "Сделал: Лебедюк Юрий(453501) Вариант номер 5. В данной задаче нужно найти колличество единиц в строке с нечетными символами.\n";
    std::cout << "----------------------------------------------------------------------------------------------------------------------------\n";
}
int countOnesInOddGroups(char* str) {
    int count = 0;
    for (int i = 0; str[i] != '\0'; ++i) {
        if (str[i] == '1') {
            count++;
        }
    }
    return count;
}
void run(){
    Menu();
   char str[80];
    std::cout << "Введите строку, состоящую из нулей и единиц: ";
    std::cin >> str;

    if (!isValidBinaryString(str)) {
        return;
    }

    int result = countOnesInOddGroups(str);
    std::cout << "Количество единиц с нечетным количеством символов: " << result << std::endl;
}      
};
class task_2{
    public:
    void Menu(){
        std::cout << "Сделал Лебедюк Юрий(453501) Вариант номер 5. В данной задаче нужно после каждого слова текста, оканчивающегося заданной подстрокой, вставить указанный символ.";
        std::cout << "----------------------------------------------------------------------------------------------------------------------------\n";
    }
bool endsWith(const char* word, const char* substring) {
    int wordLen = 0, subLen = 0;

    while (word[wordLen] != '\0') {
        wordLen++;
    }

    while (substring[subLen] != '\0') {
        subLen++;
    }
    if (wordLen < subLen) {
        return false;
    }
    for (int i = 0; i < subLen; ++i) {
        if (word[wordLen - subLen + i] != substring[i]) {
            return false;
        }
    }

    return true;
}

void processText(const char* inputText, const char* substring, char symbol, char* resultText) {
    char word[100];
    int wordIndex = 0;
    int resultIndex = 0;

    for (int i = 0;; ++i) {
        char currentChar = inputText[i];
        if (currentChar == ' ' || currentChar == '\0') {
            word[wordIndex] = '\0';
            if (endsWith(word, substring)) {
                int len = 0;
                while (word[len] != '\0') {
                    len++;
                }
                word[len] = symbol;
                word[len + 1] = '\0';
            }
            for (int j = 0; word[j] != '\0'; ++j) {
                resultText[resultIndex++] = word[j];
            }
            if (currentChar == ' ') {
                resultText[resultIndex++] = ' ';
            }
            wordIndex = 0;
            if (currentChar == '\0') {
                break;
            }
        } else {
            word[wordIndex++] = currentChar;
        }
    }
    resultText[resultIndex] = '\0';
}


void run(){
    Menu();
     char inputText[100];
    char substring[100];
    char resultText[100 * 2] = "";
    char symbol;

    std::cout << "Введите текст: ";
    std::cin.ignore();
    std::cin.getline(inputText, 100);

    if (!isValidInput(inputText)) {
        return;
    }

    std::cout << "Введите подстроку: ";
    std::cin >> substring;

    if (!isValidInput(substring)) {
        return;
    }

    std::cout << "Введите символ: ";
    std::cin >> symbol;

    processText(inputText, substring, symbol, resultText);
    std::cout << "Результат: " << resultText << std::endl;
}
};
class task_3{
    public:
    void Menu(){
        std::cout << "Сделал Лебедюк Юрий(453501) Вариант номер 5. В данной задаче нужно В массиве строк найти среднее значение длины строки. Строки,длина которых больше среднего, – обрезать, меньше – добавить пробелы.Полученный массив вывести на экран.";
        std::cout << "----------------------------------------------------------------------------------------------------------------------------\n";
    }
int calculateAverageLength(char arr[][100], int n) {
    int totalLength = 0;
    for (int i = 0; i < n; i++) {
        int length = 0;
        while (arr[i][length] != '\0') {
            length++;
        }
        totalLength += length;
    }
    return totalLength / n;
}

void processString(char* str, int avgLength) {
    int currentLength = 0;
    while (str[currentLength] != '\0') {
        currentLength++;
    }

    if (currentLength > avgLength) {
        str[avgLength] = '\0';
    } else if (currentLength < avgLength) {
        for (int i = currentLength; i < avgLength; i++) {
            str[i] = ' ';
        }
        str[avgLength] = '\0';
    }
}

void inputStrings(char arr[][100], int n) {
    std::cin.ignore();
    std::cout << "Введите строки:\n";
    for (int i = 0; i < n; i++) {
        int index = 0;
        char c;
        while (index < 99 && (c = std::cin.get()) != '\n') {
            arr[i][index++] = c;
        }
        arr[i][index] = '\0';
    }
}

void printStrings(char arr[][100], int n) {
    std::cout << "Измененные строки:\n";
    for (int i = 0; i < n; i++) {
        std::cout << "\"";
        for (int j = 0; arr[i][j] != '\0'; j++) {
            std::cout << arr[i][j];
        }
        std::cout << "\"" << std::endl;
    }
}

void run(){
    Menu();
    int n;
    std::cout << "Введите количество строк: ";
    std::cin >> n;
    char arr[n][100];
    inputStrings(arr, n);
    int avgLength = calculateAverageLength(arr, n);
    for (int i = 0; i < n; i++) {
        processString(arr[i], avgLength);
    }
    printStrings(arr, n);
}
};
