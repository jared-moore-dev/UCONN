#include <stdio.h>
#define OCTANOL 4
#define BUTANOL 3
#define ETHANOL 2
#define METHANOL 1

int value(int coin){
  if(coin == OCTANOL){
    return 8;
  }else if(coin == BUTANOL ){
    return 4;
  }else if(coin == ETHANOL){
    return 2;
  }else{
    return 1;
  }
}

int count(int amount, int maxCoin){
  /*
    TODO: Fill this in to count the number of ways to make change for amount cents using coins with value <= the value of maxCoin
   */
  /*what should coins be? {METHANOL, ETHANOL, BUTANOL, OCTANOL}*/
  if(amount==0){
    return 1;
  }else if(amount<0 || maxCoin == 0){
    return 0;
  }else{
    int updateAmount = amount - value(maxCoin);
    return count(updateAmount, maxCoin)+count(amount, maxCoin - 1);
  }
}

int main(int argc, char* argv[]){
  int amount;
  printf("Enter amount: ");
  scanf("%d", &amount);
  printf("Number of ways to make %d cents: %d\n", amount, count(amount, OCTANOL));
}
