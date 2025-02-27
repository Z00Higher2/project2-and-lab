#include <iostream>
#include "MemoryGame.hpp"
#include <cstdlib> 
#include <time.h>

using namespace std;

MemoryGame::MemoryGame() {
    numPairs = 3;
    numSlots = 8;
    values = new string[numSlots];
    bShown = new bool[numSlots];

    // Generate three random integers in [0, 999]
    int random1 = rand() % 1000;
    int random2 = rand() % 1000;
    int random3 = rand() % 1000;

    // Place the random integers in pairs in the values array
    for (int i = 0; i < numSlots; i += 2) {
        if (i < 2) {
            values[i] = to_string(random1);
            values[i + 1] = to_string(random1);
            bShown[i] = false;
            bShown[i + 1] = false;
        } else if (i < 4) {
            values[i] = to_string(random2);
            values[i + 1] = to_string(random2);
            bShown[i] = false;
            bShown[i + 1] = false;
        } else {
            values[i] = to_string(random3);
            values[i + 1] = to_string(random3);
            bShown[i] = false;
            bShown[i + 1] = false;
        }
    }

    // Set the rest of the elements of values to be empty strings
    for (int i = 6; i < numSlots; i++) {
        values[i] = "";
        bShown[i] = false;
    }
}

MemoryGame::MemoryGame(int numPairs, int numSlots) {
    if (numPairs <= 0 || numSlots <= 0 || numSlots < 2 * numPairs) {
        // Default values if parameters are invalid
        numPairs = 3;
        numSlots = 8;
    }

    this->numPairs = numPairs;
    this->numSlots = numSlots;
    values = new string[numSlots];
    bShown = new bool[numSlots];

    // Generate numPairs random integers in [0, 999]
    for (int i = 0; i < numPairs; i++) {
        int random = rand() % 1000;
        for (int j = 0; j < 2; j++) {
            values[i * 2 + j] = to_string(random);
            bShown[i * 2 + j] = false;
        }
    }

    // Set the rest of the elements of values to be empty strings
    for (int i = numPairs * 2; i < numSlots; i++) {
        values[i] = "";
        bShown[i] = false;
    }
}

MemoryGame::MemoryGame(string* words, int size, int numSlots) {
    // Adjust numSlots if necessary
    if (size <= 0 || numSlots <= 0 || numSlots < 2 * size) {
        numSlots = 2 * size;
    }

    // Set data members numPairs and numSlots
    numPairs = size;
    this->numSlots = numSlots;

    // Allocate dynamic memory for values and bShown
    values = new string[numSlots];
    bShown = new bool[numSlots];

    // Initialize values with words and empty strings
    int wordIndex = 0;
    for (int i = 0; i < numSlots; i++) {
        if (wordIndex < size) {
            values[i] = words[wordIndex];
            values[i + 1] = words[wordIndex]; // Place each word in pairs
            i++; // Skip next iteration
        } else {
            values[i] = ""; // Fill the rest with empty strings
        }
        bShown[i] = false; // Initialize bShown
        wordIndex++;
    }
}

MemoryGame::~MemoryGame() {
    delete[] values;
    delete[] bShown;

    // Set values and bShown to nullptr after deletion
    values = nullptr;
    bShown = nullptr;
}

void MemoryGame::play()
{

}

void MemoryGame::display() const
{

}

void MemoryGame::randomize()
{

}

int MemoryGame:: input() const
{

}

