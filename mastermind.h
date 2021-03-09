#include <algorithm>
#include <cassert>
#include <deque>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

struct Attempt {
    char a;
    char b;
    char c;
    char d;

    Attempt () : a('_'), b('_'), c('_'), d('_') {}

    Attempt(char a_in, char b_in, char c_in, char d_in) 
        : a(a_in), b(b_in), c(c_in), d(d_in) {}
};

class Mastermind {
	int totalCorrect;
    Attempt key;
    std::vector<Attempt> playingboard;
    const std::unordered_set<char> CHARACTER_LIST = {'A', 'B', 'C', 'D', 'E', 'F'};
    bool checkInSet(char a);
    Attempt createKey();
    void printCorrect(size_t index);
    void printBoard();
    bool playRound(int roundNumber);

public:
    Mastermind ();
};