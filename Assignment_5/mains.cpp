#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    fstream file;

    file.open("original.txt", ios::out);
    if(file.is_open()) {
        file << "One\n";
        file << "Two\n";
        file << "Three\n";
        file << "Four\n";
        file << "Five\n";
        file << "Six\n";
        file.close();
        cout << "Write successful!\n";
    }
    else{
        cout << "Failed to open original.txt\n";
    }

    file.open("original.txt", ios::in);
    vector<string> words;
    if(file.is_open()) {
        string line;
        while (getline(file, line)) {
            words.push_back(line);
        }
        file.close();
    }

    else{
        cout << "Failed to open original.txt\n";
    }

    sort(words.begin(), words.end());

    file.open("sorted.txt", ios::out);
    if (file.is_open()) {
        for (int i = 0; i < words.size(); i++) {
            file << words[i] << "\n";
        }
        file.close();
        cout << "Sort successful!\n";
    }
    else{
        cout << "Failed to open sorted.txt\n";
    }

    return 0;
}