#include "player.h"
#include "game.h"
#include <iostream>

void printScore(Player &p1, Player &p2)
{
    std::cout << p1.getName() << " (" << p1.getScore() << ") vs " << p2.getName() << " (" << p2.getScore() << ")" << std::endl;
}

void startTheGame(Player &p1, Player &p2) 
{
    p1.setName();
    p2.setName();
    system("clear");
    std::cout << "_\\|/_ Game starts _\\|/_" << std::endl;
    std::cout << p1.getName() << " vs " << p2.getName() << std::endl;
}

void playOneRound(Player &p1, Player &p2) 
{
    char curr_oddeven = p2.getOddEven();
    printScore(p1, p2);
    std::cout << p2.getName() << " chose " << (curr_oddeven == 'E' ? "Even" : "Odd") << std::endl;

    p1.setNumber();
    p2.setNumber();

    std::cout << p1.getName() << " played " << p1.getNumber() << std::endl;
    std::cout << p2.getName() << " played " << p2.getNumber() << std::endl;
    int sum = p1.getNumber() + p2.getNumber();

    if((sum % 2) == 0) { // even wins
        if (curr_oddeven == 'E') {
            p2.setScore(p2.getScore() + 1);
            std::cout << p2.getName() << " won the round" << std::endl;
        } else {
            p1.setScore(p1.getScore() + 1);
            std::cout << p1.getName() << " won the round" << std::endl;
        }
    } else { //odd wins
        if (curr_oddeven == 'O') {
            p2.setScore(p2.getScore() + 1);
            std::cout << p2.getName() << " won the round" << std::endl;
        } else {
            p1.setScore(p1.getScore() + 1);
            std::cout << p1.getName() << " won the round" << std::endl;
        }
    }
    system("clear");
}

void runTheGame(Player &p1, Player &p2)
{
    for (int round = 0; (p1.getScore() < 10) && (p2.getScore() < 10); round++) {
        playOneRound(p1, p2);
    }
    system("clear");
    std::cout << ((p1.getScore() == 10) ? p1.getName() : p2.getName()) << " won the game " << std::endl;
}