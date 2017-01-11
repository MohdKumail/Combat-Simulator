#include <iostream>
#include <random>
#include <ctime>
#include <string>
#include "Game.h"

int main()
{
    std::default_random_engine randomEngine(time(0));
    std::uniform_real_distribution<float> attack(0.0f,2.0f);

    std::default_random_engine randomEngine1(time(0));
    std::uniform_real_distribution<float> attackSketletons(0.0f,1.0f);

    //local variables
    float attackResult;
    int a = 0 ;
    int b = 0;
    int c = 0;
    int d = 0;
    std::string name = "";
    char turn ;

    //objects
    Game gameOn(a,b,c,d,name);

    gameOn.PrintMe();

    //user name
    name = gameOn.getUserName();

    //user choice
    int userChoice =  gameOn.getUserChoice();

    // humans vs zombies
    if(userChoice == 1)
    {

        turn = 'H';

      //human varialbes
        float maxHumanHealth = 250.0f;
        float humanDamage = 200.0f;
        float humanAttack = 0.8f;
        float currentHumanHealth = maxHumanHealth;
        int numHumans;
        int startHumans;

        //zombie variables
        float maxZombieHealth = 100.0;
        float zombieDamage = 60.0f;
        float zombieAttack = 0.5f;
        float currentZombieHealth = maxZombieHealth;
        int numZombies;
        int startZombies;

        //get user input for humnans
        numHumans = gameOn.getHumans();
        startHumans = numHumans;

        //get user input for zombies
        numZombies = gameOn.getZombies();
        startZombies = numZombies;

        std::cout<<"-------------------BATTLE BEGIN-------------------"<< std::endl;

        while(numHumans>0 && numZombies>0)
        {
            //initiate the attack
            attackResult = attack(randomEngine);
            //turn of humans
            if(turn=='H')
            {
                //check the attack if succesful
                if(attackResult<=humanAttack)
                {
                    currentZombieHealth -= humanDamage;
                    //check if a zombie is dead
                    if(currentZombieHealth<=0)
                    {
                        numZombies--;
                        currentZombieHealth = maxZombieHealth;
                    }
                }

                //switch the turn to zombie
                turn = 'Z';
            }else   //if not humans turn then switch to zombie
            {
                    //check the attack if succesfull
                if(attackResult<=zombieAttack)
                {
                    currentHumanHealth -= zombieDamage;
                    //check if the humans is dead
                    if(currentHumanHealth <= 0 )
                    {
                            numHumans--;
                            currentHumanHealth = maxHumanHealth;
                    }
                }

                //switch the turn back to the Human
                turn = 'H';
            }
        }

        std::cout<<"-------------------BATTLE OVER-------------------"<< std::endl;

        //Print Winner
        gameOn.printInfo(numHumans,numZombies,startHumans,startZombies);

    }

    //humans vs skeletons
    else
    {
        //human properties
        float maxHumanHealth = 200.0f;
        float currentHumanHealth = maxHumanHealth;
        float humanAttack = 0.5f;
        float humanDamage = 160.0f;
        int numHuman;
        int startHuman;

        //skeleton properties
        float maxSkeletonHealth = 100.0f;
        float currentSkeletonHealth = maxSkeletonHealth;
        float skeletonAttack = 0.1f;
        float skeletonDamage = 20.0f;
        int numSkeletons;
        int startSkeletons;

        //get input for humans
        numHuman = gameOn.getHumans();
        startHuman = numHuman;

        //get input for zombies
        numSkeletons = gameOn.getSkeletons();
        startSkeletons = numSkeletons;

        turn = 'H';

        std::cout << "-------------------BATTLE BEGIN-------------------" << std::endl;

        while (numHuman > 0 && numSkeletons > 0) {
            attackResult = attackSketletons(randomEngine1);
            //check thr turn
            if (turn == 'H') {
                //check if hit successful
                if (attackResult <= humanAttack) {
                    currentSkeletonHealth -= humanDamage;
                    //check if dead
                    if (currentSkeletonHealth <= 0) {
                        numSkeletons--;
                        currentSkeletonHealth = maxSkeletonHealth;
                    }
                }
                //switch the trun to skeletons
                turn = 'S';
            } else   //turn of skeletons
            {
                if (attackResult <= skeletonAttack) {
                    currentHumanHealth -= skeletonDamage;
                    //check if the human is dead
                    if (currentHumanHealth <= 0) {
                        numHuman--;
                        currentHumanHealth = maxHumanHealth;
                    }
                }

                //switch back to human
                turn = 'H';
            }
        }

        std::cout << "-------------------BATTLE OVER-------------------" << std::endl;
        //winner and print info
        gameOn.printInfoSkeletons(numHuman, numSkeletons, startHuman, startSkeletons);

    }

    return 0;
}