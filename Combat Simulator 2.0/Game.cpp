
#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include "Game.h"

//game constructor
Game::Game(int a,int b,int c,int d,std::string abc)
{
    numHumans = a;
    numZombies = b;
    userChoice = c;
    numSkeletons = d;
    name = abc;

}
//get username function
std::string Game::getUserName()
{
    std::cout<<"Enter your name: ";
    getline(std::cin,name);
    return name;
}
//print choice games
void Game::PrintMe()
{
    std::cout<<"1-HUMANS VS ZOMBIES"<< std::endl;
    std::cout<<"2-HUMANS VS SKELETONS"<<std::endl;
}
//get user choice
int Game::getUserChoice()
{
    std::cout<<"Enter your choice: ";
    std::cin>>userChoice;
    return userChoice;
}
//get number of humans
int Game::getHumans()
{
    std::cout<<"Enter number of humans: ";
    std::cin>>numHumans;
    return numHumans;
}
//get num zombies
int Game::getZombies()
{
    std::cout<<"Enter number of zombies: ";
    std::cin>>numZombies;
    return numZombies;
}
//print infomation of game
void Game::printInfo(int x, int y, int a, int b)
{
    if(x>0)
    {
        std::cout<<"YAY HUMANS WON!!!"<< std::endl;
        std::cout<<"Humans left: "<<x<<std::endl;
        std::cout<<"Zombies: "<<y<<std::endl;
    }
    else
    {
        std::cout<<"OMG ZOMBIES WON!!!"<< std::endl;
        std::cout<<"Zombies left: "<<y<<std::endl;
        std::cout<<"Humans left: "<<x<<std::endl;
    }


    //kill counter
    std::cout<<"Statics:-\n";
    std::cout<<a-x<<" HUMANS LOST THERE LIVES!!!"<<std::endl;
    std::cout<<b-y<<" ZOMBIES LOST THERE LIVES!!!!!"<<std::endl;
}

//get number of skeletons
int Game::getSkeletons()
{
    std::cout<<"Enter number of Skeletons: ";
    std::cin>>numSkeletons;
    return numSkeletons;
}
//print infomation od humans vs skeletons
void Game::printInfoSkeletons(int x, int y, int a, int b)
{
    if(x>0)
    {
        std::cout<<"YAY HUMANS WON!!!"<< std::endl;
        std::cout<<"Humans left: "<<x<<std::endl;
        std::cout<<"Skeletons left: "<<y<<std::endl;
    }
    else
    {
        std::cout<<"OMG SKELETONS WON!!"<< std::endl;
        std::cout<<"Skeletons left: "<<y<<std::endl;
        std::cout<<"Humans left: "<<x<<std::endl;
    }

    //statics
    std::cout<<"Statics:-"<<std::endl;
    std::cout<<a-x<<" Humans lost their lives."<<std::endl;
    std::cout<<b-y<<" Skeletons lost there lives."<<std::endl;
}

