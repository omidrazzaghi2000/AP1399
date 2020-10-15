#ifndef CLASSROOM_H
#define CLASSROOM_H
#include <memory>


class Classroom {

private:
    std::string name{};
    size_t seats{20};  //  No of seats of the class
    std::shared_ptr<Classroom> left;  // A smart pointer to the class to the left of this class
    std::shared_ptr<Classroom> right;  // A smart pointer to the class to the right of this class
    double temperature{27};

public:
    Classroom(const char* _name, size_t _seats);
    std::shared_ptr<Classroom> getRight();
    std::shared_ptr<Classroom> getLeft();
    void setRight(std::shared_ptr<Classroom> r);
    void setLeft(std::shared_ptr<Classroom> l);
    double getTemperature();
    size_t noOfSeats();
    void show();
};

#endif