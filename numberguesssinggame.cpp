#include <iostream>
#include <cstdlib>   // For rand() and srand()
#include <ctime>     // For time()

int main() {
    // Seed the random number generator with current time
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // Define the range for the random number
    const int LOWER_BOUND = 1;
    const int UPPER_BOUND = 100;

    // Generate the secret number
    int secretNumber = LOWER_BOUND + std::rand() % (UPPER_BOUND - LOWER_BOUND + 1);

    int userGuess = 0;
    int attempts = 0;

    std::cout << "Welcome to the Number Guessing Game!\n";
    std::cout << "I'm thinking of a number between " << LOWER_BOUND << " and " << UPPER_BOUND << ".\n";

    // Main guessing loop
    do {
        std::cout << "Enter your guess: ";
        std::cin >> userGuess;
        attempts++;

        if (userGuess < secretNumber) {
            std::cout << "Too low! Try a higher number.\n";
        } else if (userGuess > secretNumber) {
            std::cout << "Too high! Try a lower number.\n";
        } else if (userGuess == secretNumber) {
            std::cout << "Congratulations! You guessed the number in " << attempts << " attempts.\n";
        } else {
            std::cout << "Invalid input. Please enter a valid number.\n";
        }
    } while (userGuess != secretNumber);

    std::cout << "Thank you for playing!\n";
    return 0;
}