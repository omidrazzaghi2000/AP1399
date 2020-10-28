#include "bst.h"
#include <iostream>
#include <vector>

void disp(int val){
    std::cout << val << std::endl;
}
void disp(std::string s){
    std::cout << s << std::endl;
}
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

int BST::operator[](int index){
    return inorder().at(index);
}

size_t BST::size(){
    if(proot==nullptr){

        //No node 
        return 0;

    }else{
        
        //we have one node
        
        //we go to right and left tree to calculate all nodes
        
        BST tempRightTree{BST(proot->right)};
        BST tempLeftTree{BST(proot->left)};
        
        
        return  1 + tempRightTree.size() + tempLeftTree.size();

    }
    
}

bool BST::search(int i){
    if(proot!=nullptr){
        if(proot->val == i){

            //easy easy
            return true;
        
        }

        if(proot->val > i){

            //it may be in the left tree
            BST leftTree{BST(proot->left)};
            return leftTree.search(i);
        
        }
        

        if(proot->val < i){

            //it may be in the right tree
            BST rightTree{BST(proot->right)};
            return rightTree.search(i);
        }
    }
        return false;
    
}

//inorder : left parent right
std::vector<int> BST::inorder(){

    static std::vector<int> inorderVector;

    if(proot==nullptr){
        
        //Tree does not have any nodes
        std::cout << "null\n";
        return inorderVector;
    }

    else if(proot->left==nullptr && proot->right == nullptr ){

        //Only root
        std::cout << "only root " << proot-> val << std::endl;
        inorderVector.push_back(proot->val);
        return inorderVector;
    }

    else if(proot->left == nullptr && proot-> right != nullptr){

        //root with right tree
        std::cout << " root + right tree " << proot-> val << std::endl;
        inorderVector.push_back(proot->val);
        
        //next we go to right tree to inorder traverse 
        BST tempRightTree{BST(proot->right)};
        inorderVector =  tempRightTree.inorder();
    }

    else if(proot->left != nullptr && proot->right == nullptr){

        //root with left tree
        std::cout << " root + left tree " << proot-> val << std::endl;
        BST tempLeftTree{BST(proot->left)};
        inorderVector =  tempLeftTree.inorder();

        //next we print rooot
        inorderVector.push_back(proot->val);

    }

    else if(proot->left != nullptr && proot-> right != nullptr){

        //full tree

        //left
        std::cout << " full tree " << proot-> val << std::endl;
        BST tempLeftTree{BST(proot->left)};
        inorderVector =  tempLeftTree.inorder();

        //parent
        inorderVector.push_back(proot->val);

        //right
        BST tempRightTree{BST(proot->right)};
        inorderVector =  tempRightTree.inorder();

    }
     
    return inorderVector;
    
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
    
        //we have one element as root of tree
    else if(proot->left == nullptr && proot->right == nullptr){
            
            if(proot->val > value) {
                //insert to left node and set parent
                // proot->left->val=value;
                // proot->left->parent=proot;
                proot->left=std::make_shared<Node> (value,proot,nullptr,nullptr);
            }else if(value > proot->val){
                // proot->right->val=value;
                // proot->right->parent=proot;
                proot->right=std::make_shared<Node> (value,proot,nullptr,nullptr);
            }
        }
            
            /*we have right branch*/
    else if(proot->left==nullptr && proot->right != nullptr){
                if(value < proot->val){
                    
                    // proot->left->val=value;
                    // proot->left->parent=proot;
                    proot->left=std::make_shared<Node> (value,proot,nullptr,nullptr);
                }else if(value > proot->val){
                    //it must be add to right branch tree so again we call this function with different tree root 
                    
                    //define new tree with root of right branch
                    BST TempBstTree{BST(proot->right)};

                    //again call add function for new tree
                    TempBstTree.add(value);

                }
            }
                /*we have left branch */
    else if(proot->right==nullptr && proot->left != nullptr){

                    if(value > proot->val){

                        // proot->right->val=value;
                        // proot->right->parent=proot;
                        proot->right=std::make_shared<Node> (value,proot,nullptr,nullptr);
                    }
                        else if(value < proot->val){

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


                    }else if(value < proot->val){

                        //it must go to left tree

                        //define new tree with root of left branch
                        BST TempBstTree{BST(proot->left)};

                        //again call add function for new tree
                        TempBstTree.add(value);
                    }
    }
            

    //to support below line
    //mytree->add(10)->add(14)->add(12)
    return this;
}

void BST::remove(int i){
    
    //check value is in the tree or not
    if(search(i)){

        //we have some types let us go:

        //first: node which we want to remove is root of tree
        
    }

}