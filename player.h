#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <iostream>

class Player {
    protected:
        std::string name;
        int score;
        int number;
    public:
        Player() {
            score = 0;
            number = 0;
        }
        virtual void setName() = 0;
        virtual void setNumber(void) = 0;
        virtual char getOddEven(void) = 0;

        void setScore(int playerScore) {
            score = playerScore;
        }

        std::string getName(void) {
            return name;
        }
        int getScore(void) {
            return score;
        }
        int getNumber(void) {
            return number;
        }
        void debugPlayer(void) {
            std::cout << "[DEBUG]Name: " << name << " Score: " << score << " Number: " << number << std::endl;
        }
};

class Robot : public Player {
    public:
        void setName(void);
        void setNumber(void);
        char getOddEven(void);
};

class Human : public Player {
    public: 
        void setNumber (void);
        void setName();
        char getOddEven(void);
};

#endif