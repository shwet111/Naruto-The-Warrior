// Text Based Adventures Game - Naruto The Warrior
// C++ Progamme Using OOPS Concept

#include <bits/stdc++.h>           //Including The Libraries
using namespace std;

void gamestory() {    // Game  starting PopUpStory
  system("clear");
  cout << "\n____________________________________\n";
  cout << "| Naruto : A True Warrior |";

  cout << "\n____________________________________\n";
  cout << "\nOnce Upon a time , there was a kingdom full of happiness. The "
          "king named Mike had a beautiful princess named Lara. "
       << endl;
  cout << "\n____________________________________\n";
  cout << "\nUnfortunately, on one evil day, the HollowKnight kidnapped Lara. "
          "\nNow the entire kingdom is at stake. HollowKnight is a ruler of "
          "the DarkWorld.";
  cout << "\n____________________________________\n";
}

class player {

private:
  int health = 100;

  int maxdamage = 20;
  int mindamage = 10;

  int maxhealing = 15;
  int minhealing = 8;

public:
  player() {           // constructor calling

    cout << "\n Hi my name is Naruto! We need to save princess and get her back."
         << endl;
    cout << "Here are some stats that might be useful for you going ahead."
         << endl;

    cout << "\nNaruto's Health " << health;
    cout << "\n__________________________________\n";
    cout << "Naruto's Attack range is between " << mindamage << '-' << maxdamage
         << ".";
    cout << "\n__________________________________\n";
    cout << "Naruto's Healing range is between " << minhealing << '-'
         << maxhealing << ".\n"<<endl;
  }

int gethealth(){                //getter
  return health;
}

void takedamage(int damage){   // Damage get by Naruto
  
  cout<<"Ohh no , hit to Naruto"<<endl;
  // cout<<"Enemy is dealing damage of "<<damage << " to the Naruto!"<<endl;
  health = health - damage;

  if (health < 0)
    cout << "Naruto Died!!, You Lost.... :(" << endl;

  else 
    cout<<"Naruto's current health after damage is : " << health << endl;

  cout << "\n____________________________________\n";

  
  
  
}

int givedamage(){  // Damage given by Naruto to DarkLord

  srand(time(0));
  int randomdamage = (rand() %(maxdamage - mindamage +1) + mindamage);  //For Generating Random Value we use Formula

  cout<< "Naruto's damage to enemy " << randomdamage <<  endl;
  return randomdamage;
  
}

void heal(){  //Healing of Naruto
  
  srand(time(0));
  int randomheal = (rand() %( maxhealing - minhealing +1)+ minhealing);

  health = health+randomheal;

  cout<<"Naruto heal with HP of " << randomheal <<endl;
  
  cout<<"Naruto's health after healing " << health <<endl;
  

  cout << "\n____________________________________\n";
  
}



  
};

class enemy {
private:
  int health = 100;

  int maxdamage = 16;
  int mindamage = 10;

public :

enemy() {  // Constructor Calling
  cout<< "I am the Lord of DarkWorld!!" << endl;
}

int gethealth(){                //getter to get Health from Private 
  return health;
}

void takedamage(int damage){
  
  cout<<"Ohh Yes,hit to HollowKnight" <<endl;
  // cout<<"Naruto is dealing damage of "<<damage << " to the darklord!"<<endl;
  health = health - damage;

  if (health < 0 )
    cout<<"Enemy Died!!.... You Won :)" << endl;
  
  else //enemy is died   
    cout<<"DarkLord's current health after damage is : " << health << endl;

  cout << "\n____________________________________\n";
  
    
  
}

int givedamage(){

  srand(time(0));
  int randomdamage = (rand() %(maxdamage - mindamage +1) + mindamage);

  cout<<"Hit to Player " << randomdamage << endl;
  return randomdamage;
  
}


} ;

void gameloop(player player , enemy enemy)
//Algorithm 
//1. Either player will heal or will attack
//2. Enemy's turn -> Enemy can perform the attack only becoz we created only damage function not healing
//3. This battle lopp will continue till either one of them dies

{
  char playerchoice; //variable
  do{    // Using Do while loop Becoz Atleast one time code will then then ask approval from while condition
    
    cout<<"Press A to attack or H to heal" << endl;
    cin >> playerchoice;

    if(playerchoice == 'a' || playerchoice == 'A') {  //perform atack
      
system("clear");    
      enemy.takedamage(player.givedamage()) ;

      if(enemy.gethealth() > 0 ) {
      
        cout << "Ha Ha Ha , Its my turn now!" << endl;
        player.takedamage(enemy.givedamage());
        
      }
    }

    else if ((playerchoice == 'h' || playerchoice == 'H') && (player.gethealth() == 100)) {  // Checking for correct input
      
      cout << "Naruto's health is already full , Please choose a or A to attack " << endl;
      
    }
      
    else if(playerchoice == 'h' || playerchoice == 'H') {  //perform healing
system("clear");
      

      player.heal();  //heal function calling from player class

      if(enemy.gethealth() > 0 ) {
      
        cout << "Ha Ha Ha , Its my turn now!" << endl;
        player.takedamage(enemy.givedamage());
      }
      
    }

    else 
      cout << "invalid input" << endl;
    
  }while(player.gethealth() > 0 && enemy.gethealth() > 0) ;
  
  
}

int main() {

  gamestory();
  char userinput;  // input for start of game 

  do {   
    cout << " Press S to start the game or any other to exit!" << endl;
    cin >> userinput;

    if (userinput == 'S' || userinput == 's') {
      player playerobj;
      enemy enemyobj;
      
      // cout<< "the Player health is : " << playerobj.gethealth() << endl;
      
      // playerobj.takedamage(50);
      // playerobj.givedamage();
      // playerobj.heal();

      // cout<< "enemy's health is : " << enemyobj.gethealth() << endl;
      // enemyobj.givedamage();

      gameloop(playerobj, enemyobj);
    }

    else {
      cout << "Thanks for playing" << endl;
    }

  } while (userinput == 'S' || userinput == 's');
}
