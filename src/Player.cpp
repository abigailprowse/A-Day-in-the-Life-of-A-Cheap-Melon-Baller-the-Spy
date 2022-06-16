using namespace std;

#include "Player.h"
#include "stdlib.h"
#include "time.h"
//#include "Enemy.h"

// Constructor
Player::Player(string playerName) {
  // will be the player creation

  name = playerName; // name is something set later.
  attack = 0; // attack when you consider accuracy and
  defense = 20; // defense pretty low to start.
  hp = 100; // health lol, which should start at 100
  accuracy = 50; // this is the accuracy of player, about half chance of getting a shot on an enemy
  money = 180; // how much money the player has, they currently have 180 money currencies
  selectedMove = 0; // number according to menu of the selected move.
  bonusType = -1; // denotes which bonus type we are using.
  bonus = -1; //denotes bonus we using
  moves = {"Punchy Punchy!", "Punchy Punchy but *DOUBLE*! ", "The Punchy that is Blindfolded", "Punchy with an Ouchie >_>"};
  items = {"Chicken Noodle Soop the Raise HP Potion", "Cold Milk the Raise Defense Potion", "Hot Chili the Raise Attack Potion", "Carrot Juice the Raise Accuracy Potion", "Coffee the Lower Enemy Accuracy Potion", "Green Tea the Lower Enemy Attack Potion", "Warm Milk the Lower Enemy Defense Potion"};  //items, haha i can speak foreign language too :D 
  itemAmounts = {1, 1, 1, 1, 1, 1, 1}; //amount of each item one of each for now
} 

// getters
std::string Player::getName() {
  // if we want to get name of player
  return name;
}

int Player::getMoney() {
  //if we want to get the amount of money the player has
  return money; 
}

int Player::getAttack() {
  // get the amount for a specific attack
  return attack;
}

int Player::getBonus() {
  return bonus; 
}

string Player::getAttackName() {
  // get the attack name.
  return moves[selectedMove];
}

int Player::getDefense() {
  // get the defense of player
  return defense;
}

int Player::getAccuracy() {
  // get the accuracy of the player
  return accuracy;
}

int Player::getHP() {
  // get health
  return hp;
}

void Player::setAccuracy(int num) {
  accuracy = num;
}

void Player::setBonusType(int num){
  bonusType = num; 
}

void Player::updateHP(int num) {
  hp += num;
}

