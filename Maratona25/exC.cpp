#include <iostream>
#include <string.h>
using namespace std;

int main(){
    int qntd;
    char frase[100];

    cout<<"Digite os baguhos:";
    gets(frase);
    cout<<frase[0];
    cout<<"Esta frase tem" << strlen(frase)<< " caracteres" <<endl;
    for(auto character : frase){
        cout << character;
        cout << endl;
    }
    

    return 0;
}