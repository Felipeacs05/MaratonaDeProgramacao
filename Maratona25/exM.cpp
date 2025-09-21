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
    int height;
}no;


//Altura 
int height(no *root){ //500
  int heightAux;
  if (root == NULL){
    return -1;
  }else{
    int lef = height(root->left);//-1
    int rig = height(root->right);//-1
    if(lef > rig){
      return lef + 1;
    }
    return rig + 1;
  }
}


//Fator de Balanceamento
int balancingFactor(no *node){
  if(node){
    return (height(node->right) - height(node->left));
  }
  return 0;
}

// Rotação à direita
no* rightRotation(no* y){
    no* x = y->left;
    no* T2 = x->right;

    x->right = y;
    y->left = T2;

    // Atualiza alturas
    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;
}

// Rotação à esquerda
no* leftRotation(no* x){
    no* y = x->right;
    no* T2 = y->left;

    y->left = x;
    x->right = T2;

    // Atualiza alturas
    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}


//Rotação Dupla - DireitaEsquerda
no *rightLeftRotation(no *r){
  r->right = rightRotation(r->right);
  return leftRotation(r);
}

//Rotação Dupla - EsquerdaDireita
no *leftRightRotation(no *r){
  r->left = leftRotation(r->left);
  return rightRotation(r);
}

//Balancear a arvore
no *balance(no *root){
  int bf = balancingFactor(root);
  if(bf < -1 && balancingFactor(root->right) <= 0){
    root = rightRotation(root);
  }
  else if(bf > 1 && balancingFactor(root->left) >= 0){
    root = leftRotation(root);
  }
  else if(bf > 1 && balancingFactor(root->left) < 0){
    root = leftRightRotation(root);
  }
  else if(bf < -1 && balancingFactor(root->right) > 0){
    root = rightLeftRotation(root);
  }

  return root;
}

//Imprimir Arvore PreOrder
void printTreePreOrder(no *root, int value){
  if(root != NULL){
    root->content += value;
    cout<<root->content<<" ";
    value--;
    printTreePreOrder(root->left, value);
  }
}

//Inserir elemento na árvore
no *insert(no *root, int value){
    if(root==NULL){
        no *newNode = new no();
        newNode->content = value;
        newNode->left = NULL;
        newNode->right = NULL;
        newNode->height = 0;
        return newNode;
    }else{
        if(value<=root->content){
            root->left = insert(root->left, value);
        }
        if(value > root->content){
            root->right = insert(root->right, value);
        }
    }

    root->height = 1 + max(height(root->left), height(root->right));

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
        root = insert(root, s_numbers[i]);
    }

    printTreePreOrder(root, k);
    vector<int> numbers;
    return 0;
}
