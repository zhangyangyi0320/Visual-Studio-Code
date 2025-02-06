#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>

using namespace std;

// Function to generate a random arithmetic question and return the correct answer
pair<string, int> generateQuestion() {
    int num1 = rand() % 100 + 1;
    int num2 = rand() % 100 + 1;
    char op = rand() % 4;
    string question;
    int answer;

    switch (op) {
        case 0: // Addition
            question = to_string(num1) + " + " + to_string(num2);
            answer = num1 + num2;
            break;
        case 1: // Subtraction
            question = to_string(num1) + " - " + to_string(num2);
            answer = num1 - num2;
            break;
        case 2: // Multiplication
            question = to_string(num1) + " * " + to_string(num2);
            answer = num1 * num2;
            break;
        case 3: // Division (integer division)
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
        // Generate two random questions
        auto question1 = generateQuestion();
        auto question2 = generateQuestion();

        // Display the questions with their respective operations
        cout << "Choose a box (1 or 2) and solve the arithmetic question:" << endl;
        cout << "Box 1: " << question1.first << endl;
        cout << "Box 2: " << question2.first << endl;

        int choice;
        cin >> choice;

        int playerAnswer;
        cout << "Enter your answer: ";
        cin >> playerAnswer;

        // Check the player's answer and update the score
        if ((choice == 1 && playerAnswer == question1.second) || (choice == 2 && playerAnswer == question2.second)) {
            score++;
            cout << "Correct! Your score is: " << score << endl;
        } else {
            score -= 3;
            cout << "Wrong! Your score is: " << score << endl;
        }

        // Check if the game is over
        if (score < 0) {
            cout << "Game Over" << endl;
            this_thread::sleep_for(chrono::seconds(5)); // Wait for 5 seconds
            break;
        }
    }

    return 0;
}