#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int alwaysRock(){
    return 1;
}

int random(){
    int result;
    
    result = rand() % 3 + 1;
    return result;
}

int game(int choice1, int choice2){
    int result;
    if(choice1 == choice2 ){
       return result = 3;
    }else if(choice1 == 1){
        if(choice2 == 2){
           return result = 2;
        }else{
           return result = 1;
        }
    } else if(choice1 == 2){
        if(choice2 == 1){
           return result = 1;
        }else{
           return result = 2;
        }
    }else{
        if(choice2 == 1){
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

    int n;
    printf("How many games: ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        int result;
        int choice1 = alwaysRock();
        int choice2 = random();
        result = game(choice1, choice2);
        printf("%d  :  %d  : %d \n",choice1,choice2,result);
        if(result == 1){
            wins1++;
        }else if(result == 2){
            wins2++;
        }else{
            ties++;
        }
    }
    printf("wins 1: %d wins 2: %d ties: %d",wins1,wins2,ties);
    return 0;
}



