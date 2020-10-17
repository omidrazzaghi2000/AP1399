#include <iostream>
#include <floor.h>
#include <classroom.h>
#include <memory> //shared pointer
#include <vector> //vector 
#include <iomanip> // setprecision 
Floor::Floor(const char* _name, std::shared_ptr<Classroom> _pc){
    //name has no limitation
    name = _name;

    //this pointer must point to Classroom variable but it was checked before
    pc = _pc;

    //for updating 
    getTemperature();
    noOfClasses();
    noOfSeats();

}

size_t Floor::noOfClasses(){
    //save first class pointer to temp_pc
    std::shared_ptr<Classroom> temp_pc {pc};
    size_t ClassCounter{0};
    while(temp_pc->getRight() != pc/*until we loop over all classes*/){
        ClassCounter++;
        temp_pc = temp_pc->getRight();//set refrence pointer to right class
    }
    //for last class
    if(temp_pc->getRight() == pc){
        ClassCounter++;
    }
    no_of_classes = ClassCounter;
    return no_of_classes;
}

void Floor::show() const{
    std::cout
        <<"Floor: "
        << this->name 
        << std::endl
        << "\tAverage temperature: "
        << std::fixed << std::setprecision(2) << AverageTemperature
        << std::endl
        << "\tNo of classes: "
        << no_of_classes
        << std::endl;

        //print class list
        
        /*
        because we are in the const function so we can not use one pointer 
        hence , we can use vector of pointer.
        */
        std::vector<std::shared_ptr<Classroom>> pc_vector;
        size_t ClassIndex{0};
        pc_vector.push_back(pc);
        while( ClassIndex < no_of_classes/*until we loop over all classes*/){
            std::cout << "\t";//as intent for printing
            pc_vector.at(ClassIndex)->show();
            ClassIndex++;
            pc_vector.push_back(pc_vector.at(ClassIndex-1)->getRight());
        }
        
}

//number of whole class seats 
size_t Floor::noOfSeats(){
    //save first class pointer to temp_pc
    std::shared_ptr<Classroom> temp_pc {pc};
    size_t SeatsCounter {0};
    while(temp_pc->getRight() != pc /*until we loop over all classes*/){
        SeatsCounter = SeatsCounter + temp_pc->noOfSeats();
        temp_pc = temp_pc->getRight();//set refrence pointer to right class
    }
    //for last class
    if(temp_pc->getRight() == pc){
        SeatsCounter = SeatsCounter + temp_pc->noOfSeats();
    }
    no_of_all_seat = SeatsCounter;
    return no_of_all_seat;
};

std::shared_ptr<Classroom> Floor::operator[](int i){
    std::shared_ptr<Classroom> pt_desired_classroom{pc};
    if(i > 0){
        //forward
        while(i != 0){
            pt_desired_classroom = pt_desired_classroom->getRight();
            i--;
        }
    }else{
        //backward
        while(i != 0){
            pt_desired_classroom = pt_desired_classroom->getLeft();
            i++;
        }
    }
    return pt_desired_classroom;
}

//number of i-th class
size_t Floor::noOfSeats(int i){
    //save first class pointer to temp_pc
    return this->operator[](i)->noOfSeats();
}

double Floor::getTemperature(){
    //save first class pointer to temp_pc
    std::shared_ptr<Classroom> temp_pc{pc};
    double Summation_of_Temperature{0};
    while(temp_pc->getRight() != pc /*until we loop over all classes*/){
        Summation_of_Temperature = Summation_of_Temperature + temp_pc->getOnlyTemperature();
        temp_pc = temp_pc->getRight();//set refrence pointer to right class
    }
    //for last classroom
    if(temp_pc->getRight() == pc){
        Summation_of_Temperature = Summation_of_Temperature + temp_pc->getOnlyTemperature();
    }
    
    AverageTemperature = (double)(Summation_of_Temperature)/(double)(this->noOfClasses());    
    return  AverageTemperature;
    // return double(Summation_of_Temperature/(this->noOfClasses()));
}

void Floor::setPointer(std::shared_ptr<Classroom> a){
    //change the refrence of pointer 
    pc = a;
}

bool Floor::moveSeats(int source,int dest,size_t no){
    //find source and destination in this floor
    std::shared_ptr<Classroom> pc_source_classroom = this->operator[](source);
    std::shared_ptr<Classroom> pc_destination_classroom = this->operator[](dest);

    //does source class have enough seats
    if(pc_source_classroom->noOfSeats() > no){
        pc_source_classroom->set_seats(pc_source_classroom->noOfSeats() - no);
        pc_destination_classroom->set_seats(pc_destination_classroom->noOfSeats() + no);
        return true;
    }else{
        return false;
    }

}