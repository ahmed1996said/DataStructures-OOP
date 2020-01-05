//
// Created by Ahmed Al Mahrooqi on 2019-03-21.
//

#ifndef ECE309_SPR19_BSTREE_H
#define ECE309_SPR19_BSTREE_H
/*
#include "KVPair.h"
#include <stdlib.h>
#include "Stack.h"

template <class K, class T>
class BSTree{

public:

    class BSTnode{

    public:
        KVPair<K,T> kvpair;
        BSTnode* left;
        BSTnode* right;
        BSTnode(KVPair<K,T> pair, BSTnode* l=nullptr, BSTnode* r=nullptr)
                : kvpair(pair), left(l), right(r) {}
    };

    protected:
    BSTnode* root;
    void deleteSubTree(BSTnode*);
    int BSTGetHeight(BSTnode*);
    bool removeNode(BSTnode* node, BSTnode* parent);

public:



    class BSTiterator  {

    private:
       Stack<BSTnode> stack;
       BSTnode* curr;
       BSTnode* rt;
       int down;
       int largest;
         BSTiterator(){curr= nullptr; rt= nullptr; down=0;largest=0;  }
         //int index;            // index of current data item

    public:
        T getData();
         K getKey();
        void increment();
        bool end();
       friend class BSTree;
    };


    BSTree() : root(nullptr) {}
    ~BSTree();

    bool search(K key,T &v);
    void insert(const KVPair<K,T>& pair);
    bool remove(const K& key);
    int getHeight();
    BSTiterator begin(){

        auto it = new BSTiterator;
        if(!root)
            return *it;

        auto temp = root;
        it->rt=root;

        while (temp->left) {
            it->stack.push(temp);
            temp = temp->left;
        }
       // BSTnode *out;

        it->curr = temp;
        return *it;
    }


};






template <class K, class T>
bool BSTree<K,T>::search(K key, T &v) {
    // search for key
    // if found, return true and set v to the value
    // if not found, return false

    auto ptr=root;
    while(ptr){

        if(ptr->kvpair.getKey() == key)
        {
            v = ptr->kvpair.getVal();
            return true;
        }
        else if(key< ptr->kvpair.getKey()){

            ptr=ptr->left;
        }
        else{
            ptr = ptr->right;
        }
    }

    return false;
}

template <class K, class T>
void BSTree<K,T>::insert(const KVPair<K, T> &pair) {
    // add copy of pair to the tree

    auto node = new BSTnode(pair);
    if (!root) {
        root = node;
    }
    else {
        BSTnode * cur = root;
        while (cur) {
            if (pair.key < cur->kvpair.key) {
                if (cur->left) cur = cur->left;
                else {
                    cur->left = node;
                    return;
                }
            } else {
                if (cur->right) cur = cur->right;
                else {
                    cur->right = node;
                    return;
                }
            }
        }
    }

}


template <class K, class T>
bool BSTree<K,T>::removeNode(BSTnode *node, BSTnode *parent) {

    // double-check parent-child relationship
    if (parent && (parent->left != node) && (parent->right != node)) return false;  // error, do nothing
    if (!parent && (node != root)) return false;   // error, do nothing

    // CASE 1: leaf node
    if (!node->left && !node->right) {
        if (!parent) {
            // removing root as only node
            root = nullptr;
        } else if (parent->left == node) parent->left = nullptr;
        else parent->right = nullptr;
    }

        // CASE 2: one child
        // if internal node with only left child
    else if (node->left && !node->right) {
        // move left child into this node's position
        if (!parent) {
            // replace root with left child
            root = node->left;
        } else if (parent->left == node) parent->left = node->left;
        else parent->right = node->left;
    }
        // if internal node with only right child
    else if (!node->left && node->right) {
        // move right child into this node's position
        if (!parent) {
            // replace root with right child
            root = node->right;
        } else if (parent->left == node) parent->left = node->right;
        else parent->right = node->right;
    }

        // CASE 3: two children
        // if internal node with two children
    else {
        // don't remove -- find successor, copy data from successor, and then remove that node
        // successor is left-most node in right subtree
        BSTnode *s = node->right;  // s is known to be non-null
        BSTnode *sp = node;   // successor's parent node
        bool found = false;
        while (!found) {
            if (!s->left) found = true;
            else {
                sp = s;
                s = s->left;
            }
        }
        // remove s from its position in tree, then replace node with s
        bool rs = removeNode(s, sp);
        // replace node with s
        if (rs) {
            s->left = node->left;
            s->right = node->right;
            if (!parent) root = s;
            else if (parent->left == node) parent->left = s;
            else parent->right = s;
        }
        else return false;  // unable to remove successor?
    }
    return true;
}



template <class K, class T>
bool BSTree<K,T>::remove(const K &key) {
    // remove first pair with matching key
    // return true if removed, false if not found

    BSTnode *cur = root;
    BSTnode *parent = nullptr;
    bool removed = false;

    while (cur && !removed) {
        if (cur->kvpair.getKey() == key) { // found key, remove node
            removeNode(cur, parent);
            delete cur;
            removed = true;

        } else if (key < cur->kvpair.getKey()) { // search left
            parent = cur;
            cur = cur->left;
        } else { // search right
            parent = cur;
            cur = cur->right;
        }
    }
    return removed;

}

template <class K, class T>
int BSTree<K,T>::BSTGetHeight(BSTnode* node) {

    if (!node)
        return -1;

        int leftHeight = BSTGetHeight(node->left);
        int rightHeight = BSTGetHeight(node->right);

                return  (leftHeight > rightHeight) ? 1+leftHeight:1+rightHeight;
}


template <class K, class T>
int BSTree<K,T>::getHeight() {
    return BSTGetHeight(root);
}

template <class K, class T>
void BSTree<K,T>::deleteSubTree(BSTnode* subroot) {
    if (subroot) {
        deleteSubTree(subroot->left);
        deleteSubTree(subroot->right);
        delete subroot;
    }
}


template<class K, class T>
BSTree<K,T>::~BSTree() {

    deleteSubTree(root);

}


template<class K, class T>
T BSTree<K,T>::BSTiterator::getData() { return curr->kvpair.val; }

template<class K, class T>
K BSTree<K,T>::BSTiterator::getKey() { return curr->kvpair.key; }

template<class K, class T>
void BSTree<K,T>::BSTiterator::increment() {

    BSTnode *up;

    if (!end()) {
        largest=curr->kvpair.getKey();

        if (curr->right) {
            stack.push(curr);
            curr = curr->right;



            if (curr->left) {

                while (curr->left) {
                    stack.push(curr);
                    curr = curr->left;

                }

            }
        } else {
            while(1){
                stack.pop(up);
                curr = up;
                if(up->kvpair.getKey() > largest||curr==rt)
                    break;
            }


        }
    }
}

template<class K, class T>
bool BSTree<K,T>::BSTiterator::end() {

        auto temp=rt;

        while(temp->right){
            temp =temp->right;
        }

    return curr->kvpair.key >= temp->kvpair.key ? true : false;

}

*/
#endif //ECE309_SPR19_BSTREE_H

