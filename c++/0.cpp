#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

// Function to generate a random arithmetic question and return the correct answer
pair<string, int> generateQuestion(char op) {
    int num1 = rand() % 100 + 1;
    int num2 = rand() % 100 + 1;
    string question;
    int answer;

    switch (op) {
        case '+': // Addition
            question = to_string(num1) + " + " + to_string(num2);
            answer = num1 + num2;
            break;
        case '-': // Subtraction
            question = to_string(num1) + " - " + to_string(num2);
            answer = num1 - num2;
            break;
        case '*': // Multiplication
            question = to_string(num1) + " * " + to_string(num2);
            answer = num1 * num2;
            break;
        case '/': // Division (integer division)
            // Ensure num2 is not zero
            num2 = num2 == 0 ? 1 : num2;
            question = to_string(num1) + " / " + to_string(num2);
            answer = num1 / num2;
            break;
    }

    return {question, answer};
}

int main() {
    srand(time(0)); // Seed for random number generation
    int score = 0;

    while (true) {
        // Generate two random operations
        char op1 = "+-*/"[rand() % 4];
        char op2 = "+-*/"[rand() % 4];

        // Display the operations with their respective boxes
        cout << "Choose a box (1 or 2) and remember the operation:" << endl;
        cout << "Box 1: " << op1 << endl;
        cout << "Box 2: " << op2 << endl;

        int choice;
        cin >> choice;

        if (choice != 1 && choice != 2) {
            cout << "Invalid choice. Please enter 1 or 2." << endl;
            continue;
        }

        // Generate the question based on the chosen operation
        auto question = generateQuestion(choice == 1 ? op1 : op2);

        int playerAnswer;
        cout << "The question is: " << question.first << endl;
        cout << "Enter your answer: ";
        cin >> playerAnswer;

        // Check the player's answer and update the score
        if (playerAnswer == question.second) {
            score++;
            cout << "Correct! Your score is: " << score << endl;
        } else {
            score -= 3;
            cout << "Wrong! Your score is: " << score << endl;
        }

        // Check if the game is over
        if (score < 0) {
            cout << "Game Over" << endl;
            Sleep(5000); // Wait for 5 seconds
            break;
        }
    }

    return 0;
}