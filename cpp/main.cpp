#include <iostream>
#include "aphw2.h"
#include "gtest/gtest.h"

//must bee delete
#include <memory>
#include <classroom.h>

size_t Classroom::no;//we must declare static variable as global variable :(
int main(int argc, char **argv)
{
    //must bee delete
    auto a = std::make_shared<Classroom>("411", 40);
    auto b = std::make_shared<Classroom>("413", 30);
    auto c = std::make_shared<Classroom>("415", 20);

    a->setLeft(c);
    c->setRight(a);
    b->setLeft(a);
    a->setRight(b);
    c->setLeft(b);
    b->setRight(c);
    

    Classroom::get_no();
    
    ::testing::InitGoogleTest(&argc, argv);
    std::cout << "RUNNING TESTS ..." << std::endl;
    int ret{RUN_ALL_TESTS()};
    if (!ret)
        std::cout << "<<<SUCCESS>>>" << std::endl;
    else
        std::cout << "FAILED" << std::endl;
    return 0;
}
