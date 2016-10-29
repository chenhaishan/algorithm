#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include "binarysearchtree.h"
using namespace std;
class EmptyBinaySearchTree;

template <typename Comparable>
class BST{//BinarySearchTree
private:
    struct BN{//BinaryNode
        Comparable element;
        BN * left;
        BN * right;
        BN(const Comparable &x, BN *lf, BN *rg)
            :element(x), left(lf), right(rg){}
    };

    BN *root;

    /*a lot functions need to recursive with argv, so it is smart to
    define those functions in private domain, and provide the same name
    functions defined in public.*/

    /*use BN * & t will do great job!*/
    void makeEmpty(BN * &t){
        if(t != nullptr){
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
    /*t stands for father_t->left or father_t->right, which will be set to nullptr*/
        t = nullptr;
    }

    /*check element*/
    bool contains(const Comparable &x, BN *t)const{
        if(t == nullptr){
            return false;
        }
        else if(x > t->element){
            return contains(x, t->right);
        }
        else if(x < t->element){
            return contains(x, t->left);
        }
        else{
            return true;
        }
    }

    /*findMin*/
    BN * findMin(BN *t) const{
        if(t == nullptr){
            return nullptr;
        }
        if(t->left == nullptr){
            return t;
        }
        else
            return findMin(t->left);
    }

    /*findMax*/
    BN * findMax(BN *t)const{
        if(t == nullptr){
            return nullptr;
        }
        if(t->right == nullptr){
            return t;
        }
        else{
            return findMax(t->right);
        }
    }

    /*insert, if x exits, do nothing.*/
    /*BN * &t , so t stands for father_t->left or father_t->right*/
    void insert(const Comparable &x, BN * &t){
        if(t == nullptr){
            t = new BN(x, nullptr, nullptr);
        }
        else if(x < t->element){
            insert(x, t->left);
        }
        else if(x > t->element){
            insert(x, t->right);
        }
        else
            ;/*x already exits, do nothing*/
    }

    /*remove*/
    void remove(const Comparable &x, BN * &t){
        /*if not found or t is empty, return*/
        if(t == NULL){
            return;
        }
        else if(x < t->element){
            remove(x, t->left);
        }
        else if(x > t->element){
            remove(x, t->right);
        }
        /*if t has two child, find the minimal element of t's right tree(this
         minimal node mustn't has left child),and replace t's element with it;
        then, remove the element node from t's right tree*/
        else if(t->left != nullptr && t->right != nullptr)
        {
            t->element = findMin(t->right)->element;
            remove(t->element, t->right);
        }
        /*if t has only one child, father_t = t's child, and delete t*/
        else{
            BN * old = t;
            t = (t->left == nullptr)?t->right:t->left;
            delete old;
        }

    }

    /*Handle*/
    void Handle(BN * &t){
        cout<<t->element<<" ";
    }

    /*level order traversal*/
    /*inorder traversal*/
    void InorderTraversal(BN *t){
        if(t == nullptr)
            return;
        /*
        if(t->left != nullptr){
            InorderTraversal(t->left);
            Handle(t);
        }
        if(t->right != nullptr){
            InorderTraversal(t->right);
            if(t->left == nullptr)
                Handle(t);
        }
        if(t->left == nullptr && t->right == nullptr){
            Handle(t);
        }
        */

        InorderTraversal(t->left);
        Handle(t);
        InorderTraversal(t->right);
    }

public:
    BST(){
        root = new BN(6, new BN(2, new BN(1, nullptr, nullptr), new BN(4, new BN(3, nullptr, nullptr), nullptr)), new BN(8, nullptr, nullptr));
    }
    BST(const BST &rhs):root(nullptr){
        //too diffcult!
        //1.delete all BinarySearchTree
        makeEmpty();
        //2.use operator=
        *this = rhs;
    }

    ~BST(){
        makeEmpty();
    }

    /***fantastic!***/
    BST & operator= (const BST &rhs){
        if(this != &rhs){
            root = clone(rhs.root);
        }
        return *this;
    }
    /*brilliant!*/
    BN * clone(const BN* t){
        if(t == nullptr){
            return nullptr;
        }

        return new BN(t->element, clone(t->left), clone(t->right));
    }

    /*information*/
    bool isEmpty()const{
        return root == nullptr;
    }

    /*check element*/
    bool contains(const Comparable &x)const{
        return contains(x, root);
    }

    /*findMin*/
    const Comparable & findMin() const{
        const BN *t = findMin(root);
        if(t == nullptr){
            throw EmptyBinaySearchTree();
        }
        return t->element;
    }

    /*findMax*/
    const Comparable & findMax() const{
        if(isEmpty()){
            throw EmptyBinaySearchTree();
        }
        return findMax(root)->element;
    }

    /*delete*/
    void makeEmpty(){
        makeEmpty(root);
    }

    /*insert*/
    void insert(const Comparable &x){
        insert(x, root);
    }

    /*remove*/
    void remove(const Comparable &x){
        remove(x, root);
    }

    void printtree(){
        InorderTraversal(root);
    }
};

#endif // BINARYSEARCHTREE_H
