#include <iostream>
#include <memory>
#include <floor.h>
#include <classroom.h>

//static object must initialize global
size_t Classroom::no;

void show(Classroom classroom){
    classroom.show();
}

void show(Floor floor){
    floor.show();
}