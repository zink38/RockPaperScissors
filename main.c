#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int ROCK = 1;
const int PAPER = 2;
const int SCISSORS = 3;


struct game {
    int player1Choice;
    int player2Choice;
    int result;
};

struct game games[100000];
int match = 0;

int counterLastPicked(int ID) {
    int playerID = ID;
    int enemyLastChoice;
    int result;
    if(match == 0){
        result = rand() % 3 + 1;
    }else{
        if(playerID == 1){
            enemyLastChoice = games[match-1].player2Choice;
        }
        else{
            enemyLastChoice = games[match-1].player1Choice;
        }
       switch (enemyLastChoice){
           case 1:
                result = PAPER;
                break;
            case 2:
                result = SCISSORS;
                break;
            default:
                result = ROCK;  
                break;         
       }
    }
    return result;
}

int alwaysRock(){
    return ROCK;
}

int random(){
    int result;
    
    result = rand() % 3 + 1;
    return result;
}

int getWinner(int choice1, int choice2){
    int result;
    if(choice1 == choice2 ){
       return result = 3;
    }else if(choice1 == ROCK){
        if(choice2 == PAPER){
           return result = 2;
        }else{
           return result = 1;
        }
    } else if(choice1 == PAPER){
        if(choice2 == ROCK){
           return result = 1;
        }else{
           return result = 2;
        }
    }else{
        if(choice2 == ROCK){
           return result = 2;
        }else{
           return result = 1;
        }
    }
}

int main()
{
    int wins1=0;
    int wins2=0;
    int ties=0;

    int n = 100000;
  
    for(int i=0; i<n; i++){
        int id = 1;
        int result;
        int choice1 = alwaysRock();
        id++;
        int choice2 = counterLastPicked(id);
        result = getWinner(choice1, choice2);
        printf("%d  :  %d  : %d \n",choice1,choice2,result);
        games[i].player1Choice = choice1;
        games[i].player2Choice = choice2;
        games[i].result = result;
        if(result == 1){
            wins1++;
        }else if(result == 2){
            wins2++;
        }else{
            ties++;
        }
        match++;
    }
    printf("wins 1: %d wins 2: %d ties: %d",wins1,wins2,ties);
    return 0;
}



