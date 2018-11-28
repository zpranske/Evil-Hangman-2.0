#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

void loadDict(map<int,set<string>>& dict, ifstream& in){
    string temp;
    while(in >> temp){
        dict[temp.length()].insert(temp);
    }
}

template <typename T>
void printDict(map<T,set<string>>& dict, ostream& out) {
    for (auto i = dict.begin(); i != dict.end(); i++) {
        for ( auto j = i->second.begin(); j != i->second.end(); j++ ){
            out << *j << endl;
        }
    }
}

void printDict(map<int,set<string>>& dict, int n, ostream& out) {
    for (map<int,set<string>>::iterator i = dict.begin(); i != dict.end(); i++) {
        if (i->first == n) {
            for ( set<string>::iterator itr = i->second.begin(); itr != i->second.end(); ++itr ){
                out << *itr << endl;
            }
        }
    }
}

void getDictInfo(map<int,set<string>>& dict, int& min, int& max) {
    map<int,set<string>>::iterator i;
    i = dict.begin();
    min = i->first;
    i = --dict.end();
    max = i->first;
}

void loadSubdict(map<int,set<string>>& src, set<string>& dest, int n) {
    for (auto i = src.begin(); i != src.end(); i++) {
        if (i->first == n) {
            for ( auto j = i->second.begin(); j != i->second.end(); j++ ){
                dest.insert(*j);
            }
        }
    }
}

void printSet(set<string> s, ostream& out) {
    for (auto i = s.begin(); i != s.end(); i++) {
        out << *i << " ";
    }
}

void makeguess(set<string> src, char guess, vector<char> guesslist) {
    int wordLength = src.begin()->length();
    map<int,set<string>> partitions;

    for (auto i = src.begin(); i != src.end(); i++) {
        int pos;

    }
}

int main() {
    ifstream in;
    in.open("dict.txt");

    map<int,set<string>> dict;
    loadDict(dict, in);
    printDict(dict, 21, cout);

    int minSize = 0, maxSize = 0;
    getDictInfo(dict, minSize, maxSize);
    cout << minSize << " " << maxSize << endl;

    int wordLength = 0;
    bool valid = false;
    cout << "Pick a word length: \n";
    while (!valid) {
        cin >> wordLength;
        if (wordLength >= minSize && wordLength <= maxSize) valid = true;
        else {
            cout << "No words of that length exist. Please choose a length between ";
            cout << minSize << " and " << maxSize << ":\n";
        }
    }

    set<string> subdict1;
    loadSubdict(dict, subdict1, wordLength);
    printSet(subdict1, cout);
    cout << endl << endl;

    vector<char> guesses;
    int numGuesses = 0;
    char c = '\0';
    cout << "Guess a letter: ";
    while (!(islower(c))) {
        cin >> c;
        if (isupper(c))
            c = tolower(c);
        if (!islower(c))
            cout << "Please enter a letter, not just some random character you moron\n";
    }
    guesses.push_back(c);
    numGuesses++;

    makeguess(subdict1, c, guesses);









    return 0;
}