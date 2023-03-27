#include<iostream>
#include "game.hpp"
#include"doctest.h"


TEST_CASE("check game"){

Player p1("Alice");
Player p2("Bob");

Game game(p1,p2); 

CHECK_FALSE(!(p1.stacksize() == 21));

CHECK_FALSE(!(p2.stacksize() == 21));

CHECK_FALSE(!(p1.cardesTaken() == 0 ));

CHECK_FALSE(!(p2.cardesTaken() == 0 ));

CHECK_NOTHROW(game.playTurn());

CHECK_NOTHROW(game.printLastTurn());


if(p1.cardesTaken() == 2  &&  p2.cardesTaken() == 0){
    std::cout << "player 1 won this turn!" << endl;

    CHECK_FALSE(!(p1.stacksize() == 22));
    CHECK_FALSE(!(p2.stacksize() == 20));
 }


 if(p2.cardesTaken() == 2  &&  p1.cardesTaken() == 0){
    std::cout << "player 2 won this turn!" << endl;

    CHECK_FALSE(!(p2.stacksize() == 22));
    CHECK_FALSE(!(p1.stacksize() == 20));
 }


if(p1.cardesTaken() == 0  &&  p2.cardesTaken() == 0){
     std::cout << "draw!" << endl;

    if(p1.cardesTaken() == 3  &&  p2.cardesTaken() == 0){
        CHECK_FALSE(!(p1.stacksize() == 24));
        CHECK_FALSE(!(p2.stacksize() == 18));

    };

    if(p1.cardesTaken() == 3  &&  p2.cardesTaken() == 0){
        CHECK_FALSE(!(p2.stacksize() == 24));
        CHECK_FALSE(!(p1.stacksize() == 18));
    }

      if(p1.cardesTaken() == 0  &&  p2.cardesTaken() == 0){
             std::cout << "another draw!" << endl;
               CHECK_FALSE(!(p2.stacksize() == 18));
               CHECK_FALSE(!(p1.stacksize() == 18));
    }
 }

    CHECK_NOTHROW(game.playAll()); 

    CHECK_NOTHROW(game.printWiner());


    if(p1.stacksize() == 0){
        std::cout << "player 2 won the game!" << endl;

        CHECK_FALSE(!(p2.stacksize() > 0 ));
    }

    if(p2.stacksize() == 0){
        std::cout << "player 1 won the game!" << endl;

        CHECK_FALSE(!(p1.stacksize() > 0 ));
    }

    CHECK_NOTHROW(game.printLog());
      
    CHECK_NOTHROW(game.printStats());

    CHECK_THROWS(game.playTurn());

    CHECK_THROWS(game.playAll());
    
}


