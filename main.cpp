#include <iostream>
#include <fstream>
#include <vector>

void rearrangeNumbersUsingFilePointers(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);

    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Не вдалося відкрити файл.\n";
        return;
    }

    std::vector<double> positives;
    std::vector<double> negatives;
    int zerosCount = 0;

    double number;
    while (inFile >> number) {
        if (number > 0) {
            positives.push_back(number);
        } else if (number < 0) {
            negatives.push_back(number);
        } else {
            zerosCount++;
        }
    }

    for (const auto& num : positives) {
        outFile << num << std::endl;
    }
    for (int i = 0; i < zerosCount; i++) {
        outFile << 0 << std::endl;
    }
    for (const auto& num : negatives) {
        outFile << num << std::endl;
    }

    inFile.close();
    outFile.close();
}

int main() {
    std::string inputFile = "input.txt";
    std::string outputFile = "rearranged.txt";

    rearrangeNumbersUsingFilePointers(inputFile, outputFile);
    std::cout << "Копіювання файлу завершено." << std::endl;
    return 0;
}
