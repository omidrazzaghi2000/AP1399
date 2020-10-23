
#include <memory> //for shared pointer
#include <vector>

class BST{
private:
    class Node{
        public:
            std::shared_ptr<Node> parent{nullptr};
            std::shared_ptr<Node> right{nullptr};
            std::shared_ptr<Node> left{nullptr};
            int val;
            Node(std::shared_ptr<Node> p, std::shared_ptr<Node> r, std::shared_ptr<Node> l);
            Node(int i);
            void show();  //  Prints the value of a node in a single line
    };   
    std::shared_ptr<Node> proot{nullptr};
public:
    BST(const BST& b);
    int root();  //  Returns the root value
    int operator[](int index);
    size_t size();  //  Returns no of elements in BST 
    BST operator+(int i);  //  Adds i to the BST
    bool search(int i);  //  Returns true if the value i is in BST, otherwise false
    std::vector<int> inorder();  //  Inorder traverse of tree
    std::vector<int> preorder();  //  Preorder traverse of tree
    std::vector<int> postorder();  //  Postorder traverse of tree
    void show();  //  Prints the inorder traverse of BST in a single line.
};