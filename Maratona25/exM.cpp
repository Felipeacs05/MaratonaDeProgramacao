#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

typedef struct no{
    int content;
    struct no *left;
    struct no *right;
}no;

int main(){
    string f_line;
    getline(cin, f_line);

    stringstream ss(f_line);
    vector<int> f_numbers;

    int num1;
    while(ss>>num1){
        f_numbers.push_back(num1);
    }

    int n, k;
    n = f_numbers[0];
    k = f_numbers[1];

    cin.ignore();

    string s_line;
    getline(cinm, s_line);

    int n, k;
    vector<int> numbers;
    return 0;
}
