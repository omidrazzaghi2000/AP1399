#include "bst.h"
#include <iostream>

/*
    Node Class
*/
BST::Node::Node(int i){
    val=i;
}
BST::Node::Node(std::shared_ptr<Node> p, std::shared_ptr<Node> r, std::shared_ptr<Node> l){
    //there is no limitaion to assigning these parametere
    parent=p;
    right=r;
    left=l;
}
BST::Node::Node(int i,std::shared_ptr<Node> p, std::shared_ptr<Node> r, std::shared_ptr<Node> l){
    parent=p;
    right=r;
    left=l;
    val=i;
}
void BST::Node::show(){
    std::cout 
    << "Node with value"
    << val
    << std::endl;
}

/*
    BST class
*/

//copy constructor
BST::BST(const BST& b){
    //only need to change root address
    proot = b.proot;
}

BST::BST(std::shared_ptr<Node> _proot){
    proot=_proot;
}

int BST::root(){
    return proot->val;
}


//extra methods:
//because of on unittest in aphw3_unittest.cpp file we
//must declare add function like below:
BST* BST::add(int value){
    if(proot==nullptr){
        //set node value
        proot=std::make_shared<Node>(value);
        //as default all right and left and parent are nullptr
    }//whether initialized before
    else{
        //we have one element as root of tree
        if(proot->left == nullptr && proot->right == nullptr){
            if(proot->val > value) {
                //insert to left node and set parent
                // proot->left->val=value;
                // proot->left->parent=proot;
                proot->left=std::make_shared<Node> (value,proot,nullptr,nullptr);
            }else{
                // proot->right->val=value;
                // proot->right->parent=proot;
                proot->right=std::make_shared<Node> (value,proot,nullptr,nullptr);
            }
        }
        else{
            //we have one element with one branch

            /*we have right branch*/
            if(proot->left==nullptr){
                if(value < proot->val){

                    // proot->left->val=value;
                    // proot->left->parent=proot;
                    proot->left=std::make_shared<Node> (value,proot,nullptr,nullptr);
                }else{
                    //it must be add to right branch tree so again we call this function with different tree root 
                    
                    //define new tree with root of right branch
                    BST TempBstTree{BST(proot->right)};

                    //again call add function for new tree
                    TempBstTree.add(value);

                }
            }else{
                /*we have left branch */
                if(proot->right==nullptr){

                    if(value < proot->val){

                        // proot->right->val=value;
                        // proot->right->parent=proot;
                        proot->left=std::make_shared<Node> (value,proot,nullptr,nullptr);

                        }
                        else{

                        //it must be add to left branch tree so again we call this function with different tree root 

                        //define new tree with root of left branch
                        BST TempBstTree{BST(proot->left)};

                        //again call add function for new tree
                        TempBstTree.add(value);


                    }
                }
                /*we have full branch*/
                if(proot->left != nullptr && proot->right != nullptr){
                    if(value > proot->val){

                        //it must go to right tree

                        //define new tree with root of right branch
                        BST TempBstTree{BST(proot->right)};

                        //again call add function for new tree
                        TempBstTree.add(value);


                    }else{

                        //it must go to left tree

                        //define new tree with root of left branch
                        BST TempBstTree{BST(proot->left)};

                        //again call add function for new tree
                        TempBstTree.add(value);
                    }
                }
            }

            
        }



    }


    //to support below line
    //mytree->add(10)->add(14)->add(12)
    return this;
}
