//12_트리 필수3: 5639.cpp
#include <iostream>
#include <cstdlib>

using namespace std;

class Node 
{
public:
    int num;
    Node* left;
    Node* right;

    Node(int n) : num(n), left(nullptr), right(nullptr) {}

    Node(int n, Node* l, Node* r) : num(n), left(l), right(r) {}

    void insert(int n) 
{
        if (n < this->num) 
        {
            if (this->left == nullptr){
                this->left = new Node(n);
            }  
            else{
                this->left->insert(n);
            }  
        } 
        else 
        {
            if (this->right == nullptr){
                this->right = new Node(n);
            }  
            else{
                this->right->insert(n);
            }  
        }
    }
};

void postOrder(Node* node) 
{
    if (node == nullptr){
        return;
    }  

    postOrder(node->left);
    postOrder(node->right);
    cout << node->num << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string input;
    getline(cin, input);

    Node* root = new Node(stoi(input));

    while (true) 
    {
        getline(cin, input);
        if (input.empty()){
            break;
        }  
        root->insert(stoi(input));
    }

    postOrder(root);

    return 0;
}
