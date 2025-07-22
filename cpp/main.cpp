#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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

int main(void)
{
    FileManagement file("lala.txt");
    file.print_file();
    file.blabla();
    file.save();
    return 0;
}