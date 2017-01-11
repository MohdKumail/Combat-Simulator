

#ifndef COMBAT_SIMULATOR_2_0_GAME_H
#define COMBAT_SIMULATOR_2_0_GAME_H


class Game
{
public:
    Game(int a,int b,int c,int d,std::string abc);
    void PrintMe();
    int getUserChoice();
    int choice();
    int getHumans();
    std::string getUserName();
    int getSkeletons();
    int getZombies();
    void printInfo(int x,int y,int a,int b);
    void printInfoSkeletons(int x,int y, int a,int b);
private:
    int numHumans;
    int numZombies;
    int userChoice;
    int numSkeletons;
    std::string name;
};


#endif
