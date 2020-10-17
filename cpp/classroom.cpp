#include <iostream>
#include <classroom.h>
#include <random> //normal gaussian random number
#include <chrono> //for generation random number
#include <memory> //shared pointer
#include <iomanip> //for std::setprecision

//constructor of classroom with name and number of sits
Classroom :: Classroom(const char* _name, size_t _seats){
    //name has no exception
    name = _name;

    //seats must not have minus value 
    if(_seats >= 0){
        seats = _seats;    
    }else{
        std::cout 
        << "*****Your enter seats number is not valid******" 
        << std::endl;
    }
    no++;

    //Update classroom temperature
    getTemperature();
}

void Classroom::setRight(std::shared_ptr<Classroom> r){
    right = r;
}

void Classroom::setLeft(std::shared_ptr<Classroom> l){
    left = l;
}

std::shared_ptr<Classroom> Classroom::getRight(){
    return right;
}

std::shared_ptr<Classroom> Classroom::getLeft(){
    return left;
}

double Classroom::getTemperature(){
    //Generate random number with random header file
    //onstruct a trivial random generator engine from a time-based seed:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator (seed);
    //mean: 27 and standard deviation = 3
    std::normal_distribution<double> distribution(27.0,3.0);
    temperature = distribution(generator);
    return temperature;
}

size_t Classroom::noOfSeats(){
    return seats;
}

void Classroom::show() const{
    std::cout 
    << "Class " 
    << this->name 
    << ", Seats: "
    << this->seats 
    << ", Temprature: " 
    << std::fixed << std::setprecision(2) << temperature 
    << std::endl;
}


//extra method declaration
void Classroom::set_seats(size_t _seats){
    seats = _seats;
}

double Classroom::getOnlyTemperature(){
    return temperature;
}