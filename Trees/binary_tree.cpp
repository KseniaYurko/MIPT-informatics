#include <iostream>

using namespace std;

typedef struct tree_elem {
    int value;
    struct tree_elem* left;
    struct tree_elem* right;
} tree_elem;

tree_elem* create_tree_elem(int i){
    tree_elem* elem = new tree_elem;
    elem -> value = i;
    elem -> left = NULL;
    elem -> right = NULL;
    return elem;
}

void insert_tree_elem(tree_elem* root, tree_elem* elem){
    if(elem -> value < root -> value){
        //left
        if(root -> left == NULL){
            //insesrt value if LEFT undertree is NULL
            root -> left = elem;
        }
        else{
            //LEFT not NULL. recursive insert
            insert_tree_elem(root -> left, elem);  
        }
    }
    else{
        //right
        if(root -> right == NULL){
            //insesrt value if RIGHT undertree is NULL
            root -> right = elem;
        }
        else{
            //RIGHT not NULL. recursive insert
            insert_tree_elem(root -> right, elem);  
        }
    }
}

void print_tree(tree_elem* cur_elem){
    if(cur_elem -> left != NULL){
        print_tree(cur_elem -> left);
    }
    cout << "value = " << cur_elem -> value << endl;
    if(cur_elem -> right != NULL){
        print_tree(cur_elem -> right);
    }
    cout << "value = " << cur_elem -> value << endl;
    
}



int main(){

    int a[7] = {3, 1, -5, 42, 2, -6, 8};
    tree_elem* root = create_tree_elem(0);
    for(int i = 0; i < 7; i++){
        tree_elem* el = create_tree_elem(a[i]);
        insert_tree_elem(root, el);
    }

    cout << "tree: " << endl;
    print_tree(root);



    return 0;
}
