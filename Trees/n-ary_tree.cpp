#include <iostream>
#include <vector>

using namespace std;

//functions
struct tree_node* get_new_node(int data);
void add_child(tree_node*, int data);
void print_tree(tree_node* root);

//struct
struct tree_node{
    int data;
    vector <tree_node*> children;
};

int main(){
    tree_node* root;

    root = get_new_node(3);

    add_child(root, 2);
    add_child(root, 1);

    add_child(root -> children[0], 5);
    add_child(root -> children[0], 6);
    add_child(root -> children[0], 7);

    add_child(root -> children[1], 5);
    add_child(root -> children[1], 6);
    add_child(root -> children[1], 7);

    print_tree(root);

    return 0;
}

//funcions to create a new node
tree_node* get_new_node(int data){
    tree_node* new_node = new tree_node();
    new_node -> data = data;
    return new_node;
}

//funcions add child to node
void add_child(tree_node* node, int data){
    //create a new node
    tree_node* new_node = get_new_node(data);
    node -> children.push_back(new_node);
}

void print_tree(tree_node* root){
    cout << root -> data;
    cout << root -> children[0] -> data;
    cout << root -> children[1] -> data;
    cout << root -> children[0] -> children[0] -> data;
    cout << root -> children[0] -> children[1] -> data;
    cout << root -> children[0] -> children[2] -> data;
    cout << root -> children[1] -> children[0] -> data;
    cout << root -> children[1] -> children[1] -> data;
    cout << root -> children[1] -> children[2] -> data;
    
}