TEST_CASE("if draw continue"){

Player p1("Alicea");
Player p2("Boba");

Game game(p1,p2); 

CHECK_FALSE(!(p1.stacksize() == 21));

CHECK_FALSE(!(p2.stacksize() == 21));

CHECK_FALSE(!(p1.cardesTaken() == 0 ));

CHECK_FALSE(!(p2.cardesTaken() == 0 ));

CHECK_NOTHROW(game.playTurn());

CHECK_NOTHROW(game.printLastTurn());

 if(p1.cardesTaken() == 2  &&  p2.cardesTaken() == 0){


    std::cout << "player 1 won this turn!" << endl;

    CHECK_FALSE(!(p1.stacksize() == 22));
    CHECK_FALSE(!(p2.stacksize() == 20));

    CHECK_FALSE(!(p1.cardesTaken() == 1));
    CHECK_FALSE(!(p2.cardesTaken() == -1));

     game.playTurn();


 if(p1.cardesTaken() == 2  &&  p2.cardesTaken() == 0){
     std::cout << "player 1 won another turn!" << endl;

    CHECK_FALSE(!(p1.stacksize() == 23));
    CHECK_FALSE(!(p2.stacksize() == 19));


    CHECK_FALSE(!(p1.cardesTaken() == 2));
    CHECK_FALSE(!(p2.cardesTaken() == -2));
 }


 if(p2.cardesTaken() == 2  &&  p1.cardesTaken() == 0){
    std::cout << "player 2 won this turn!" << endl;

    CHECK_FALSE(!(p1.stacksize() == 21));
    CHECK_FALSE(!(p2.stacksize() == 21));

    CHECK_FALSE(!(p1.cardesTaken() == 0));
    CHECK_FALSE(!(p2.cardesTaken() == 0));
 }


 if(p1.cardesTaken() == 0  &&  p2.cardesTaken() == 0){
     std::cout << "draw!" << endl;

    if(p1.cardesTaken() == 3  &&  p2.cardesTaken() == 0){
        CHECK_FALSE(!(p1.stacksize() == 25));
        CHECK_FALSE(!(p2.stacksize() == 17));

        CHECK_FALSE(!(p1.cardesTaken() == 4));
        CHECK_FALSE(!(p2.cardesTaken() == -4));
    };

    if(p2.cardesTaken() == 3  &&  p1.cardesTaken() == 0){
        CHECK_FALSE(!(p1.stacksize() == 19));
        CHECK_FALSE(!(p2.stacksize() == 23));

        CHECK_FALSE(!(p1.cardesTaken() == -2));
        CHECK_FALSE(!(p2.cardesTaken() == 2));
    }

      if(p1.cardesTaken() == 0  &&  p2.cardesTaken() == 0){
             std::cout << "another draw!" << endl;
    }

 }


 }



 if(p2.cardesTaken() == 2  &&  p1.cardesTaken() == 0){


    std::cout << "player 2 won this turn!" << endl;

    CHECK_FALSE(!(p2.stacksize() == 22));
    CHECK_FALSE(!(p1.stacksize() == 20));

    CHECK_FALSE(!(p2.cardesTaken() == 1));
    CHECK_FALSE(!(p1.cardesTaken() == -1));

     game.playTurn();


 if(p2.cardesTaken() == 2  &&  p1.cardesTaken() == 0){
     std::cout << "player 1 won another turn!" << endl;

    CHECK_FALSE(!(p2.stacksize() == 23));
    CHECK_FALSE(!(p1.stacksize() == 19));


    CHECK_FALSE(!(p2.cardesTaken() == 2));
    CHECK_FALSE(!(p1.cardesTaken() == -2));
 }


 if(p1.cardesTaken() == 2  &&  p2.cardesTaken() == 0){
    std::cout << "player 1 won this turn!" << endl;

    CHECK_FALSE(!(p2.stacksize() == 21));
    CHECK_FALSE(!(p1.stacksize() == 21));

    CHECK_FALSE(!(p2.cardesTaken() == 0));
    CHECK_FALSE(!(p1.cardesTaken() == 0));
 }


 if(p2.cardesTaken() == 0  &&  p1.cardesTaken() == 0){
     std::cout << "draw!" << endl;

    if(p2.cardesTaken() == 3  &&  p1.cardesTaken() == 0){
        CHECK_FALSE(!(p2.stacksize() == 25));
        CHECK_FALSE(!(p1.stacksize() == 17));

        CHECK_FALSE(!(p2.cardesTaken() == 4));
        CHECK_FALSE(!(p1.cardesTaken() == -4));
    };

    if(p1.cardesTaken() == 3  &&  p2.cardesTaken() == 0){
        CHECK_FALSE(!(p2.stacksize() == 19));
        CHECK_FALSE(!(p1.stacksize() == 23));

        CHECK_FALSE(!(p2.cardesTaken() == -2));
        CHECK_FALSE(!(p1.cardesTaken() == 2));
    }

      if(p2.cardesTaken() == 0  &&  p1.cardesTaken() == 0){
             std::cout << "another draw!" << endl;
    }

 }


 }
}