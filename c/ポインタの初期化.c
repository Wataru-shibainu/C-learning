#include <stdio.h>

int main(){
  int *p1;
  int *p2 = NULL;
  printf("%p\n", p1); //不定値
  printf("%p\n", p2); //０番地

}
