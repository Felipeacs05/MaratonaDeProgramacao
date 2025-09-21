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

no *insert(no *root, int value){
    if(root=NULL){
        no *new = (no*) malloc(sizeof(no));
        new->content = value;
        new->left = NULL;
        new->right = NULL;
        new->height = 0;
        return new;
    }else{
        if(value<root->content){
            root->left = inser(root->left, value);
        }
        if(value > root->content){
            root->right = insert(root->right, value);
        }
    }

    root = balance(root);
    return root;
}

int main(){
    no *root = NULL;

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
        insert(no, s_numbers[i]);
    }
    vector<int> numbers;
    return 0;
}