// actions
void attackEnemy(Player &p, Enemy & e) {
  // attacks the enemy by attack determined by the move chosen by the player.
  p.chooseMove(); // chooses the move and sets it to the selected move.

  p.setAttack(0); // reset to make sure we're not adding more damage from last round.
  
 
  p.setBonus(0); // number of bonus points.
  p.setBonusType(-1); //reset bonus type

  
  p.setBonus(p.useItem());// useItem will remove the item from the item inventory, whether it be improving attack, improving accuracy, or improving defense (or the reverse for the enemy MWAHAHAHAHA).  It should also set the bonusType, which will control which stat we need to temporarily change.

  // apply bonuses.
  cout << p.getBonusType() << endl; 
  switch(p.getBonusType()) {
    case 1:
      // raise your OWN HP
      p.updateHP(p.getBonus());

      cout << "Your HP has been raised by " << p.getBonus() << "\n";
      break;
    case 2:
      // raise your OWN defense
      p.updateDefense(p.getBonus());

      cout << "Your defense has been raised by " << p.getBonus()<< "\n";
      break;
    case 3:
      // raise your OWN attack
      p.updateAttack(p.getBonus());

      cout << "Your attack has been raised by " << p.getBonus()<< "\n";
      break;
    case 4:
      // raise your OWN accuracy
      p.updateAccuracy(p.getBonus());

      cout << "Your accuracy has been raised by " << p.getBonus()<< "\n";
      break;
    case 5:
      // lower enemy accuracy
      if (e.getAccuracy() > p.getBonus()) {
        e.updateAccuracy(p.getBonus() * -1); // negate because I'm too lazy to make a decrement function, so might as well just add a negative.

      cout << "Enemy accuracy has been lowered by " << p.getBonus()<< "\n";
      }
      else {
        while (e.getAccuracy() != 0) {
          e.updateAccuracy(-1); // bring accuracy down to 0
        }

        e.updateAccuracy(10); // update to 10.

        cout << "Enemy Accuracy has been lowered to 10" << "\n";
      }
      
      break;
    case 6:
      // lower enemy attack

       if (e.getAttack() > p.getBonus()) {
        e.updateAttack(p.getBonus() * -1); // decrease attack
      cout << "You have lowered the enemy's attack by " << p.getBonus() * -1 << endl;
      }
      else {
        while (e.getAttack() != 0) {
          e.updateAccuracy(-1); // bring accuracy down to 0
        }

        cout << "Enemy Attack has been lowered to 0" << "\n";
      }
      break;
    case 7:
      // lower enemy defense
      e.updateDefense(p.getBonus() * -1); // decrease defense

      cout << "You have lowered the enemy's defense by " << p.getBonus() * -1 << endl;


      if (e.getDefense() > p.getBonus()) {
        e.updateDefense(p.getBonus() * -1); // negate because I'm too lazy to make a decrement function, so might as well just add a negative.

      cout << "Enemy defense has been lowered by " << p.getBonus()<< "\n";
      }
      else {
        while (e.getDefense() != 0) {
          e.updateDefense(-1); // bring accuracy down to 0
        }

        cout << "Enemy Defense has been lowered to 0" << "\n";
      }
      break;
  }

  // now apply the damage from each move.
  if (p.getSelectedMove() == 0) {
    // do first move stats. just a normal punchy-punchy, no drawbacks
    p.updateAttack(25);
    
  }
  else if (p.getSelectedMove() == 1) {
    // do second move stats.
    // double(close to double at least :P) punchy-punchy, small drawback in defense.
    p.updateAttack(35);
    if (p.getDefense() >= 5) {
      p.updateDefense(-5);

      cout << "Your defense has been lowered by 5 using this move\n";
    }
    else {
      while (p.getDefense() != 0) {
        p.updateDefense(-1); // update until 0
      }

      cout << "Your defense has been lowered to 0 by this move.\n";
    }
    
  }
  else if (p.getSelectedMove() == 2) {
    // do third move stats.
    // super duper powerful move, but decreases accuracy down to 45%, can be a benefit if your accuracy is lower than said value.

    p.updateAttack(60); // powerful attack.
    p.setAccuracy(45); // move to 45%
    cout << "Your accuracy has been set to 45%\n"; 
  }
  else {
    // should only be the fourth move, so do the fourth move stats.
    // decently poweful attack but you can hurt yourself in the process!  So it lowers your hp by a teensy bit.

    p.updateAttack(40); // attack by 40
    p.updateHP(-10); // subtratct 10 HP points
    cout << "You hurt yourself trying to attack, -10 HP!\n";
  }
  
  // then, remove the defense from the enemy.
  p.setAttack(p.getAttack() - e.getDefense());
 
  // now does the attack even hit?  let's roll for accuracy.
  srand(time(NULL)); // set the seed to the current time.
  int probability = rand() % 100 + 1; // find random number inbetween 1 and 100.

  if (!(probability <= p.getAccuracy())) {
    // if the attack is not within the accuracy range, then it fails.
    p.setAttack(0); // attack is 0 because the attack failed, no damage dealt.
    cout << "Your attack missed! \n";
  } else{ 
    // attack is now set.
  
    // now apply it
    if(p.getAttack() <= 0){
      p.setAttack(1); //if we end up being negative, round to one since we always want to deal at least one bit of damage
    }
    e.loseHP(p.getAttack());
    cout << "You dealt " << p.getAttack() << " damage to the foe!\n"; 
    }
}

void Player::loseHP(int damage) {
  // this what occurs when the enemy attacks the player.

  hp -= damage; // remove the amount of damage dealt.
}

void Player::printMoves() {
  for (int i = 0; i < 4; i++) {
    // print out each move from the move list.
    cout << "[" << i + 1 << "] " << moves[i] << "\n";
  }
}

