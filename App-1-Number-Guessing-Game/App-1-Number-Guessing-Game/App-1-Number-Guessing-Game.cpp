// App-1-Number-Guessing-Game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//1. Adding a complexity layer - adding difficulties
//2. Adding a complexity layer - re-randomising the number when the difficulty is chosen
//3. Adding a complexity layer - adding basic statistics (attempts, wins, loss)

//Importing libraries
#include <iostream>
#include <random>
#include "random_number.h"

static void DisplayStatistics(int &totalAttempts, int &win, int &loss) {

    // Generating the statistics
    std::cout << "------------------------------Generating Statistics--------------------------------- \n";
    std::cout << "Total Attempts: " << totalAttempts << '\n';
    std::cout << "Wins: " << win << '\n';
    std::cout << "Losses: " << loss << '\n';

    if (totalAttempts > 0) {
        double win_percentage = static_cast<double>(win) / totalAttempts * 100;
        std::cout << "Win Percentage: " << win_percentage << "%" << '\n';
    }
    else {
        std::cout << "No games played yet." << '\n';
    }

}

int main()
{
    // Properly seed the RNG
    std::random_device rd;
    std::mt19937 rng(rd());
    
    // Calling the guessing game function
    std::cout << "Would you like to play the guessing game (y=yes and n=no)? ";
    char start{};
    std::cin >> start;

    // Starting the game
    auto [totalAttempts,win,loss] = guessing_game(start, rng);

    // Calling the statistics function
    DisplayStatistics(totalAttempts, win, loss);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
