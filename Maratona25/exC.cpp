#include <iostream>
#include <string.h>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    int qntd;
    cin >> qntd;
    cin.ignore();

    string line; 
    getline(cin, line); // Lê a linha inteira, incluindo os espaços

    stringstream ss(line); // Cria um stream a partir da linha lida
    vector<int> phrase; // Vetor para armazenar os números

    int num;
    while(ss>>num){// Lê cada número do stream
        phrase.push_back(num);
    }
    
    //Agora que temos os números em um vetor, podemos iterar sobre ele
    int total;
    int count;
    for (int i = qntd; i>=0; i--){
        if (phrase[i]){
            total = total + pow(2, count);
        }
    }

    /**for(auto character : frase){
        cout << character;
        cout << endl;
    }**/

    return 0;
}