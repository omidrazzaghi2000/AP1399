#ifndef FLOOR_H
#define FLOOR_H
#include <memory>// shared_pointer
#include <classroom.h>

class Floor{

private:
    size_t no_of_classes;
    std::string name{};
    std::shared_ptr<Classroom> pc;  // pointer to one of the classes in the floor

    /*
    because show is constant and we can not use get Temperature
    Therefore we add private member AverageTemperature in Floor class
    to use it in show function.
    */
    double AverageTemperature;
    size_t no_of_all_seat;
public:
    Floor(const char* name, std::shared_ptr<Classroom> pc);
    size_t noOfClasses();
    void show() const;
    std::shared_ptr<Classroom> operator[](int i);
    bool moveSeats(int source, int dest, size_t no);  // source and dest are indices of classrooms
    size_t noOfSeats(int i);  // No of seats of the i-th class starting from pc
    size_t noOfSeats();  // No of seats of the whole floor
    double getTemperature();  // Average of temperature of all the classes
    void setPointer(std::shared_ptr<Classroom> a); // Sets the pc to another class in the floor

};

#endif