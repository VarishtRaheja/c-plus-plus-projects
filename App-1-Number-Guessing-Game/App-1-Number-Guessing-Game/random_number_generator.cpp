// For the game
#include <iostream>
#include <random>
#include <cstdlib>
#include <limits> // for std::numeric_limits
#include <tuple>
#include <vector>
#include <cmath> // For std::floor

// For logging the attempts
//#include <fstream>
//#include <ctime>
//#include <chrono>
//#include <iomanip>

const int MAX_VALUE{ 1000 };

// Creating the logger function which saves the win/loss ratio along with username and date/time
// WIP - Havent learned OOP, structs...etc
// For now creating a simple array which stores the win/loss.(Simpler)
//static void logger_profiler(int attempts) {
//	int guesses[]{attempts};
//
//
//}

// Creating a difficulty structure
enum class Difficulty {
	Easy = 1,	//0
	Medium = 2,	//1
	Hard = 3	//2
};


static std::uniform_int_distribution<int> user_random_number(std::mt19937 &rng) {

	bool user_number_range{};
	int min_range{};
	int max_range{};

	while (true) {
		std::cout << "Would you like to decide the range of the numbers? (1=Yes, 0=No):  ";
		// Checking for user validation
		if (!(std::cin >> user_number_range)) {
			std::cout << "Please enter the number 1 or 0. \n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		if (!user_number_range) {
			min_range = 1;
			max_range = 100;
		}
		else {
			std::cout << "Enter min and max (max <= " << MAX_VALUE << "): ";
			if (!(std::cin >> min_range >> max_range)) {
				std::cout << "Invalid numbers. Try again. \n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
			if (min_range > max_range || MAX_VALUE < max_range || min_range == 0) {
				std::cout << "Error: Ensure 1 < min < max < " << MAX_VALUE << " \n";
				continue;
			}
		}
		// We have valid min and max numbers
		// Seed the random number generator with random engine.
		std::uniform_int_distribution<int>distribution(min_range, max_range);
		return distribution;
	}

}

static int user_choice_number() {

	int chances{};
	//Chances for the user to guess the number	
	while (true) {
		std::cout << "How many chances would you like? ";
		// Check if input is integer
		if (!(std::cin >> chances)) {
			std::cout << "That is not a valid integer. \n";

			//Clear error flags and discard invalid input
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');	// flushes the bad input.
		}
		else if (chances < 1 || chances > 5) {
			std::cout << "Error: Please keep your chances between 1 and 5 (included).\n";
		}
		else {
			std::cout << "Chances given: " << chances << "\n";
			break;	// exit loop if input is valid
		}
	}
	return chances;
}

// Function to create the difficulty
static void Difficulty_Options(Difficulty game_settings, int &fetch_chances, std::uniform_int_distribution<int>&distrib) {
	// Create the bounds of the random generator
	int lower_bound = distrib.a();
	int upper_bound = distrib.b();

	if (game_settings >= Difficulty::Easy && game_settings <= Difficulty::Hard) {
		switch (game_settings) {
			// Each case: Modifying chances and max bound of range.
		case Difficulty::Easy:
			std::cout << "Chosen difficulty: Easy \n";
			std::cout << "Chances increased by 1. Max range reduced by 25%.\n";
			fetch_chances += 1;
			distrib = std::uniform_int_distribution<int>(lower_bound, static_cast<int>(std::floor(upper_bound * 0.75)));
			break;

		case Difficulty::Medium:
			std::cout << "Chosen difficulty: Medium \n";
			std::cout << "Chances decreased by 1. Max range increased by 25%.\n";
			fetch_chances -= 1;
			distrib = std::uniform_int_distribution<int>(lower_bound, static_cast<int>(std::floor(upper_bound * 1.25)));
			break;

		case Difficulty::Hard:
			std::cout << "Chosen difficulty: Hard \n";
			std::cout << "Chances decreased by 2. Max range increased by 50%.\n";
			try {
				fetch_chances -= 2;
				distrib = std::uniform_int_distribution<int>(lower_bound, static_cast<int>(std::floor(upper_bound * 1.5)));
				if (fetch_chances <= 0 || upper_bound > MAX_VALUE) {
					throw std::runtime_error("Error: For hard mode keep a minimum of 3 chances by default.");
				}
			}
			catch(std::exception &e){
				std::cerr << "Exception: Chances cannot be 0 and do not exceed MAX VALUE (1000). " << e.what() << std::endl;
			}
			
			break;

		default:
			// default settings and chances.
			distrib = std::uniform_int_distribution<int>(lower_bound, upper_bound);
			std::cout << "Invalid input. Please enter: [1 < input < 3] \n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		}
	}
	else {
		fetch_chances -= 0;
		std::cout << "Chances and range are unchanged. \n";

	}
}

// Logic implementation of the game.
std::tuple<int,int,int> guessing_game(char start_game, std::mt19937 &rng) {
	int i{ 1 };		// increment the choco chip cookie when re-play game.

	std::vector<int> total_attempt(3);

	// Function to create the guessing game.
	while (start_game == 'y') {

		// Setting the difficulty of the game and modifying chances given
		std::cout << "Set the difficulty of the game: \n";
		std::cout << "Easy = 1 \t Medium = 2 \t Hard = 3 \n";

		int difficulty_input{};
		std::cin >> difficulty_input;
		Difficulty curr_option = static_cast<Difficulty>(difficulty_input);
		
		// Call the user_random_number to generate teh random distribution
		std::uniform_int_distribution<int>distrib = user_random_number(rng);
		
		// Lets call the user defined chances
		int get_chances = user_choice_number();

		// Select the difficulty option:
		Difficulty_Options(curr_option, get_chances,distrib);

		// Changes after selecting difficulty
		std::cout << "Chances left now: " << get_chances << '\n';
		std::cout << " Max Range modified: " << distrib.b() << '\n';

		int guessed_number{0};

		// Generate the random number to check against user input.
		int get_random_number = distrib(rng);

		// Start the event loop
		while (get_chances > 0) {
			std::cout << "Enter the number your guess: ";
			// Making sure the number is being added
			if (!(std::cin >> guessed_number)) {
				std::cout << "Please enter a valid number. \n";
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				continue;
			}
			// second if conditional - directly ending the game on guessing the number
			if (guessed_number == get_random_number) {
				std::cout << "The number " << guessed_number << " was correct! Congratulations. \n";
				std::cout << "You have won " << i << " double chocolate chip cookie(s) \n";
				++i;
				total_attempt[1]++;		//array of index 1: holding win stats.
				break;
			}
			// Logic to enhance variability like greater; lesser and reducing chances
			else {
				--get_chances;
				std::cout << " Incorrect guess! You currently have " << get_chances << " chance(s) left. \n";
				if (get_chances == 0) {
					std::cout << "You have run out of chances. Correct number was " << get_random_number <<  "\n";
					total_attempt[2]++;		//index 2: holding loss stats
					break;
				}
				else if (guessed_number > get_random_number) {
					std::cout << "Too high! Try again. \n";
				}
				else {
					std::cout << "Too low!. Try again \n";
				}
			}
		}
		total_attempt[0]++;		//index 0: holding total attempts stats

		std::cout << "Game over! Would you like to play again? (y/n): ";
		std::cin >> start_game;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	}
	
	if (start_game == 'n') {
		std::cout << "Too bad! You could have won one or more double chocolate chip cookies. \n";
		std::cout << "\n";
	}
	
	//Output the array of the stats 
	int attempts = total_attempt[0];
	int wins = total_attempt[1];
	int losses = total_attempt[2];

	return {attempts,wins,losses};
}
