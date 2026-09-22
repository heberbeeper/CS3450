# Program 2 - Decorator Pattern

This program implements the Decorator design pattern using C++.

The program includes:

StreamOutput
BracketOutput
NumberedOutput
FilterOutput
Predicate interface
ContainsDigit predicate

The driver reads decorator.txt one line at a time and passes each
line through a chain of decorators.

## Language

C++17

## Build and Run

### Linux/GitHub Codespaces

Compile:

bash:

g++ -std=c++17 main.cpp -o decorator

Run to output to terminal:

./decorator decorator.txt

Run to capture output in file:

./decorator decorator.txt > CapturedOutput.txt