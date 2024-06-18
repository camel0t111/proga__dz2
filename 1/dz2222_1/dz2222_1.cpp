#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void removeLastLine(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream inFile(inputFile);
    std::ofstream outFile(outputFile);

    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Error opening file." << std::endl;
        return;
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(inFile, line)) {
        lines.push_back(line);
    }

    inFile.close();

    for (size_t i = 0; i < lines.size() - 1; ++i) {
        outFile << lines[i] << std::endl;
    }

    outFile.close();
}

int main() {
    removeLastLine("input.txt", "output.txt");
    return 0;
}
