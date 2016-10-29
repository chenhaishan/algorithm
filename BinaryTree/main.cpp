#include <iostream>
#include <queue>
#include <vector>
#include <stack>
using namespace std;

struct Node{
    char element;
    struct Node *left;
    struct Node *right;

    Node():left(nullptr), right(nullptr){}

    Node(char x, struct Node * l=nullptr, struct Node * r=nullptr)
        :element(x), left(l), right(r){}
};
typedef struct Node BT;

/*
              +

     +                  *

a        *           +       g

       b   c       *   f

                  d e

inorder traversal:   a + b * c + d * e + f * g
postorder traversal: a b c * + d e * f + g * +
preorder traversal:  + + a * b c * + * d e f g
levelorder traversal:+ + * a * + g b c * f d e

reverse:
              +

     *                  +

  g     +           *       a

      f   *       c   b

         d e

*/
void Handle(BT * &p){
    cout<<p->element<<' ';
}

void InorderTraversal(BT * &root){
    if(root == nullptr)
        return;
    InorderTraversal(root->left);
    Handle(root);
    InorderTraversal(root->right);
}
/*inorder traversal no recurse*/
void InorderTraversal_NoRecurse(BT * root){
    stack<BT *> s;
    auto p = root;
    while(p != nullptr || !s.empty()){
        while(p != nullptr){
            s.push(p);
            p = p->left;

        }
        if(!s.empty()){
            p = s.top();
            s.pop();
            Handle(p);
            p = p->right;
        }
    }
}



void PostorderTraversal(BT * &root){
    if(root == nullptr)
        return;
    PostorderTraversal(root->left);
    PostorderTraversal(root->right);
    Handle(root);

}

/*postorder traversal no recurse*/
void PostorderTraversal_NoRecurse(BT * root){
    stack<BT *>s1, s2;
    BT *p;
    s1.push(root);
    while(!s1.empty()){
        p = s1.top();
        s1.pop();
        s2.push(p);
        if(p ->left != nullptr)s1.push(p->left);
        if(p ->right != nullptr)s1.push(p->right);
    }
    while(!s2.empty()){
        Handle(s2.top());
        s2.pop();
    }
}

void PreorderTraversal(BT * &root){
    if(root == nullptr)
        return;
    else
        Handle(root);
    PreorderTraversal(root->left);
    PreorderTraversal(root->right);
}

/*very bad!!!*/
/*
void PreorderTraversal_No_Recurse(BT * root){
    vector<BT *> vb;
    vb.push_back(root);
    Handle(root);
LABEL:
    auto now = vb.back();

    while(now->left != nullptr){
        now = now->left;
        Handle(now);
        vb.push_back(now);
    }
    if(now->right != nullptr){
        vb.pop_back();//pop now
        now = now->right;
        Handle(now);
        vb.push_back(now);
        goto LABEL;
    }else{
        vb.pop_back();
        while(!vb.empty() && vb.back()->right == nullptr){
            vb.pop_back();
        }
        if(!vb.empty()){
            auto tmp = vb.back()->right;
            vb.pop_back();
            Handle(tmp);
            vb.push_back(tmp);
            goto LABEL;
        }
        else{
            goto END;
        }
    }
END:
    cout<<"over"<<endl;
}
*/

/*perfect one!!!*/
void PreorderTraversal_NoRecurse(BT * root){
    stack<BT *> s;
    s.push(root);
    while(!s.empty()){
        auto p = s.top();
        s.pop();
        Handle(p);
        if(p->right != nullptr)s.push(p->right);
        if(p->left != nullptr)s.push(p->left);
    }
}

/*another preorder traversal */
void PreorderTraversal_NoRecurse_2(BT * root){
    stack<BT *> s;
    auto p = root;
    while(p != nullptr || !s.empty()){
        while(p != nullptr){
            Handle(p);
            s.push(p);
            p = p->left;
        }
        if(!s.empty()){
            p = s.top();
            s.pop();
            p = p->right;
        }
    }
}

void LevelorderTraversal(queue<BT *> &q)
{
   while(!q.empty()){
       BT *p = q.front();
       Handle(p);
       q.pop();
       if(p->left != nullptr)
           q.push(p->left);
       if(p->right != nullptr)
           q.push(p->right);
   }

}

void Reverse(BT * &root){
    if(root->left == nullptr && root->right == nullptr){
        return;
    }
    if(root->left != nullptr){
        Reverse(root->left);
    }
    if(root->right != nullptr){
        Reverse(root->right);
    }
    BT *tmp = root->left;
    root->left = root->right;
    root->right = tmp;
}

int Depth(BT *root, int depth=0){
    if(root->left == nullptr && root->right == nullptr){
        return depth;
    }
   int ldepth = depth;
   int rdepth = depth;
   if(root->left != nullptr){
       ldepth = Depth(root->left, depth+1);
   }
   if(root->right != nullptr){
       rdepth = Depth(root->right, depth+1);
   }
   return ldepth > rdepth ? ldepth:rdepth;
}

int main(int argc, char *argv[])
{
    BT *root = new BT('+',
                      new BT('+',
                            new BT('a', nullptr, nullptr),
                            new BT('*',
                                    new BT('b', nullptr, nullptr), new BT('c', nullptr, nullptr))),
                      new BT('*', new BT('+', new BT('*', new BT('d', nullptr,nullptr),
                                                     new BT('e', nullptr, nullptr)),
                                              new BT('f', nullptr, nullptr)),
                             new BT('g', nullptr, nullptr)));

    cout<<"InorderTraversal"<<endl;
    InorderTraversal(root);
    cout<<endl;

    cout<<"PostorderTraversal"<<endl;
    PostorderTraversal(root);
    cout<<endl;

    cout<<"PostorderTraversal_NoRecurse double stack"<<endl;
    PostorderTraversal_NoRecurse(root);
    cout<<endl;

    cout<<"PreorderTraversal"<<endl;
    PreorderTraversal(root);
    cout<<endl;

    cout<<"PreorderTraversal_NoRecurse"<<endl;
    PreorderTraversal_NoRecurse(root);
    cout<<endl;

    queue<BT *> q;
    q.push(root);
    cout<<"LevelorderTraversal"<<endl;
    LevelorderTraversal(q);
    cout<<endl;

    /*reverse binaytree*/
    cout<<"reverse binarytree and inorder traversal"<<endl;
    Reverse(root);
    InorderTraversal(root);
    cout<<endl;

    cout<<"depth of the tree is :"<<Depth(root)<<endl;

    return 0;
}
