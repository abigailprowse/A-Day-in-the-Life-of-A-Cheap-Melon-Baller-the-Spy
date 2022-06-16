/*
  Names: Ethan Lalanne and Abigail Prowse
  Program Name: Github-athon Team Project!
  Date: 6/7/2022 - 6/15/2022
  Extra: Ha! This whole thing is an extra >:P 
*/ 
#include <iostream>
using namespace std; //makin' life easier 
#include "Enemy.h" //enemy object 
#include "GetData.h" //error trapping 
#include "Player.h" //player object
//functions
bool battle(Player mc, Enemy enemy);  //battle function, returns true or false depending on win/lose 
void store(void); //we can do store related stuff ina function since this stuff will be used multiple times throughout the program 
int searchies(string *, int, int, string); //declare binary search function

void getStats(Player &p, Enemy &e);
// get the stats for the player and enemy to see and stragetize.


 //Object set up!
Player mc("Jermaine the Plastic Melon Baller Spy"); //our main character 
Enemy enemy1("The Snotty Spork", 15, 75, 75); // meh kinda starter enemy
Enemy enemy2("The Dirty Dishcloth", 24, 60, 40); // tanker, can take a lot of attack before getting hurt.
Enemy enemy3("The Watermelon Warrior", 18, 80, 50); // healthy boi
Enemy enemy4("The Melon Murderer", 3, 75, 95); // really accurate but has a really huge achilles heel called "oh crud i have no health whoopsies"
Enemy enemy5("Dat Annoying Butter Knife Secretary", 20, 90, 55); // good health and accuracy combo
Enemy enemy6("The Metal Melon Baller From *KiTChEn AiD* D: ", 22, 100, 60); // good at everything.  Big Bad Wolf.


