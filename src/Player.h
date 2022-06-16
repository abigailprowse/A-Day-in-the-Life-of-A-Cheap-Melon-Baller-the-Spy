
#ifndef PLAYER_H
#define PLAYER_H 

#include <iostream>
#include <vector>
//#include "Enemy.h"
#include "GetData.h"


class Player { 
  // player class.

  public: // yeah yeah everyone can view
    // Constructor
    Player(std::string playerName); // will be the player creation
    // getters
    std::string getName(); // if we want to get name of player
    int getAttack(); // get the amount for a specific attack
    int getDefense(); // get the defense of player
    int getAccuracy(); // get the accuracy of the player
    int getHP(); // get health
    int getMoney(); // get money
    int getBonus(); //get bonus
    std::string getAttackName();// get the attack name.

    //Enemy Object within an Object
    //Enemy e;
//(std::string, int, int, int, int); 
    //Enemy e("somebody", 1, 1, 1,);

    // actions
    //void attackEnemy(Enemy e);
    //void attackEnemy(Enemy e); // attacks the enemy by attack determined by the move chosen by the player.
    void loseHP(int damage); // this what occurs when the enemy attacks the player.
    void chooseMove(); // choose the move from move set.
    void printMoves(); // print the player's current moveset.
    int useItem(); // returns the item being used
    // upgrades
    void updateAttack(int increment); // increase the base attack damage.
    void updateDefense(int increment); // improve base defense
    void updateAccuracy(int increment); // update the base accuracy.
    void updateMoney(int increment); // update the amount of money the player has
    void updateInventory(int index, int incriment); // update the inventory of the player

    void setAttack(int num);

    int getBonusType();

    int getSelectedMove();

    void setAccuracy(int num);

    void setBonus(int num); //bonus

    void setBonusType(int num);

    void updateHP(int num);

    void resetStats(); //reset stats

    void resetInventory(); //reset inventory
    
    // Deconstructor
    ~Player(){};
  
  private: // nuh-uh only for the class cuz we're *special*
    // variables
    std::string name; // name of player
    int attack;    // attack when you consider accuracy and baseAttack together!
    int defense; // defense
    int hp; // health lol
    int accuracy; // this is the accuracy of player
    int money; // how much money the player has
    int selectedMove; // number according to menu of the selected move.
    int bonusType;    // denotes what type of bonus is being applied.
    int bonus; //bonus added on for the tiems 
    std::vector<std::string> items; // items user has
    std::vector<int> itemAmounts;   // amounts of items user has

    std::vector<std::string> moves; // these are the moves of the user.
};


#include "Enemy.h"
void attackEnemy(Player&, Enemy &);
#endif