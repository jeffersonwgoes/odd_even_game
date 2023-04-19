#include "player.h"

void Robot::setName(void) 
{
    const int names_max = 20;
    FILE *pFile = fopen("names.txt", "r");
    char names[names_max][15];
    char aux[15];
    for( int i = 0; fgets(names[i], sizeof(names[i]), pFile) != nullptr; i++);
    name = (std::string) names[3];
    name.erase(name.find('\n'), name.length());
}

void Robot::setNumber(void)
{
    number = 2;
}

char Robot::getOddEven()
{
    return 'E';
}

void Human::setNumber (void) 
{
    do {
        std::cout << "Number between 0 and 10: ";
        std::cin >> number;
        if ((number > 10) && (number < 0)) { //treat invalid values
            std::cout << "The number should be between 0 and 10!!" << std::endl;
        }
    } while ((number > 10) && (number < 0));
}

void Human::setName()
{
    std::cout << "Enter a name: ";
    std::cin >> name;
}

char Human::getOddEven()
{
    char oddenven;
    do {
        std::cout << "[O] for Odds and [E] even: ";
        std::cin >> oddenven;
        oddenven = toupper(oddenven);
    } while ( (oddenven != 'E') && (oddenven != 'O') );
    return oddenven;
}