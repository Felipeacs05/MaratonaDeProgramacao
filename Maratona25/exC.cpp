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
    int total = 0;
    int count = 0;
    for (int i = qntd; i>=0; i--){
        if (phrase[i]==1){
            total += pow(2, count);
        }
        count++;
    }

    //Agora temos o valor de binário em decimal, vamos realizar o processo restante
    int contador = 0;
    int ref;

    //Loop que verifica as duas situações específicas do problema C
    while (true){
        if(total!=1){
            if(total%2==0){
                total = total /2;
                contador++;
            }else{
                ref = total;
                total = total*2 + 1;
                total = (total*2 + 1)^total;
            }
        }else{
            break;
        }
    }

    printf("%d", contador);
    
    return 0;
}