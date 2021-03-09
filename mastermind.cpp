#include "mastermind.h"

using namespace std;

Mastermind::Mastermind() {
    cout << "Please enter a key for your partner to deduce!" << endl << endl;
    key = createKey();
    playingboard.resize(10);

    cout << string(500, '\n');

    cout << "The key has been set." << endl
         << "Please enter any character to indicate that your partner has been "
            "given the computer."
         << endl
         << endl;
    char reader;
    cin >> reader;

    cout << string(500, '\n');

    int roundNumber = 0;
    bool correctDeduction = false;

    while (roundNumber < 10 && !correctDeduction) {
        correctDeduction = playRound(roundNumber);
        ++roundNumber;
        cout << string(500, '\n');
    }

    cout << "This is the final board : " << endl << endl;

    printBoard();

    if (roundNumber >= 10) {
        cout << "You lose, Better luck next time!" << endl
             << "Thank you for playing!" << endl
             << endl
             << endl
             << endl;
    } else {
        cout << "You Win - Great job deducing the key!" << endl
             << "Thank you for playing!" << endl
             << endl
             << endl
             << endl;
    }
}

bool Mastermind::checkInSet(char a) {
    if (CHARACTER_LIST.find(a) != CHARACTER_LIST.end()) {
        return false;
    } else {
        cout << "That is invalid input, please try again." << endl;
        return true;
    }
}

Attempt Mastermind::createKey() {
    cout << "To enter a key, you must enter four characters." << endl
         << "Each character in the key can only be one of these 6 characters:"
         << endl
         << endl
         << "\t'A', 'B', 'C', 'D', 'E', or 'F'." << endl
         << endl
         << "Repetition is allowed!" << endl
         << endl;

    char a = ' ', b = ' ', c = ' ', d = ' ';
    bool incorrectInput = true;

    while (incorrectInput) {
        cout << "Character 1 in the Key: ";
        cin >> a;

        incorrectInput = checkInSet(a);
    }

    incorrectInput = true;

    while (incorrectInput) {
        cout << "Character 2 in the Key: ";
        cin >> b;

        incorrectInput = checkInSet(b);
    }

    incorrectInput = true;

    while (incorrectInput) {
        cout << "Character 3 in the Key: ";
        cin >> c;

        incorrectInput = checkInSet(c);
    }

    incorrectInput = true;

    while (incorrectInput) {
        cout << "Character 4 in the Key: ";
        cin >> d;

        incorrectInput = checkInSet(d);
    }

    return Attempt(a, b, c, d);
}

void Mastermind::printCorrect(size_t index) {
    const Attempt &check = playingboard[index];
    int totallyCorrect = 0;
    int correctCharacter = 0;

    vector<bool> countedOff;
    for (int i = 0; i < 4; ++i) {
        countedOff.push_back(false);
    }

    if (check.a == key.a) {
        ++totallyCorrect;
        ++correctCharacter;
        countedOff[0] = true;
    } else if (check.a == key.b && !countedOff[1]) {
        ++correctCharacter;
        countedOff[1] = true;
    } else if (check.a == key.c && !countedOff[2]) {
        ++correctCharacter;
        countedOff[2] = true;
    } else if (check.a == key.d && !countedOff[3]) {
        ++correctCharacter;
        countedOff[3] = true;
    }

    if (check.b == key.b) {
        ++totallyCorrect;
        ++correctCharacter;
        countedOff[2] = true;
    } else if (check.b == key.a && !countedOff[0]) {
        ++correctCharacter;
        countedOff[1] = true;
    } else if (check.b == key.c && !countedOff[2]) {
        ++correctCharacter;
        countedOff[2] = true;
    } else if (check.b == key.d && !countedOff[3]) {
        ++correctCharacter;
        countedOff[3] = true;
    }

    if (check.c == key.c) {
        ++totallyCorrect;
        ++correctCharacter;
        countedOff[2] = true;
    } else if (check.c == key.a && !countedOff[0]) {
        ++correctCharacter;
        countedOff[1] = true;
    } else if (check.c == key.b && !countedOff[1]) {
        ++correctCharacter;
        countedOff[2] = true;
    } else if (check.c == key.d && !countedOff[3]) {
        ++correctCharacter;
        countedOff[3] = true;
    }

    if (check.d == key.d) {
        ++totallyCorrect;
        ++correctCharacter;
        countedOff[3] = true;
    } else if (check.d == key.a && !countedOff[0]) {
        ++correctCharacter;
        countedOff[1] = true;
    } else if (check.d == key.b && !countedOff[1]) {
        ++correctCharacter;
        countedOff[2] = true;
    } else if (check.d == key.c && !countedOff[2]) {
        ++correctCharacter;
        countedOff[3] = true;
    }

    cout << "There are " << correctCharacter << " correct character(s), "
         << totallyCorrect;
    if (totallyCorrect == 1) {
        cout << " of which is in the correct position." << endl << endl;
    } else {
        cout << " of which are in the correct position." << endl << endl;
    }

    if (totallyCorrect > totalCorrect) {
        totalCorrect = totallyCorrect;
    }
}

void Mastermind::printBoard() {
    cout << "- - - - - - - - - - -" << endl << endl;
    for (size_t i = 0; i < playingboard.size(); ++i) {
        cout << i << ". //  " << playingboard[i].a << "  " << playingboard[i].b
             << "  " << playingboard[i].c << "  " << playingboard[i].d << "  "
             << "//   ";
        if (playingboard[i].a != '_') {
            printCorrect(i);
        } else {
            cout << endl << endl;
        }
    }
    cout << "- - - - - - - - - - -" << endl;
}

bool Mastermind::playRound(int roundNumber) {
    cout << endl
         << endl
         << "What key would you like to try now?" << endl
         << endl
         << endl;

    printBoard();

    cout << endl << endl;

    playingboard[(size_t)roundNumber] = createKey();


    if (totalCorrect == 4) {
        return true;
    } else {
        return false;
    }
}

int main() {
    cout << string(500, '\n');

    while (true) {
        cout << "Please enter either \"yes\" to play a new game or \"no\" to "
                "quit."
             << endl;
        string response;
        cin >> response;
        if (response == "yes") {
            cout << string(500, '\n');
            Mastermind game;
        } else if (response == "no") {
            cout << "Thank you for playing the game!" << endl;
            return 0;
        } else {
            cout << "That was an invalid response, please try again." << endl;
        }
    }
}