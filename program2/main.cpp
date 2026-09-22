#include "BracketOutput.h"
#include "ContainsDigit.h"
#include "FilterOutput.h"
#include "NumberedOutput.h"
#include "Output.h"
#include "StreamOutput.h"

#include <fstream>
#include <iostream>
#include <memory>
#include <string>

void runFile(const std::string& filename) {
    std::ifstream file(filename);

    if (!file) {
        std::cerr << "Could not open " << filename << '\n';
        return;
    }

    std::unique_ptr<Output> output =
        std::make_unique<FilterOutput>(
            std::make_unique<NumberedOutput>(
                std::make_unique<BracketOutput>(
                    std::make_unique<StreamOutput>(std::cout)
                )
            ),
            std::make_unique<ContainsDigit>()
        );

    std::string line;

    while (std::getline(file, line)) {
        output->write(line);
    }
}

void orderingDemo() {
    std::cout << "\n--- Filter Before Numbering ---\n";

    std::unique_ptr<Output> firstChain =
        std::make_unique<FilterOutput>(
            std::make_unique<NumberedOutput>(
                std::make_unique<BracketOutput>(
                    std::make_unique<StreamOutput>(std::cout)
                )
            ),
            std::make_unique<ContainsDigit>()
        );

    firstChain->write("Hello");
    firstChain->write("CS3450");

    std::cout << "\n--- Filter After Numbering ---\n";

    std::unique_ptr<Output> secondChain =
        std::make_unique<NumberedOutput>(
            std::make_unique<FilterOutput>(
                std::make_unique<BracketOutput>(
                    std::make_unique<StreamOutput>(std::cout)
                ),
                std::make_unique<ContainsDigit>()
            )
        );

    secondChain->write("Hello");
    secondChain->write("CS3450");
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./decorator decorator.txt\n";
        return 1;
    }

    std::cout << "--- decorator.txt output ---\n";

    runFile(argv[1]);

    orderingDemo();

    return 0;
}