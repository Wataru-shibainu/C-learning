#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

#define SIZE 1000

char* str_cut_out(int a, int b, char* origin_str){
  char* buffer_str = NULL;
  buffer_str = (char*)malloc(sizeof(char) * SIZE);
  if(buffer_str == NULL){
    printf("領域確保失敗\n");
  }
  origin_str += a;
  for(int i = 0; i < b - a + 1; i++){
    buffer_str[i] = *origin_str;
    origin_str++;
  }
  return buffer_str;
}

char* replace(int a, int b, char* origin_str, char* p_str){
  for(int i = 0; i < b - a + 1; i++){
    origin_str[i + a] = p_str[i];
  }
  return origin_str;
}

char* reverse(int a, int b, char* origin_str){
  char* str = NULL;
  str = str_cut_out(a, b, origin_str);

  for(int i = 0; i < b - a + 1; i++){
    origin_str[i + a] = str[strlen(str) - 1 - i];
  }
  return origin_str;
}

int main(){
  char origin_str[SIZE];
  char* bufffer_str = NULL;
  char* after_replace_str = NULL;
  char p_str[SIZE];
  char order[10];
  int order_num  = 0;
  int a = 0, b = 0;

  scanf("%s", origin_str);
  scanf("%d", &order_num);

  for(int i = 0; i < order_num; i++){
    scanf("%s", order);
    if(strcmp(order, "print") == 0){
      scanf("%d %d", &a, &b);
      bufffer_str = str_cut_out(a, b, origin_str);
      printf("%s\n", bufffer_str);
    }else if(strcmp(order, "replace") == 0){
      scanf("%d %d", &a, &b);
      scanf("%s", p_str);
      replace(a, b, origin_str, p_str);
    }else if(strcmp(order, "reverse") == 0){
      scanf("%d %d", &a, &b);
      reverse(a, b, origin_str);
    }
  }
  free(bufffer_str);
}
