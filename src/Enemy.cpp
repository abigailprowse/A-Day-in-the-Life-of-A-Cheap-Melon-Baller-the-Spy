using namespace std;


#include "Enemy.h"
#include "stdlib.h"
#include "time.h"
//#include "Player.cpp"

// Constructor
Enemy::Enemy(string enemyName, int defenseStart, int hpStart, int accuracyStart) {
  // will be the player creation
  
  name = enemyName; // name of enemy
  attack = 0; // attack when you consider accuracy and 
  defense = defenseStart; // how is the defense set?
  hp = hpStart; // health lol
  accuracy = accuracyStart; // this is the accuracy of enemy when game starts
  selectedMove = 0; // number according to menu of the selected move.

  moves = {"Slappy Slappy!", "The Weakening Slappy!", "The Blurry Vision Slappy!", "The OP Slappy that Breaks Knees *yours* "}; //nobody except the programmers will see these names hehehehe >:) 
} 

// getters
string Enemy::getName() {
  // if we want to get name of player
  return name;
}

int Enemy::getAttack() {
  // get the amount for a specific attack
  return attack;
}

string Enemy::getAttackName() {
  // get the attack name.
  return moves[selectedMove];
}


int Enemy::getDefense() {
  // get the defense of player
  return defense;
}

int Enemy::getAccuracy() {
  // get the accuracy of the player
  return accuracy;
}

int Enemy::getHP() {
  // get health
  return hp;
}

// upgrades
void Enemy::updateAttack(int increment) {
  // increase the base attack damage.
  attack += increment;
}

void Enemy::updateDefense(int increment) {
  // improve base defense
  defense += increment;
}

void Enemy::updateAccuracy(int increment) {
  // update the base accuracy.
  accuracy += increment;
}

void Enemy::setAttack(int num) {
  attack = num;
}

int Enemy::getSelectedMove() {
  return(selectedMove);
}

int Enemy::setAccuracy(int num) {
  accuracy = num;
}

// actions
void attackPlayer(Enemy &e, Player & p) {
  // attacks the enemy by attack determined by the move chosen by the player.

  e.setAttack(0); // reset attack to 0 so we don't have OP moves.
  
  e.chooseMove(); // chooses the move and sets it to the selected move.

  // since affecting player stats is not regulated by items, they can fail, meaning I want to calculate accuracy before i start unlike the player, who will use an item and then find the accuracy of their move.  Basically, for the player, when they use a bonus, it will apply, however for the enemy, that is not true.  It only applies if the move passes.

  srand(time(NULL)); // find seed based on time
  int probability = rand() % 100 + 1; // random number between 1 and 100

  if (probability <= e.getAccuracy()) {
    // good move

    switch (e.getSelectedMove()) {
      // what each move does.
      case 1:
        // small and normal punchy-punchy
        e.updateAttack(30);
        break;
      case 2:
        // small punchy-punch with attack lowering power.
        e.updateAttack(25);
        

        if (p.getAttack() >= 10) {
          p.updateAttack(-10); // remove 10 from their attack
        }
        else {
          while (p.getAttack() != 0) {
            p.updateAttack(-1); // subtract until 0
          }
        }
        
        break;
      case 3:
        // small punchy-punchy, affecting acccuracy
        e.updateAttack(25);
        
        if (p.getAccuracy() >= 10) {
          p.updateAccuracy(-5); // remove 5 from their accuracy
        }
        else {
          while (p.getAccuracy() != 0) {
            p.updateAccuracy(-1); // subtract until 0
          }

          p.setAccuracy(10); // cap at 10
        }
        break;
      
      case 4:
        // big PUNCHY that lowers defense
        e.updateAttack(50); // ah feel the wind knocked out of you!!!
        if (p.getDefense() >= 10) {
          p.updateDefense(-15); // remove 10 from their defense
        }
        else {
          while (p.getDefense() != 0) {
            p.updateDefense(-1); // subtract until 0
          }
        }
    }

    // okay so now we know how much attack we have.  but we need to remove the player's defense.
    
    e.setAttack(e.getAttack() - p.getDefense());


    if(e.getAttack() <= 0){ //if we have low attack
      e.setAttack(1); //round to 1
    }
    // now let's execute this attack.
    p.loseHP(e.getAttack());
    cout << "The enemy attacked and dealt " << e.getAttack() << " damage!\n";
  }

  else {
    // bad move.
    e.setAttack(0);
    // won't even attack, though a move was selected, so it can be printed out that it failed.
    cout << "The enemy's attack missed!\n";
  }
}

void Enemy::loseHP(int damage) {
  // this what occurs when the enemy attacks the player.

  hp -= damage; // remove the amount of damage dealt.
}

void Enemy::chooseMove() {
  // choose the move from move set.
  srand(time(NULL)); // set the seed to the current time

  selectedMove = rand() % 4 + 1; // random number between 1 and 4.
}