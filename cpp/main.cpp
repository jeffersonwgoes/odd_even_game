#include <iostream>
#include <list>
#include "scoreboard.h"
#include "player.h"
#include "game.h"


void testClasses(void)
{
    Human human;
    Robot robot;

    std::cout << "Human Debug functions: " << std::endl;
    human.setName();
    human.setNumber();
    human.debugPlayer();

    std::cout << "Robot Debug functions: " << std::endl;
    robot.setName();
    robot.setNumber();
    robot.debugPlayer();
}

int main(void)
{
#ifndef DEBUG
    while(1) {
        system("clear");
        ScoreBoard scores;
        scores.printScores();
        Human human;
        Robot robot;
        
        std::cout << "Press any key to continue..." << std::endl;
        std::cin.get();
        startTheGame(human, robot);
        runTheGame(human, robot);
    }
#else
    testClasses();
#endif
    return 0;
}

