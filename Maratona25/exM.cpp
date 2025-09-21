#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <vector>

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

    string s_line;
    getline(cin, s_line);
    stringstream ss2(s_line);

    vector<int> s_numbers;
    int num2;
    while(ss2>>num2){
        s_numbers.push_back(num2);
    }

    cout<<n<<" "<<k<<endl;
    for(int i=0; i<s_numbers.size();i++){
        cout<<s_numbers[i]<<" ";
    }
    vector<int> numbers;
    return 0;
}
