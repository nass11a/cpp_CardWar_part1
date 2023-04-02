#pragma once

#include <string>
#include <iostream>
#include <vector>

using namespace std;
namespace ariel{
class Player;
};

class ariel::Player{

    private:
     std::string name;



    public:

     Player(const std::string& name){
        this->name = name;
        };

     static int stacksize(){
        return 0;
     }
     static int cardesTaken(){
        return 0;
     }

};