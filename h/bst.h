
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
            //extra method that we need to make node
            Node(int i , std::shared_ptr<Node> p, std::shared_ptr<Node> r, std::shared_ptr<Node> l);
            void show();  //  Prints the value of a node in a single line
            int getval(){
                return val;
            }
    };   
    std::shared_ptr<Node> proot{nullptr};
    
public:
    BST(const BST& b);
    //------------Extra Method----------
    //default constructor
    BST()=default;
    BST(std::shared_ptr<Node> _proot);
    //----------------------------------
    int root();  //  Returns the root value
    int operator[](int index);
    size_t size();  //  Returns no of elements in BST 
    BST operator+(int i);  //  Adds i to the BST
    bool search(int i);  //  Returns true if the value i is in BST, otherwise false
    std::vector<int> inorder();  //  Inorder traverse of tree
    std::vector<int> preorder();  //  Preorder traverse of tree
    std::vector<int> postorder();  //  Postorder traverse of tree
    void show();  //  Prints the inorder traverse of BST in a single line.

    //---------------extra methods----------------
    BST* add(int );
    void remove(int );

    //get shared pointer to root
    std::shared_ptr<Node> get_proot(){
        return proot;
    }
    

    //--------------------------------------------

};