int main() {
 //In main we will have the control flow of the story because... because :p
  int keepPlaying = 1; // run condition that sees if the user will keep playing the game
  do{ //do while loop to run thru the game
    
    //Keeping this similar to MMR we will have a prompt, the user will have to make a choice and based on that choice
    int choice; //choice variable 
    int progressing = 1; //if we are progressing we are progressing 

    cout << "The Day in the Life of the Cheap Plastic Melon Baller the Spy\n"; 
    do{ //prompt 1
      cout << "You are a spy in the Silverware Spy Society, led by the secretary, Butter Knife.  As such, he assigns you a mission.  You must parole the kitchen on the lookout for anyone who is a threat to the Society.  What do you do?\n"; //prompt
      
      cout << "1) Stay in the Drawer\n" << "2) Hang out in the Dishwasher\n" << "3) Actually Listen to Your Boss\n"; //choices (just random stuff for now)
      
    }while(!getValidInt(choice) || choice <= 0 || choice > 3); //error trapping
    
    if(choice == 1){ //if we choose 1, hmmm maybe that can lead to death
      cout << "Butter Knife sells you out to the kitchen chef, resulting in you being thrown in the trash, where you die.\n";
      progressing = 0; //toggle progressing to 0 to signify loss 
    } if(choice == 2 || choice == 3){  //maybe lead to a balle, different choices lead to different enemies w/ diff stats 
        bool firstBattle; //see if we won our first battle 
        if(choice == 2){ //choice 2 fight
          cout << "In the dishwasher, you run into the Snotty Spork who starts some serious trash talk (very characteristic for the trash he is!). Forseeing the threat that he is, you engage in battle.\n";
          //battle
          if(battle(mc, enemy1) == false){ //if we lose
            progressing = 0; //we lose
            firstBattle = false; 
          } else{ //we winnas
            firstBattle = true;
          }
        } else if(choice == 3){ //choice 3
          cout << "On your patrole, you spot a rogue piece of fabric on the edge of the sink, his damp, smelly form making you retch.  On closer examination, you recognize him as The Dirty Discloth.  You reckon he has not been washed in over three months.  He spots you, and after quick conversation you realize he's been colluding with the melons! To preserve the Society you initiate a battle!\n";
          //battle 
          if(battle(mc, enemy2) == false){ //if we lose
            progressing = 0; //we lose
            firstBattle = false; 
          } else{
            firstBattle = true; //hey if we win we won 
          }
        }
      //so after that scenario goes on... let's give them an option to keep walking or go to the store so long as we won
      if(firstBattle == true){
        mc.resetStats(); //reset stats
        mc.updateMoney(30);
        cout << "You earned 30 monies!\n";
        do{
          cout << "Would you like to...\n";
          cout << "1) Keep Progressing\n2)Go to the Fridge\n"; //options
  
        }while(!getValidInt(choice) || choice <= 0 || choice > 2); //error trap
  
        if(choice == 2){ //if we goin' to the store
          store(); //legoo
        }
        //we dont need to control flow to keep progressing sicne after the store we will be forced to make a choice again 
        do{ //prompt 2 
          cout << "As you continue your parole, you see a melon in the distance.  He's one of the biggest you've ever seen.  You know it could be one of two possibilities --- either way, if they were to find the Society, it would be disaster.  What do you do?\n"; //random prompt 
            cout << "1) Be the melon baller you were meant to be and cut out its insides. \n" << "2) Run Back to Base and Alert the Other Silverware \n" << "3) Use the melon to get intel on the secret operations on the Melon Military\n"; //choices (just random stuff for now)
        }while(!getValidInt(choice) || choice <= 0 || choice > 3);
        if(choice == 2){ //da bad choice
          cout << "The utensils are rallying for war. However the silverware soon become a murderous frenzy and the meat tenderizer accidentally tramples you.  You die painfully.\n";
          progressing = 0;
        }
        if(choice == 1 || choice == 3){ //the ok choices
          bool secondBattle; //did we win the second battle 
          if(choice == 1){ 
            cout << "As you launch yourself at the melon, you recognize it as the dreaded, the feared, the horrid . . . Watermelon Warrior!  You gasp, and feel your insides turn to Jell-O.  However, the mark of a true spy is to fight even when the going gets tough. So you put on your big melon baller pants and give it all you've got.\n";
            if(battle(mc, enemy3) == false){ //battle, if we lost we lose
              progressing = 0;
              secondBattle = false;
            } else{ //if we win we won
              secondBattle = true; 
            }
          } else if(choice == 3){
            cout << "As you sneak around the melon, it becomes evident that the melon is none other than The Melon Murderer.  It has become clear that investigation is no longer an option, and the only way to survive will be to kill the dreaded foe.  You crack your knuckles, and dive in, planning to get as much information as you can while you fight valiantly.\n"; 
            if(battle(mc, enemy4) == false){ //battle, if we lost we lose
              progressing = 0;
              secondBattle = false;
            } else{ //if we win we won
              secondBattle = true; 
            }
          }
          //Let's see if we need to restock so long as we won
          if(secondBattle == true){
            mc.resetStats(); //reset stats
            mc.updateMoney(50);
            cout << "You earned 50 monies!\n";
            do{
              cout << "Would you like to...\n";
              cout << "1) Keep Progressing\n2)Go to the Fridge\n"; //options
            }while(!getValidInt(choice) || choice <= 0 || choice > 2); //error trap
            bool thirdBattle; 
          if(choice == 2){ //we goin to the store?
            store();  //lets drain our wallet 
            thirdBattle = true; //exempt from battle 
          } else if(choice == 1){
            //Another Battle? A mini one
            cout << "Random prompt\n";
            //battle
            if(battle(mc, enemy5) == false){ //if we lose we lose
              thirdBattle = false;
              progressing = 0; 
            }
          }
            //OK OK OK... is the big choice! ... if we won
          if(thirdBattle == true){
            mc.resetStats(); //reset stats 

            if(enemy5.getHP() <= 0){
              cout << "You have earned 1 money for beating the enmy \n";
              mc.updateMoney(1);
            }
            do{ //prompt 2 
                cout << "After slaying the great watermelon, you walk across the white marble counter, which may be in need of a good wipe down. Patrolling across the crusty surface, you run into the legend, Kitchen Aid Melon Baller. Just looking at him smile, you know his grim smile is all bad news.  He threatens to overthrow the Silverware Spy Society , ake your accomplishments for his own., and replace your job as the melon baller! He's metal, how can you compete!?!What do you do?\n"; //random prompt 
                cout << "1)  Run from the Household and start a better life in the neighbors house. n" << "2) Slay the Kitched Aid Melon Baller\n" << "3) Lure Kitech Aid Melon Baller over to the toaster and try to electrocute him\n";//choices (            
              }while(!getValidInt(choice) || choice <= 0 || choice > 2);
              if(choice == 1) { //death lol
                cout << "You run out of the house, jumping out of the window by the sink. You wave goodbye to shooga who is digging up your past foes as you head to the road. However you forgot to look both ways as you were too busy staring at shooga and die as you are run over by a passing car during your escape. Who knew that plastic could be crushed! n"; 
                progressing = 0; 
              } else if(choice == 2 || choice == 3){

                if(choice == 2){ 
                  cout << "Well, slaying is slaying, not much story to say. Well, what are you waiting for? Time to fight and protect your honor!n"; 

                  } else if(choice == 3){
                  cout << "You intimidatingly bend your plastic body, enraging the Metal Melon Baller from Kitchen Aid. You make it very close to the garbage disposal, but the Metal Melon Baller from Kitchen Aid soon finds out about your trap. Quick he's so close! Now is your chance to push him in! \n";
                  }                //big fight 
                if(battle(mc, enemy6) == false){  //if we lost we lost 
                  progressing = 0;
                }
              }
            }
          }
        }
      }
    }
    //If we lost
    if(progressing == 0){
      cout << "Welp, your plastic body has bent too much. and Shooga Wooga finds your controted remains Time for Shooga Wo do her job, cya in the hole! \n"; 
      cout << "Game Over\n"; //say game over
    }else if(progressing == 1){
      cout << "AYou have done away with the Metal Melon Baller from Kitchen Aid. Shooga somehow retrieves his remains and puts him in the hole with the rest of them. The kitchen is now safe once and for all, and you retire for the day, happy with the hard work you have done to protect the kitchen! Props to shooga for clean up duty! n";
     
    }
    //Whether or not we beat the game we will ask them if they want to play again
    string playAgain; //making a string cuz Y/N is so much more aesthetic than 1 / 2 in this case :P 
    do{
      cout << "Would you like to play again? (Y/N) \n"; //ask question 
      getline(cin, playAgain); //get input 

      //error trap message
      if(playAgain != "Y" && playAgain != "y" && playAgain != "N" && playAgain != "n"){
        cout << "That's not what was asked of you >:/ \n"; //lez play agressive OwO  
        }
    }while(playAgain != "Y" && playAgain != "y" && playAgain != "N" && playAgain != "n"); //ISNT THERE AN EQUALS IGNORE CASE OR SOMETHING >:( 
    
    if(playAgain == "Y" || playAgain == "y"){ //if we play agian, legoo
      cout << "Legoo!\n";
      mc.resetStats(); //reset player stats
      mc.resetInventory(); //reset inventory
      mc.updateMoney((-(mc.getMoney())) + 180); 
      //reset money 
    } else{ //othrwise end game
      cout << "Thanks for playing :3\n";
      keepPlaying = 0; 
    }
  }while(keepPlaying != 0); //end when we stop playing, obvi 
} 

