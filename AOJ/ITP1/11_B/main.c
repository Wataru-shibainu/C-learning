#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define SIZE 100

typedef struct{
    int num[6];
}dice;

typedef enum{
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
}dice_allocation;

int lead_num_side(int top_num, int front_num, dice* p_dice){

  if(top_num == p_dice->num[ONE]){
    if(front_num == p_dice->num[TWO]) return p_dice->num[THREE];
    else if(front_num == p_dice->num[THREE]) return p_dice->num[FIVE];
    else if(front_num == p_dice->num[FOUR]) return p_dice->num[TWO];
    else if(front_num == p_dice->num[FIVE]) return p_dice->num[FOUR];
  }else if(top_num == p_dice->num[TWO]){
    if(front_num == p_dice->num[THREE]) return p_dice->num[ONE];
    else if(front_num == p_dice->num[ONE]) return p_dice->num[FOUR];
    else if(front_num == p_dice->num[FOUR]) return p_dice->num[SIX];
    else if(front_num == p_dice->num[SIX]) return p_dice->num[THREE];
  }else if(top_num == p_dice->num[THREE]){
    if(front_num == p_dice->num[FIVE]) return p_dice->num[ONE];
    else if(front_num == p_dice->num[ONE]) return p_dice->num[TWO];
    else if(front_num == p_dice->num[TWO]) return p_dice->num[SIX];
    else if(front_num == p_dice->num[SIX]) return p_dice->num[FIVE];
  }else if(top_num == p_dice->num[FOUR]){
    if(front_num == p_dice->num[TWO]) return p_dice->num[ONE];
    else if(front_num == p_dice->num[ONE]) return p_dice->num[FIVE];
    else if(front_num == p_dice->num[FIVE]) return p_dice->num[SIX];
    else if(front_num == p_dice->num[SIX]) return p_dice->num[TWO];
  }else if(top_num == p_dice->num[FIVE]){
    if(front_num == p_dice->num[FOUR]) return p_dice->num[ONE];
    else if(front_num == p_dice->num[ONE]) return p_dice->num[THREE];
    else if(front_num == p_dice->num[THREE]) return p_dice->num[SIX];
    else if(front_num == p_dice->num[SIX]) return p_dice->num[FOUR];
  }else if(top_num == p_dice->num[SIX]){
    if(front_num == p_dice->num[THREE]) return p_dice->num[TWO];
    else if(front_num == p_dice->num[TWO]) return p_dice->num[FOUR];
    else if(front_num == p_dice->num[FOUR]) return p_dice->num[FIVE];
    else if(front_num == p_dice->num[FIVE]) return p_dice->num[THREE];
  }
  return 0;
}

int main(){
    //************
    //declaration
    //************
    int top_num = 0;
    int front_num = 0;
    int question_num = 0;
    dice dice1;
    
    //******
    //input
    //******
    //サイコロの目入力
    for(int i = 0; i < 6; i++){
        scanf("%d", &dice1.num[i]);
    }

    //質問数入力
    scanf("%d", &question_num);
    
    for(int i = 0; i < question_num; i++){
      scanf("%d %d", &top_num, &front_num);
      printf("%d\n", lead_num_side(top_num, front_num, &dice1));
    }

    //********
    //process
    //********

    //*******
    //output
    //*******
}