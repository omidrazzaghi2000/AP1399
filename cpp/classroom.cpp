#include <iostream>
#include <classroom.h>
#include <random> //normal gaussian random number
#include <memory>

//constructor of classroom with name and number of sits
Classroom :: Classroom(const char* _name, size_t _seats){
    //name has no exception
    name = _name;

    //seats must not have minus value 
    if(_seats >= 0){
        seats = _seats;    
    }else{
        std::cout << "*****Your enter seats number is not valid******" << std::endl;
    }
    
}

void Classroom::setRight(std::shared_ptr<Classroom> r){
    right = r;
}

void Classroom::setLeft(std::shared_ptr<Classroom> l){
    left = l;
}

double Classroom::getTemperature(){
    //Generate random number with random header file
    std::default_random_engine generator;
    //mean: 27 and standard deviation = 3
    std::normal_distribution<double> distribution(27.0,3.0);
    
    return distribution(generator);
}

size_t Classroom::noOfSeats(){
    return seats;
}

void Classroom::show() const{
    std::cout << "Class " << this->name << ", Seats: "<< this->seats << ", Temprature: " << this->temperature << std::endl;
}

