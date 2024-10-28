#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Player {
private:
    string name;
    int score;

public:
    // Constructor to initialize a player's name and score
    Player(const string& playerName, int playerScore) : name(playerName), score(playerScore) {}

    // Accessor for name
    string getName() const {
        return name;
    }

    // Accessor for score
    int getScore() const {
        return score;
    }
};

// Function prototypes
void addPlayer(vector<Player>& players);
void printPlayers(const vector<Player>& players);
void findPlayerScore(const vector<Player>& players);
void removePlayer(vector<Player>& players);

int main() {
    vector<Player> players;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add a new player and score\n";
        cout << "2. Print all players and scores\n";
        cout << "3. Find a player's score\n";
        cout << "4. Remove a player\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addPlayer(players);
                break;
            case 2:
                printPlayers(players);
                break;
            case 3:
                findPlayerScore(players);
                break;
            case 4:
                removePlayer(players);
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}

// Function to add a new player
void addPlayer(vector<Player>& players) {
    if (players.size() >= 10) {
        cout << "Player list is full. Cannot add more players." << endl;
        return;
    }

    string name;
    int score;
    cout << "Enter player name: ";
    cin >> name;
    cout << "Enter player score: ";
    cin >> score;

    players.emplace_back(name, score);
    cout << "Player added successfully." << endl;
}

// Function to print all players and their scores
void printPlayers(const vector<Player>& players) {
    if (players.empty()) {
        cout << "No players in the list." << endl;
        return;
    }

    cout << "\nPlayers and scores:\n";
    for (const auto& player : players) {
        cout << "Name: " << player.getName() << ", Score: " << player.getScore() << endl;
    }
}

// Function to find and display a player's score
void findPlayerScore(const vector<Player>& players) {
    string name;
    cout << "Enter player name to find the score: ";
    cin >> name;

    for (const auto& player : players) {
        if (player.getName() == name) {
            cout << "Score of " << name << " is " << player.getScore() << endl;
            return;
        }
    }
    cout << "Player not found." << endl;
}

// Function to remove a player from the list
void removePlayer(vector<Player>& players) {
    string name;
    cout << "Enter player name to remove: ";
    cin >> name;

    for (auto it = players.begin(); it != players.end(); ++it) {
        if (it->getName() == name) {
            players.erase(it);
            cout << "Player " << name << " removed successfully." << endl;
            return;
        }
    }
    cout << "Player not found." << endl;
}
