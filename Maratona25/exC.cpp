#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
using namespace std;

int main(){
    int qntd;
    cin >> qntd;
    cin.ignore();

    string line; 
    getline(cin, line); // Lê a linha inteira, incluindo os espaços

    stringstream ss(line); // Cria um stream a partir da linha lida
    vector<int> phrase(100); // Vetor para armazenar os números

    int num;
    while(ss>>num){// Lê cada número do stream
        phrase.push_back(num);
    }

    for(int i=0; i<size(phrase); i++){
        cout << phrase[i] << " ";
    }
    /**for(auto character : frase){
        cout << character;
        cout << endl;
    }**/

    return 0;
}