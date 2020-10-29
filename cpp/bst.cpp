#include "bst.h"
#include <iostream>
#include <vector>
#include <memory>

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

BST BST::operator+(int value){
    BST tempTree(proot);
    tempTree.add(value);
    return tempTree;
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
        return inorderVector;
    }

    else if(proot->left==nullptr && proot->right == nullptr ){

        //Only root
        inorderVector.push_back(proot->val);
        return inorderVector;
    }

    else if(proot->left == nullptr && proot-> right != nullptr){

        //root with right tree
        inorderVector.push_back(proot->val);
        
        //next we go to right tree to inorder traverse 
        BST tempRightTree{BST(proot->right)};
        inorderVector =  tempRightTree.inorder();
    }

    else if(proot->left != nullptr && proot->right == nullptr){

        //root with left tree
        BST tempLeftTree{BST(proot->left)};
        inorderVector =  tempLeftTree.inorder();

        //next we print rooot
        inorderVector.push_back(proot->val);

    }

    else if(proot->left != nullptr && proot-> right != nullptr){

        //full tree

        //left
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

//perorder :root left right
std::vector<int> BST::preorder(){
    static std::vector<int> inorderVector;

    if(proot==nullptr){
        
        //Tree does not have any nodes
        return inorderVector;
    }

    else if(proot->left==nullptr && proot->right == nullptr ){

        //Only root
        inorderVector.push_back(proot->val);
        return inorderVector;
    }

    else if(proot->left == nullptr && proot-> right != nullptr){

        //root with right tree
        inorderVector.push_back(proot->val);
        
        //next we go to right tree to preorder traverse 
        BST tempRightTree{BST(proot->right)};
        inorderVector =  tempRightTree.preorder();
    }

    else if(proot->left != nullptr && proot->right == nullptr){

        //we save root
        inorderVector.push_back(proot->val);

        //root with left tree
        BST tempLeftTree{BST(proot->left)};
        inorderVector =  tempLeftTree.preorder();


    }

    else if(proot->left != nullptr && proot-> right != nullptr){

        //full tree
        
        //parent
        inorderVector.push_back(proot->val);
        
        //left
        BST tempLeftTree{BST(proot->left)};
        inorderVector =  tempLeftTree.preorder();

        

        //right
        BST tempRightTree{BST(proot->right)};
        inorderVector =  tempRightTree.preorder();

    }
     
    return inorderVector;
}

//postorder : left right root
std::vector<int> BST::postorder(){
    static std::vector<int> inorderVector;

    if(proot==nullptr){
        
        //Tree does not have any nodes
        return inorderVector;
    }

    else if(proot->left==nullptr && proot->right == nullptr ){

        //Only root
        inorderVector.push_back(proot->val);
        return inorderVector;
    }

    else if(proot->left == nullptr && proot-> right != nullptr){
        
        //root with right tree

        //we go to right tree to postorder traverse 
        BST tempRightTree{BST(proot->right)};
        inorderVector =  tempRightTree.postorder();

        // next add root
        inorderVector.push_back(proot->val);
    }

    else if(proot->left != nullptr && proot->right == nullptr){

        //root with left tree
        BST tempLeftTree{BST(proot->left)};
        inorderVector =  tempLeftTree.postorder();

        //next we save root
        inorderVector.push_back(proot->val);

    }

    else if(proot->left != nullptr && proot-> right != nullptr){

        //full tree
        
        
        
        //left
        BST tempLeftTree{BST(proot->left)};
        inorderVector =  tempLeftTree.postorder();


        //right
        BST tempRightTree{BST(proot->right)};
        inorderVector =  tempRightTree.postorder();

        //parent
        inorderVector.push_back(proot->val);

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
        if(i == proot->val){    
            //again we have three types:
                //only root
                if(proot->left == nullptr && proot->right == nullptr){
                    
                    //  :(  tree is being destroyed
                    proot=nullptr;
                }
                //root + right branch
                else if(proot->left == nullptr && proot->right != nullptr){

                    //root of right tree is the new root of big tree
                    proot = proot->right;
                    proot->parent=nullptr;
                }
                //root + left branch
                else if(proot->left != nullptr && proot->right == nullptr){

                    //root of left tree is the new root of big tree
                    proot = proot->left;
                    proot->parent=nullptr;
                //root + left + right
                }else if(proot->left != nullptr && proot->right != nullptr){
                
                    //we remove root and then declare right child as root 
                    //but there is one important thing that if right child of root have 
                    // left child so we add this node to left child of former root
                    if(proot->right->left!=nullptr){
                        BST LeftTree = BST(proot->left);
                        std::shared_ptr<Node> leftTreeMaxNodePtr=LeftTree.findMaximum();
                        
                        //1:
                        proot->left->parent=proot->right;
                        
                        //2:
                        proot=proot->right;
                        proot->parent=nullptr;

                        //3:
                        leftTreeMaxNodePtr->right=proot->left;
                        proot->left->parent=leftTreeMaxNodePtr;
                        proot->left=LeftTree.get_proot();


                    }else{
                        
                        //set right child as root and delete former root

                        //1:
                        proot->left->parent=proot->right;
                        proot->right->left=proot->left;

                        //2:
                        proot=proot->right;
                        proot->parent=nullptr;

                    }
                    

                }
        }else{
        //if it is not root of main tree then we declare major tree as below
        BST majorTree = searchAndGetTree(i);

        //second: node which we want to remove is a leaf(no right and left branch)
        if(majorTree.get_proot()->right == nullptr && majorTree.get_proot()->left == nullptr){
            //in this case we have no type

                //wether it is the left child of his/her parent 
                if(majorTree.get_proot()->parent->getval() > i){
                    majorTree.get_proot()->parent->left=nullptr;
                }else{
                    majorTree.get_proot()->parent->right=nullptr;
                }   
        
        }else

        //third: node which we want to delete has only right child
        if(majorTree.get_proot()->right != nullptr && majorTree.get_proot()->left == nullptr){
            

            //if node which we want to delete is left child of his/her parent
            if(majorTree.get_proot()->parent->getval() > i){
                majorTree.get_proot()->parent->left=majorTree.get_proot()->right;
                majorTree.get_proot()->right->parent=majorTree.get_proot()->parent;
            }else{

            //if node which we want to delete is right child of his/her parent
                majorTree.get_proot()->parent->right=majorTree.get_proot()->right;
                majorTree.get_proot()->right->parent=majorTree.get_proot()->parent;
            }
        }else
        //fourth: node which we want to delete has only left child
        if(majorTree.get_proot()->right != nullptr && majorTree.get_proot()->left == nullptr){

            //if node which we want to delete is left child of his/her parent
            if(majorTree.get_proot()->parent->getval() > i){
                majorTree.get_proot()->parent->left=majorTree.get_proot()->left;
                majorTree.get_proot()->left->parent=majorTree.get_proot()->parent;
            }else{

            //if node which we want to delete is right child of his/her parent
                majorTree.get_proot()->parent->right=majorTree.get_proot()->left;
                majorTree.get_proot()->left->parent=majorTree.get_proot()->parent;
            }
        }else{
        //five: node has right and left child

            //in this case I replace right child with root 
            //but if right child has left child or not we have two case:

            //helper pointer
            std::shared_ptr<Node> tempProot = majorTree.get_proot();
            //case 1: right child has left child:
            if(majorTree.get_proot()->right->left!=nullptr){
                
                BST LeftTree = BST(tempProot->left);
                std::shared_ptr<Node> leftTreeMaxNodePtr=LeftTree.findMaximum();
                        
                
                //1:
                leftTreeMaxNodePtr->right=tempProot->right->left;
                tempProot->right->left->parent=leftTreeMaxNodePtr;

                //2:
                tempProot->left->parent=tempProot->right;
                tempProot->right->left=tempProot->left;
                        
                //3:
                tempProot=tempProot->right;
                
                // //3:
                if(majorTree.get_proot()->parent->getval() < i){
                            majorTree.get_proot()->parent->right=tempProot;
                        }else{
                            majorTree.get_proot()->parent->left=tempProot;
                        }
                
                

                
            }else{
            //case 2: right child has not left child
            
            //set right child as root and delete former root

                         
                        //1:
                        tempProot->left->parent=tempProot->right;
                        tempProot->right->left=tempProot->left;

                        //2:
                        tempProot=tempProot->right;
                        tempProot->parent = majorTree.get_proot()->parent;

                        //3:
                        //whether is this node is right child of his/her parent or left one.
                        if(majorTree.get_proot()->parent->getval() < i){
                            majorTree.get_proot()->parent->right=tempProot;
                        }else{
                            majorTree.get_proot()->parent->left=tempProot;
                        }

            }

        }
    }
    }

}

BST BST::searchAndGetTree(int i){
    if(proot!=nullptr){
        if(proot->val == i){

            //easy easy
            return BST(proot);
        
        }

        if(proot->val > i){

            //it may be in the left tree
            BST leftTree{BST(proot->left)};
            return leftTree.searchAndGetTree(i);
        
        }
        

        if(proot->val < i){

            //it may be in the right tree
            BST rightTree{BST(proot->right)};
            return rightTree.searchAndGetTree(i);
        }
    }
        return BST(nullptr);
    
}

std::shared_ptr<BST::Node> BST::findMaximum(){

    std::shared_ptr<Node> tempPtr{proot};
    
    //we go to right child until get to nullptr
    while(tempPtr->right!=nullptr){
        tempPtr=tempPtr->right;
    }
    return tempPtr;
}