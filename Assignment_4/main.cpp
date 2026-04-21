#include <iostream>
#include <fstream>
using namespace std;

int main() {

    fstream file;
    fstream copyFile;

    file.open("color.txt", ios::out);
    if(file.is_open()) {
        file << "Red\n";
        file << "Blue\n";
        file << "Green\n";
        file << "Yellow\n";
        file << "Purple\n";
        file.close();
        cout << "Write successful!\n";
    }
    else{
        cout << "Failed to open color.txt\n";
    }

    file.open("color.txt", ios::in);
    copyFile.open("color_copy.txt", ios::out);

    if(file.is_open() && copyFile.is_open()) {
        string line;
        while (getline(file, line)) {
            copyFile << line << "\n";
        }
        file.close();
        copyFile.close();
        cout << "Copy successful!\n";
    }
    
    else{
        cout << "Failed to open file.\n";
    }

    return 0;
}