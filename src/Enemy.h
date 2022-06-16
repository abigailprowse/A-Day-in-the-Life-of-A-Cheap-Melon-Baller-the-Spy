#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <vector>
//#include "Player.h"

class Enemy {
  // enemy class.

  public: // yeah yeah everyone can view
    // Constructor
    Enemy(std::string enemyName, int defenseStart, int hpStart, int accuracyStart); // will be the enemy creation

    // getters
    std::string getName(); // if we want to get name of enemy
    int getAttack(); // get the amount for a specific attack
    int getDefense(); // get the defense of enemy
    int getAccuracy(); // get the accuracy of the enemy
    int getHP(); // get health
    void updateAttack(int increment); // increase the base attack damage.
    void updateDefense(int increment); // improve base defense
    void updateAccuracy(int increment); // update the base accuracy.
    std::string getAttackName(); // get the attack name.

    // actions
    //void attackEnemy(Player p); // attacks the player by attack determined by the move chosen by the player.
    void loseHP(int damage); // this what occurs when the player attacks the enemy.
    void chooseMove(); // choose the move from move set.

    void setAttack(int num);

    int getBonusType();

    int getSelectedMove();

    int setAccuracy(int num);

    // Deconstructor
    ~Enemy() {};

  private: // nuh-uh only for the class cuz we're *special*
    // variables

    std::string name; // name of enemy
    int attack; // attack when you consider accuracy and baseAttack together!
    int defense; // defense
    int hp; // health lol
    int accuracy; // this is the accuracy of enemy 
    int selectedMove; // move index of the move randomly selected for the enemy

    std::vector <std::string> moves; // these are the moves of the enemy.
};

#include "Player.h" //inclyde player file and add the static stuff
void attackPlayer(Enemy &, Player &);
#endif