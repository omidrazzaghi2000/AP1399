#include "bst.h"
#include <iostream>

BST::Node::Node(int i){
    val=i;
}
BST::Node::Node(std::shared_ptr<Node> p, std::shared_ptr<Node> r, std::shared_ptr<Node> l){
    //there is no limitaion to assigning these parametere
    parent=p;
    right=r;
    left=l;
}
void BST::Node::show(){
    std::cout 
    << "Node with value"
    << val
    << std::endl;
}

