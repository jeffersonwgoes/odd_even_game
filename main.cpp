#include "player.h"
#include "game.h"

using namespace std;


void testClasses(void)
{
    Human human;
    Robot robot;

    cout << "Human Debug functions: " << endl;
    human.setName();
    human.setNumber();
    human.debugPlayer();

    cout << "Robot Debug functions: " << endl;
    robot.setName();
    robot.setNumber();
    robot.debugPlayer();
}

int main(void)
{
#ifndef DEBUG
    Human human;
    Robot robot;
    //showScoreBoard;
    cout << "Press any key to continue...";
    cin.get();
    startTheGame(human, robot);
    runTheGame(human, robot);
    cout << "Press any key to continue ";
    cin.get();
#else
    testClasses();
#endif
    return 0;
}

