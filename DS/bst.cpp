#include<iostream>
struct BST{
    int data;
    BST* left;
    BST* right;
};

BST* getNewNode(int x){
    BST* node = new BST;
    node->data = x;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

BST* Insert(BST* root,int x){ 
    if(root == nullptr){
        root = getNewNode(x);
        return root;
    }
    else if(x <= root->left->data){
        root->left = Insert(root->left,x);
    }
    else{
        root->right = Insert(root->right,x);
    }
    return root;
}

bool Search(BST* root,int x){
    if(root == nullptr ) return false;
    if(root->data == x){
        return true;
    }
    else if(x <= root->data){
        return Search(root->left,x);
    }
    else{
        return Search(root->right,x);
    }
}
int main(){
    BST* root = nullptr;
    root = Insert(root,3);
    std::cout<<Search(root,3);
}