void Player::chooseMove() {
  // choose the move from move set.
  string input; // just to get input in
  bool validInput = true; // is it valid?

  do {

    validInput = true;

    cout << "Choose your move!\n\n";
    printMoves(); // prints the moves
    cout << "Choice: ";
    getline(cin, input);
  
    for (int i = 0; i < input.size(); i++) {
      if (!isdigit(input[i])) {
        validInput = false;
      }
    }

    if (input.size() < 1) {
      // no characters == no bueno
      validInput = false;
    }
  
    if (validInput) {
      // continue to make sure it is in range.
      if (stoi(input) > 0 && stoi(input) <=4) {
        validInput = true; // this is good.
        cout << "Valid Input.\n\n";
      }
      else {
        // bad input! (how dare the user do such things!!!)
        validInput = false; // bad input
      }
    }
    else {
      // this is just invalid. repeat bruh
  
      cout << "Invalid Choice.  Please try again:\n\n";
    }
  } while (!validInput);
  selectedMove = stoi(input)-1; // set the selected move.
}

int Player::useItem(){
  int input; //input
  bool itemSelected = false;
  do{
    do{
      //selects the item being used and changes the bonus type 
      cout << "Please select an item by typing the item's associated number. If typed wrong this will repeat\n"; 
      //first let's run through the items in our array 
      for(int i = 0; i <  items.size(); i++){
        cout << i+1 << ") " << items[i] << endl; //print the item 
        cout << "\t Amount in Inventory: " << itemAmounts[i] << endl; 
      }
      cout << "8) No item \n"; 
    }while(!getValidInt(input) || input < 0 || input > 8); //error trapping
  
    if(input != 8){ //if we chose an item
      if(itemAmounts[input-1] > 0){
        updateInventory(input - 1, -1); //remove the item from the inventory 
        itemSelected = true; //we have an item selected 
        } else{
          cout << "You can't use what you don't have :/\n";
        }
    } else{ //if we dont want to use one, we can just get out of the loop 
       itemSelected = true; 
    }
  }while(itemSelected != true); //keep running until we have an item we can use 
/*
  if(input == 1){ //update the bonus variable based on what we chose(randomized)
    setBonus((rand() % 5 + 0) + 5);
  } else if(input == 2){
    setBonus((rand() % 5 + 0) + 5);   
  } else if(input == 3){
    setBonus((rand() % 5 + 0) + 5);
  } else if(input == 4){
    setBonus((rand() % 5 + 0) + 5);
  } else if(input == 5){
    setBonus((rand() % 5 + 0) + 5);
  } else if(input == 6){
    setBonus((rand() % 5 + 0) + 5);
  } else if(input == 7){
    setBonus((rand() % 5 + 0) + 5);
  } */

  setBonus((rand() % 5 + 0) + 5);
  setBonusType(input); //set the bonus type 
  return getBonus(); //return the input so we can use the item in our attackEnemy function 

}

void Player::setAttack(int num) {
  attack = num;
}

int Player::getBonusType() {
  return(bonusType);
}

int Player::getSelectedMove() {
  return(selectedMove);
}

void Player::setBonus(int num){
  bonus = num;
}
// upgrades
void Player::updateAttack(int increment) {
  // increase the base attack damage.
  attack += increment;
}

void Player::updateDefense(int increment) {
  // improve base defense
  defense += increment;
}

void Player::updateAccuracy(int increment) {
  // update the base accuracy.
  accuracy += increment;
}

void Player::updateMoney(int incriment) {
  //update the amount of money we have in inventory 
  money += incriment; 
}

void Player::updateInventory(int index, int incriment){
  //update the inventory of the player, items are in an array so we need the index to specify which item
  itemAmounts[index] += incriment; 
}

void Player::resetStats(){ //after each battle, reset the player's stats 
  defense = 20;
  hp = 100;
  accuracy = 50;
}

void Player::resetInventory(){ //reset inventory to 1
  for(int i = 0; i < itemAmounts.size(); i++){
    itemAmounts[i] = 1; 
  }
}