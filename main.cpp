/*
This program is a simple number guessing game. The player is be prompted for a guess of a number
between 1 and 100 and will get 20 attempts. If the player guesses the random number within 20
attempts, he/she wins.
*/

#include <iostream> // I/O
#include <cstdlib> // Include for rand() and srand()
#include <ctime> // Include for time()

int checkGuess(int numRand, int guess); // Function prototype

// Entry point

int main() {
	srand(time(NULL)); // Seeding rand() with time so it's actually random
	int numRand = rand() % 100 + 1; // Generates a random number between 1 - 100
	int guess = 0; // Players guess is stored here
	int tries = 1; // Guessing attempts stored here. Set to 1 otherwise the number of attempts is always 1 too many when the attempts are printed out below

	/*
	Prompts the player for a guess and takes that input.
	Loops through and checks if the players guess is <= 1, <= 5, <= 10, <= 20, or > 20 and outputs
	the message associated with that condition.
	Checks if the players guess is not equal to the random number. If it is not, the message is displayed.
	tries is incremented
	*/

	while(true) {
		//std::cout << numRand << std::endl; // Used for debugging
		std::cout << "Enter a number between 1 and 100 (" << 21 - tries << " tries left): "; // Prompts the player for a guess. Also displays the remaining amount of attempts left
		std::cin >> guess; // Prompts player for their guess
		if(checkGuess(numRand, guess) <= 1 && guess != numRand)
			std::cout << "You're really close now!\n";
		else if(checkGuess(numRand, guess) <= 5 && guess != numRand)
			std::cout << "You're getting closer!\n";
		else if(checkGuess(numRand, guess) <= 10 && guess != numRand)
			std::cout << "You're far off!\n";
		else if(checkGuess(numRand, guess)  <= 20 && guess != numRand)
			std::cout << "You're really far off!\n";
		else if (checkGuess(numRand, guess) > 20 && guess != numRand)
			std::cout << "You're not even close!\n";

		tries++; // Increment players attempts

		/*
		Determines how many attempts the player has entered and prints the message associated with
		winning or losing. If the player does not guess the random number within 20 attempts,
		they get the Loss message and the program exits.
		If they guess the random number, they get the Win message and
		the program exits.
		*/

		while(tries >= 21) {
			// Loss message
			std::cout << "You ran out of tries! The randomly generated number was: " << numRand << " And you made " << tries - 1 << " guesses\n";
			return 1; //Exits the program
		}
		while(guess == numRand) {
			// Win message
			std::cout << "You won! The randomly generated number was: " << numRand  << " And you made "  << tries - 1 << " guesses\n";
			return 1; // Exits the program
		}

	}

	return 0;
}

/*
checkGuess is a value returning function that takes in 2 ints: numRand and guess.
An int difference is defined inside the function.
If the players guess is less than the random number, difference = the random number - guess.
else difference = the guess - the random number.
difference is returned.
*/

int checkGuess(int numRand, int guess) {
	int difference = 0;
	if(numRand > guess)
		difference = numRand - guess;
	else
		difference = guess - numRand;
	return difference;
}