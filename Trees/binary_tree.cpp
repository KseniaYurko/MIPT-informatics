#include <iostream>
#include <vector>

#include <string>
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
#include <tuple>
#include <stdexcept>
#include <memory>
#ifdef _WIN32
    #include <windows.h>
#else
    #include <locale.h>
#endif

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

//DISPLAY TREE ------------------------------------------------------------------------------------------------------------------//
#define LN { std::cout << __LINE__ << std::endl; }
#define DEB(x) { std::cout << #x << "=(" << (x) << ") "; }
static std::string ch_hor = "\u2500" /*─*/, ch_ver = "\u2502" /*│*/, ch_ddia = "\u250C" /*┌*/, ch_rddia = "\u2510" /*┐*/, ch_udia = "\u2514" /*└*/, ch_ver_hor = "\u251C\u2500" /*├─*/, ch_udia_hor = "\u2514\u2500" /*└─*/, ch_ddia_hor = "\u250C\u2500" /*┌─*/, ch_ver_spa = "\u2502 " /*│ */;

void dump4(tree_elem const * node, bool high = true, 
            vector<string> const & lpref = vector<string>(),
            vector<string> const & cpref = vector<string>(), 
            vector<string> const & rpref = vector<string>(), 
            bool root = true, 
            bool left = true, 
            shared_ptr<vector<vector<string>>> lines = nullptr){
    
    if (!node) return;

    typedef vector<string> VS;

    auto VSCat = [](VS const & a, VS const & b){ auto r = a; r.insert(r.end(), b.begin(), b.end()); return r; };

    if (root) lines = make_shared<vector<VS>>();
    if (node->left);

    dump4(node->left, high, VSCat(lpref, high ? VS({" ", " "}): VS({" "})), VSCat(lpref, high ? VS({ch_ddia, ch_ver}) : VS({ch_ddia})), VSCat(lpref, high ? VS({ch_hor, " "}) : VS({ch_hor})), false, true, lines);
    auto sval = to_string(node->value);
    size_t sm = left || sval.empty() ? sval.size() / 2 : ((sval.size() + 1) / 2 - 1);
    for (size_t i = 0; i < sval.size(); ++i)
        lines->push_back(VSCat(i < sm ? lpref : i == sm ? cpref : rpref, {string(1, sval[i])}));
    if (node->right)
        dump4(node->right, high, VSCat(rpref, high ? VS({ch_hor, " "}) : VS({ch_hor})), VSCat(rpref, high ? VS({ch_rddia, ch_ver}) : VS({ch_rddia})), VSCat(rpref, high ? VS({" ", " "}) : VS({" "})), false, false, lines);
    if (root) {
        VS out;
        for (size_t l = 0;;++l) {
            bool last = true;
            string line;
            for (size_t i = 0; i < lines->size(); ++i)
                if (l < (*lines).at(i).size()) {
                    line += lines->at(i)[l];
                    last = false;
                } else line += " ";
            if (last) break;
            out.push_back(line);
        }
        for (size_t i = 0; i < out.size(); ++i)
            cout << out[i] << endl;
    }
}
//-------------------------------------------------------------------------------------------------------------------------------//


int main(){

    int a[7] = {3, 1, -5, 42, 2, -6, 8};
    tree_elem* root = create_tree_elem(0);
    for(int i = 0; i < 7; i++){
        tree_elem* el = create_tree_elem(a[i]);
        insert_tree_elem(root, el);
    }

    cout << "tree: " << endl;
    dump4(root, true);



    return 0;
}
