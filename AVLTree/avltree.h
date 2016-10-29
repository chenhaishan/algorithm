#ifndef AVLTREE_H
#define AVLTREE_H

#include <iostream>
#include <queue>

using namespace std;
/*
template <typename T>
T max(const T &l, const T &r){
    return l>r ? l :r;
}
*/
template <typename Comparable>
class AVLTree{
private:
    struct AVLNode{
        Comparable element;
        AVLNode *left;
        AVLNode *right;
        int height;
        AVLNode(const Comparable &x, AVLNode *lf, AVLNode *rg, int h = 0)
            :element(x), left(lf), right(rg), height(h){}

    };

    AVLNode *root;

    void makeEmpty(AVLNode * &t){
        if(t != nullptr){
            makeEmpty(t->left);
            makeEmpty(t->right);
            delete t;
        }
        t = nullptr;
    }

    AVLNode * clone(AVLNode * &t){
        if(t == nullptr)
            return nullptr;
        return new AVLNode(t->element, clone(t->left), clone(t->right), t->height);
    }

    int height(const AVLNode * t) const{
        return t == nullptr? -1 : t->height;
    }

    /*left-left insertion*/
    void left_left_rotate(AVLNode * &k2){
        AVLNode *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;

        k1->height = max(height(k1->left), height(k1->right)) + 1;
        k2->height = max(height(k2->left), height(k2->right)) + 1;

        k2 = k1;
    }

    /*right-right insertion*/
    void right_right_rotate(AVLNode * &k2){
        AVLNode *k1 = k2->right;
        k2->right = k1->left;
        k1->left = k2;

        k1->height = max(height(k1->left), height(k1->right)) + 1;
        k2->height = max(height(k2->left), height(k2->right)) + 1;

        k2 = k1;
    }

    /*left-right insertion*/
    void left_right_rotate(AVLNode * &k3){
        right_right_rotate(k3->left);
        left_left_rotate(k3);
    }

    /*right-left insertion*/
    void right_left_rotate(AVLNode * &k3){
        left_left_rotate(k3->right);
        right_right_rotate(k3);
    }

    void insert(const Comparable &x, AVLNode * &t){
        if(t == nullptr){
            t = new AVLNode(x, nullptr, nullptr, 0);
        }
        /*t maybe k2(signal rotate) or k3(double rotate)*/
        else if(x < t->element){
            insert(x, t->left);
            /*x shoude be insert to t's left son tree*/
            /*and if broken balance condition, left_height > right_height*/
            if(height(t->left) - height(t->right) == 2){
                /*check which side takes x */
                if(x < t->left->element){/*left-left insert*/
                    left_left_rotate(t);
                }
                else{/*left-right insert*/
                    left_right_rotate(t);
                }
            }
        }
        /*t maybe k2(signal rotate) or k3(double rotate)*/
        else if(x > t->element){
            insert(x, t->right);
            /*x should be insert to t's right son tree*/
            /*and if broken balance codition, right_height>left_height*/
            if(height(t->right) - height(t->left) == 2){
                /*check which side takes x*/
                if(x > t->right->element){/*right-right insert*/
                    right_right_rotate(t);
                }
                else{/*right-left insert*/
                    right_left_rotate(t);
                }
            }
        }
        else
            ;/*duplated, do nothing*/

        /*update t's height*/
        t->height = max<int>(height(t->left), height(t->right)) + 1;
    }

    AVLNode * & findMin(AVLNode * &t){

        if(t->left != nullptr){
            return findMin(t->left);
        }
        return t;
    }

    void remove(const Comparable &x, AVLNode* &t){
        if(t == nullptr){/*AVLTree is empty or can't find x*/
            return;
        }
        if(x < t->element){
            remove(x, t->left);
            /*x was token from t's left son tree, so height_left < height_right*/
            if(height(t->right) - height(t->left) == 2){
                if(height(t->right->left) < height(t->right->right)){
                    right_right_rotate(t);
                }
                else{
                    right_left_rotate(t);
                }
            }
        }
        else if(x > t->element){
            remove(x, t->right);
            /*x was token from t's right son tree, so height_left > height_right*/
            if(height(t->left) - height(t->right) == 2){
                if(height(t->left->left) > height(t->left->right)){
                    left_left_rotate(t);
                }
                else{
                    left_right_rotate(t);
                }
            }
        }
        else{
            /*t has two child*/
            if(t->left != nullptr && t->right != nullptr){
                AVLNode * min = findMin(t->right);
                t->element = min->element;
                remove(min->element, t->right);
                /*min is deleted from t's right son tree, so height_left > height_right*/
                if(height(t->left) - height(t->right) == 2){
                    if(height(t->left->left) > height(t->left->right)){
                        /*left-left insertion*/
                        left_left_rotate(t);
                    }
                    else{
                        left_right_rotate(t);
                    }
                }

            }
            /*t has most one child*/
            else{
                AVLNode *old = t;
                t = old->right;
                delete old;
            }

        }
        if(t != nullptr)
            t->height = max(height(t->left), height(t->right)) + 1;
    }

    void Handle(AVLNode * &t){
        cout<<t->element<<" ";
    }

    void InorderTraversal(AVLNode *t){
        if(t == nullptr)
            return;
        if(t->left != nullptr){
            InorderTraversal(t->left);
        }
        Handle(t);
        if(t->right != nullptr){
            InorderTraversal(t->right);
        }
    }

    void LevelorderTraversal(queue<AVLNode *> &q){
        AVLNode *t = q.front();
        if(t == nullptr)
            return;
        while(!q.empty()){
            t = q.front();
            Handle(t);
            if(t->left != nullptr)
                q.push(t->left);
            if(t->right != nullptr)
                q.push(t->right);
            q.pop();
        }
    }

public:
    AVLTree():root(nullptr){}
    AVLTree(const AVLTree &rhs):root(nullptr){

        *this = rhs;
    }
    ~AVLTree(){
        makeEmpty();
    }

    /*reload operator*/
    AVLTree & operator= (const AVLTree &rhs){
        if(this != &rhs){
            makeEmpty();
            root = clone(rhs->root);
        }
        return *this;
    }

    const AVLTree &operator= (const AVLTree &rhs) const {
        if(*this != &rhs){
            makeEmpty();
            root = clone(rhs->root);
        }
        return *this;
    }
    /*information*/
    bool isEmpty() const {
        return root == nullptr;
    }
    /*height of tree*/
    int height() const {
        if(isEmpty())
            return -1;
        return root->height;
    }

    /*insert*/
    void insert(const Comparable &x){
        insert(x, root);
    }

    void remove(const Comparable &x){
        remove(x, root);
    }

    void makeEmpty(){
        makeEmpty(root);
    }

    void printtree(){
        queue<AVLNode *> q;
        /*InorderTraversal(root);*/
        q.push(root);
        LevelorderTraversal(q);
    }

};

#endif // AVLTREE_H
