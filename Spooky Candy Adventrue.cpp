#include <iostream>
#include <string>
#include <random>

using namespace std;

bool chooseRoom(int &playerLive, int &playerCandy) {
    const int numRooms = 3;
    string rooms[numRooms] = {"Living Room", "Kitchen", "Basement"};

    cout << "Choose which room you will explore (enter 0 to quit):\n";
    for (int i = 0; i < numRooms; ++i) {
        cout << i + 1 << ". " << rooms[i] << endl;
    }

    int choice;
    cout << "Enter the room number (1, 2, or 3) or 0 to quit: ";
    cin >> choice;

    if (choice == 0) {
        return false;
    } else if (choice >= 1 && choice <= numRooms) {
        cout << "You chose to explore the " << rooms[choice - 1] << "." << endl;

        // random event for finding candy, encountering a ghost, finding a potion, or finding nothing
        int event = rand() % 4;  // Generates 0, 1, 2, or 3

        if (event == 0) {
            cout << "You found a hidden stash of candy! +2 candies." << endl;
            playerCandy += 2;
        } else if (event == 1) {
            cout << "Oh no! A ghost appears! You lose 1 life." << endl;
            playerLive--;
        } else if (event == 2) {
            cout << "You found a magic potion! You gain 1 life." << endl;
            playerLive++;
        } else {
            cout << "The room is empty. Nothing here." << endl;
        }

        cout << "Current candies: " << playerCandy << endl;
        cout << "Current lives: " << playerLive << endl;

    } else {
        cout << "Invalid choice. Please enter a number between 0 and " << numRooms << "." << endl;
    }
    return true;  // Continue the game
}

int main() {
    //srand(static_cast<unsigned int>(time(0)));  // Seed random number generator
    int MIN = 1;
    int MAX = 4;
    random_device engine;
uniform_int_distribution<int> diceValue(MIN, MAX);

    int playerLive = 3;
    int playerCandy = 0;

    cout << "You have 3 lives." << endl;

    do {
        if (!chooseRoom(playerLive, playerCandy)) {
            cout << "Game ended by the player." << endl;
            break;
        }

    } while (playerLive > 0);

    if (playerLive == 0) {
        cout << "Better luck next time!" << endl;
    }

    return 0;
}