//battle function
bool battle(Player mc, Enemy enemy){
  do{
    //cout << "Player HP: " << mc.getHP() << endl;
    //cout << "Enemy HP: " << enemy.getHP() << endl << endl; 
    getStats(mc, enemy);
    attackEnemy(mc, enemy); //ok so have the player attack the enemy(chooses moves, items, deals the damage, etc. check the OOP for more detais :3)
    if(enemy.getHP() > 0){ //if and only if the enemy is still standings
      attackPlayer(enemy, mc); //let the enemy attack 
    }
    
  }while(mc.getHP() > 0 && enemy.getHP() > 0); //the battle will keep going on until the enemy or the player's HP is emptied 
  //we will tell if we won or lost depending on if the player... yk, died... so lez return that :D 
  if(mc.getHP() > 0){
    cout << "You have defeated " << enemy.getName() << "!\n"; 
    return true; 
  } else{
    cout << "You were killed in battle\n"; 
    return false; 
  }
}

//store function 
void store(){
  
  int keepBuying = 1; //keep buying variable 
  
  cout << "Welcome to the Fridge, where you Need to Buy The Stuff Cuz Life Isn't Cheap :D \n"; //greeting the user 
  do{
  string items[] = {"Chicken Noodle Soop the Raise HP Potion", "Cold Milk the Raise Defense Potion", "Hot Chili the Raise Attack Potion", "Carrot Juice the Raise Accuracy Potion", "Coffee the Lower Enemy Accuracy Potion", "Green Tea the Lower Enemy Attack Potion", "Warm Milk the Lower Enemy Defense Potion"}; //items 
    
  int prices[] = {10, 20, 30, 40, 50, 60, 70}; //items prices, parallell to the first array
  //Exchange sort to sort the items 
  
  string temp; //temp variable
  int temp2; //other temp variable
  for(int i = 0; i < 7 - 1; i++){ //run thru array till before last index
    for(int j = i + 1; j < 7; j++){ //j a step ahead of i goign to the end
      if(items[i] > items[j]){ //check for swap
        temp = items[i];
        items[i] = items[j];
        items[j] = temp; //swap items

        temp2 = prices[i];
        prices[i] = prices[j];
        prices[j] = temp2;  //swap item variables 
      }
    }
  }
  string selection; //instead of using a boring name like *choice* lez switch it up a bit >:D 
  int choice; //fine fine, we can have a boring name, :/ plus i have int values to obtain for this store >:o 

  int found = -99999993; //did we find the item, so far we didn;t so it is set to this... placeholder. Dont ask me why I made it so big O_O 

  do{ //have the user type in their item until the item is found 
    
    //Print the item choices
    for(int i = 0; i < 7; i++){ //run thru item array
      cout << i+1 << ") " << items[i] << endl;
    }
    cout << "\nMoneys: $"<< mc.getMoney() << endl; //print money
    cout << "Please enter the name of the item you want to select.\n";
    getline(cin, selection); //type in selection
    
    found = searchies(items, 0, 7, selection); //see if the item is in the shop
    
    if(found == -99999993){ //if we didn't find it
      cout << "Did you type in your choice correctly?\n";
    }
  }while(found == -99999993); //keep asking until we found it 
  
  double cost = prices[found]; //cost of the item, for now, set to the item we found 
  int amount = -1; //amount of item selected
  do{
    do{
      cout << "Moneys: $"<< mc.getMoney() << endl; //print money
      cout << "You have selected the " << selection << " . How many would you like to buy?\n";
    }while(!getValidInt(amount));
    if(cost * amount > mc.getMoney()){
      cout << "Ha! You wish you had that money to spend *BROKE* 🤧\n";
    }
    
  }while(cost * amount > mc.getMoney() || cost * amount < 0); //make sure we don't exceed

    mc.updateMoney(-cost * amount); //subtract money
    //ummm update inventory based on choice
    if(selection == "Chicken Noodle Soop the Raise HP Potion"){ //basically goes thru the itmes and adds on the inventory
       mc.updateInventory(0, amount);
    } else if(selection == "Cold Milk the Raise Defense Potion"){
      mc.updateInventory(1, amount);      
    } else if(selection == "Hot Chili the Raise Attack Potion"){
      mc.updateInventory(2, amount);
    } else if(selection == "Carrot Juice the Raise Accuracy Potion"){
      mc.updateInventory(3, amount);
    } else if(selection == "Coffee the Lower Enemy Accuracy Potion"){
      mc.updateInventory(4, amount);
    } else if(selection == "Green Tea the Lower Enemy Attack Potion"){
      mc.updateInventory(5, amount);
    } else if(selection == "Warm Milk the Lower Enemy Defense Potion"){
      mc.updateInventory(6, amount);
    }

    
    cout << "Thank you for your purchase :3 \n"; //thank the user for purchasing 
    cout << "\nMoneys: $"<< mc.getMoney() << endl; //print money
    
    if(mc.getMoney() >= 30){ //if we have the money to keep shopping
      string shopping; // selection to keep shopping or not
      do{  //do while loop to get an aswer
        
        cout << "Would you like to keep shopping? (Y/N) \n";
        getline(cin, shopping);  //see if they want to keep shopping

        if(shopping != "Y" && shopping != "y" && shopping != "N" && shopping != "n"){ //approrpiate error emssage
          cout << "Bruh. That's not what I was asking for :/ \n";
        }
      }while(shopping != "Y" && shopping != "y" && shopping != "N" && shopping != "n"); //error trap

      if(shopping == "N" || shopping == "n"){ //if we dont want to shop exit th shop
        cout << "Thanks for shopping. Onto the adventure!\n"; 
        keepBuying = 0; //toggle loop switch
        break;
      }
    } else{ //if we poor
      cout << "L, you broke now. Git outta my shop >:) \n"; //ha ha broke, get out, L
      keepBuying = 0; //toggle loop switch
    
    }
  }while(keepBuying != 0);
  
}

//binary search function 
int searchies(string * arr , int l, int r, string x) {
    if (r >= l)  // make sure we have the right indexes
      {
        int mid = l + (r - l) / 2; //find the iddle point

        //if we find it
        if (arr[mid] == x)
            return mid; //return the index of the array
        // If element is smaller than mid, then it can only be present in left subarray
        if (arr[mid] > x)
            return searchies(arr, l, mid - 1, x);
        // Else the element can only be present in right subarray
        return searchies(arr, mid + 1, r, x);
      }
    // We reach here when element is not
    // present in array
    return -99999993;
  }

void getStats(Player &p, Enemy &e) {
  // get the stats for the player to see and stragetize.

  cout <<"----------------------------------------\n";
  cout << p.getName() << "\n\n";
  cout << "Defense: " << p.getDefense() << "\n";
  cout << "Accuracy " << p.getAccuracy() << "%\n";
  cout << "Health: " << p.getHP() << "\n\n";
  // player stats

  cout << e.getName() << ":\n\n";
  cout << "Defense: " << e.getDefense() << "\n";
  cout << "Accuracy: " << e.getAccuracy() << "%\n";
  cout << "Health: " << e.getHP() << "\n\n";
  cout <<"----------------------------------------\n";
}