#ifndef __SCOREBOARD_H__
#define __SCOREBOARD_H__

class ScoreEntry {
    private:
        std::string Name;
        std::string datatime;
        int score;
    public:
        ScoreEntry(std::string line);

        std::string getName() const{
            return Name;
        }
        std::string getFormatedDate() const {
            return datatime;
        }
        int getScore() const {
            return score;
        }
};

class ScoreBoard {
    private:
        std::list<ScoreEntry> scoreDiff;
        std::list<ScoreEntry> scoreWins;
    public:
        ScoreBoard();
        void printScores();
        void AddEntry(Player &winner, Player &loser);
};
#endif