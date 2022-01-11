// Copyright (c) 2022 Alexander Matheson All rights reserved.

// Created by: Alexander Matheson
// Created on: Jan 11, 2022
// This program gets the user to enter a number of sides.
// It then simulates two die with that number of sides
// and rolls then until it gets doubles.
#include <iostream>
#include <random>

// declare variables
int loopCounter = 0;
int sides;


// This function gets the user's input
void userInput() {
    // declare local variable
    std::string sidesString;

    // get the user number as a string
    std::cout << "Enter the number of sides each die should have: ";
    std::getline(std::cin, sidesString);

    // error checking
    try {
        sides = std::stoi(sidesString);
        if (sides <= 0) {
            std::cout << "Number must be positive.\n";
            return userInput();
        }
    } catch (std::invalid_argument) {
        std::cout << "Invalid input.\n";
        return userInput();
    }
}


// The Die Is Cast
// This function rolls the die
void aleaIactaEst() {
    // declare local variables
    int rollA;
    int rollB;

    // loop
    do {
        // set rollA
        std::random_device rseed;
        std::mt19937 rgen(rseed());
        std::uniform_int_distribution<int> idist(1, sides);
        rollA = idist(rgen);

        // set rollB
        std::uniform_int_distribution<int> (1, sides);
        rollB = idist(rgen);

        // display rolls
        std::cout << rollA << " and " << rollB << std::endl;
        loopCounter = loopCounter + 1;
    } while (rollA != rollB);

    std::cout << "It took " << loopCounter << " tries to get doubles";
}


int main() {
    // call functions
    userInput();
    aleaIactaEst();
}
