#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
/*

File management
Create a class to manage files, it will keep a copy in the memory and it will be saved when called save()
Create methods to load a file from the disk
The file can be accessed line by line (string vector)
Save the file
*/

class FileManagement {
    public:
        FileManagement(std::string filePath);
        void print_file(void);
        void save(void);
        void blabla(void);
        std::vector<std::string> get_lines(void);
    private:
        std::string path;
        std::vector<std::string> lines;

};

FileManagement::FileManagement(std::string filePath)
{
    path = filePath;
    std::ifstream filep(path);
    std::string line;
    while (std::getline(filep, line)) {
        lines.push_back(line);
    }
    filep.close();
}

void FileManagement::print_file(void)
{
    for (std::string line : lines) {
        std::cout << line;
    }
}

void FileManagement::save(void)
{
    std::ofstream filep(path);
    for(std::string line: lines)
    {
        filep << line;
    }

    filep.close();
}

void FileManagement::blabla(void)
{
    // for(int i = 0; i < 5; i++)
    // {
    //     lines.push_back("bla");
        lines.clear();
    // }
}

std::vector<std::string> FileManagement::get_lines(void)
{
    return lines;
}

struct Score {
    std::string name;
    int score;
};

class Scoreboard {
    public:
        Scoreboard();
        void add_highscore(int score);
        bool is_highscore(int score);
        void print_scores(void);
    private:
        std::vector<Score> scores;      
        FileManagement *file_scores;
        Score parse_line(std::string);
        void print_score(Score s);
};

Scoreboard::Scoreboard()
{
    file_scores = new FileManagement("scoreboard.txt");
    for(std::string line : file_scores->get_lines()) 
    {
        scores.push_back(parse_line(line));
    }
}

Score Scoreboard::parse_line(std::string str)
{
    Score ret = {};
    std::stringstream ss (str);
    std::string item;
    getline(ss, item, ',');
    ret.name = item;
    getline(ss, item, ',');
    ret.score = std::stoi(item);

    return ret;
}

void Scoreboard::print_score(Score s)
{
    
    std::cout << s.name << " " << s.score << std::endl;
}

void Scoreboard::print_scores(void)
{
    for (auto score : scores) 
    {
        print_score(score);
    }
}

// void Scoreboard::is_highscore(int score)
// {

// }

// void Scoreboard::add_highscore(int)
// {
    
// }

int main(void)
{
    Scoreboard *scr = new Scoreboard();
    scr->print_scores();
    return 0;
}