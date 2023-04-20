#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <algorithm>
#include <chrono>
#include <ctime>
#include <iomanip>
#include "player.h"
#include "scoreboard.h"

std::string getCurrentTime()
{
    auto now = std::chrono::system_clock::now();
    std::time_t now_c = std::chrono::system_clock::to_time_t(now);
    std::tm* now_tm = std::localtime(&now_c);

    std::stringstream ss;
    ss << std::put_time(now_tm, "%Y-%m-%d %H:%M");
    std::string datetime_str = ss.str();
    return datetime_str;
}

ScoreEntry::ScoreEntry(std::string line) 
{
    std::stringstream ss(line);  
    std::string word[3];
    for (int i = 0;std::getline(ss, word[i], ';'); i++);/* {
        std::cout << "w: " << word[i] << std::endl;
    }*/
    Name = word[1];
    datatime = word[0];
    //score = stoi(word[2]);
}

ScoreBoard ::ScoreBoard() 
{
    std::string line;
    std::ifstream infile("scoreboarddiff.txt");
    for(int i = 0; std::getline(infile, line); i++) {
        scoreDiff.push_back(ScoreEntry(line));
    }
    infile.close();

    std::ifstream infile2("scoreboardwins.txt");
    for(int i = 0; std::getline(infile2, line); i++) {
        scoreWins.push_back(ScoreEntry(line));
    }
    infile2.close();

    std::cout << "ALO: " << getCurrentTime() << std::endl;

    /*while(!scoreDiff.empty()) {
        auto x = scoreDiff.back();
        scoreDiff.pop_back();
        std::cout << "l: " << x.getScore();
    }*/
}


void ScoreBoard::AddEntry(Player &winner, Player &loser)
{
    std::stringstream ss;
    ss << winner.getName() << ";" << getCurrentTime() << ":" << winner.getScore();
    scoreWins.push_back(ScoreEntry(ss.str()));
}

void ScoreBoard::printScores() 
{
    std::cout << "------Score By Wins-------" << std::endl;
    int s = 1;
    std::cout << "Pos - name - Datetime - Score" << std::endl;
    for (auto const& i : scoreWins) {
        std::cout <<  s++ << " - " <<  i.getName() << " - " << i.getFormatedDate() << " - " << i.getScore() << std::endl;
    }
    std::cout << "--------------------------" << std::endl;
    std::cout << "------Score By Diff-------" << std::endl;
    s = 1;
    std::cout << "Pos - name - Datetime - Score" << std::endl;
    for (auto const& i : scoreDiff) {
        std::cout <<  s++ << " - " <<  i.getName() << " - " << i.getFormatedDate() << " - " << i.getScore() << std::endl;
    }
}