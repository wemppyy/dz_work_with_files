#include <iostream>
#include <fstream>
#include <vector>

void processNumbersUsingStreams(const std::string& inputFile, const std::string& negativeFile, const std::string& positiveFile) {
    std::ifstream inFile(inputFile);
    std::ofstream negFile(negativeFile);
    std::ofstream posFile(positiveFile);

    if (!inFile.is_open() || !negFile.is_open() || !posFile.is_open()) {
        std::cerr << "Не вдалося відкрити файл.\n";
        return;
    }

    double number;
    int negativeCount = 0, positiveCount = 0;

    while (inFile >> number) {
        if (number < 0) {
            negFile << number << std::endl;
            negativeCount++;
        } else if (number > 0) {
            posFile << number << std::endl;
            positiveCount++;
        }
    }

    negFile << "Кількість від’ємних чисел: " << negativeCount << std::endl;
    posFile << "Кількість додатних чисел: " << positiveCount << std::endl;

    inFile.close();
    negFile.close();
    posFile.close();
}

int main() {
    std::string inputFile = "input.txt";
    std::string negativeFile = "negative.txt";
    std::string positiveFile = "positive.txt";

    processNumbersUsingStreams(inputFile, negativeFile, positiveFile);
    std::cout << "Обробка файлу завершена." << std::endl;
    return 0;
}
