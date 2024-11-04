#include <iostream>
#include <fstream>

void countNegativeNumbersUsingStreams(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);

    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Не вдалося відкрити файл.\n";
        return;
    }

    double number;
    int position = 1;
    int negativeCount = 0;

    while (inFile >> number) {
        if (number < 0) {
            outFile << "Позиція: " << position << ", Значення: " << number << std::endl;
            negativeCount++;
        }
        position++;
    }

    std::cout << "Кількість від’ємних чисел: " << negativeCount << std::endl;

    inFile.close();
    outFile.close();
}

int main() {
    std::string inputFile = "input.txt";
    std::string outputFile = "negative_positions.txt";

    countNegativeNumbersUsingStreams(inputFile, outputFile);
    return 0;
}
