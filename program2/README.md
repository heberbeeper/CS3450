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

TWO CHAIN ORDER EXPLANATION:
    The two chains produce different results because the filter evaluates whatever 
text reaches it at its position in the decorator chain. When FilterOutput comes 
before NumberedOutput, it sees the original text, so "Hello" fails the ContainsDigit 
predicate. When the filter comes after NumberedOutput, the line number has already 
added a digit, so the same input passes the predicate.

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