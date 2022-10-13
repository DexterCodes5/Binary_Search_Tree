#include <iostream>
#include <windows.h>
struct BSTNode {
    int m_key;
    BSTNode *m_left;
    BSTNode *m_right;
    
    BSTNode(int d) :m_key{d}, m_left{nullptr}, m_right{nullptr} {}
};

BSTNode *insert(BSTNode *r, int x) {
    
    // base case
    if (r == nullptr) {
        return new BSTNode(x);
    }
    
    // rec case
    if (x < r->m_key) {
        r->m_left = insert(r->m_left,x);
    }
    else {
        r->m_right = insert(r->m_right,x);
    }
    return r;
}

void printBT(const std::string& px, const BSTNode* r, bool left)
{
    if(r != nullptr )
    {
        std::cout << px;

        std::cout << (left ? "|-->" : "|-->" );

        std::cout << r->m_key << std::endl;

        printBT(px + (left ? "|   " : "    "), r->m_left, true);
        printBT(px + (left ? "|   " : "    "), r->m_right, false);
    }
}

BSTNode *findMin(BSTNode *r) {
    
    while (r->m_left != nullptr) {
        r = r->m_left;
    }
    return r;
}

BSTNode *delete_node(BSTNode *r, int x) {
    if (r == nullptr) {
        return nullptr;
    }
    else if (r->m_key > x) {
        r->m_left = delete_node(r->m_left,x);
    }
    else if (r->m_key < x) {
        r->m_right = delete_node(r->m_right,x);
    }
    else {
        if ((r->m_left == nullptr) && (r->m_right == nullptr)) {
            delete r;
            r = nullptr;
        }
        
        else if (r->m_left == nullptr) {
            BSTNode *temp = r;
            r = r->m_right;
            delete temp;
        }
        else if (r->m_right == nullptr) {
            BSTNode *temp = r;
            r = r->m_left;
            delete temp;
        }
        else {
            BSTNode *temp = findMin(r->m_right);
            r->m_key = temp->m_key;
            r->m_right = delete_node(r->m_right,temp->m_key);
        }
    }
    return r;
}

int main(){
    BSTNode *root = nullptr;
    int arr[] {8,3,10,1,6,14,2,4,7,13};
    
    // How to build the tree
    for (int x: arr) {
        root = insert(root,x);
    }
    
    printBT("", root, false);
    
    delete_node(root,6);
    Sleep(1500);
    printBT("",root,false);
    
    return 0;
}
