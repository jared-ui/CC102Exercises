#include <iostream>
#include <fstream>
using namespace std; 

bool PrimeNum(int n){
    if (n <= 1) return false;
    
    for(int i = 2; i * i <= n; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    
    ifstream inputFile("nums.txt");
    ofstream outputFile("result.txt");
    
    int num;
    int count = 0;
    
    if(!inputFile){
        cout << "input File not opened!";
        return 1;
    }
    
    if(!outputFile){
        cout << "output File not opened!";
        return 1;
    }
    
    while(inputFile >> num){
        if(PrimeNum(num)){
            count++;
        }        
    }
    
    cout << "Prime numbers: " << count << endl;
    outputFile << "Prime numbers: " << count << endl;
    
    inputFile.close();
    outputFile.close();
    
    return 0;
}