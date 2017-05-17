#include "mchar.h"
#include <stdio.h>


void print_morse(mchar_t m) { 
  mchar_iter_t i = mchar_iter(m); 
  while (mchar_valid(i)) {
    if (mchar_next(&i) == MDot){
      printf(".");
    }
    else{
      printf("-"); 
    }
  }
}
int main(void){
  mchar_t c = mchar(0000);//H
  print_morse(c);
  printf("\n");
  mchar_t r = mchar(01); //A
  print_morse(r);
  printf("\n");
  mchar_t i = mchar(0010);  //F
  print_morse(i);
  printf("\n");
  mchar_t s = mchar(0010); //F
  print_morse(s);
  printf("\n");
  mchar_t t = mchar(0);   //E
  print_morse(t); 
  printf("\n");
  mchar_t y = mchar(0100);  //L
  print_morse(y);
  printf("\n");
  mchar_t a = mchar(111);  //O
  print_morse(a);
  printf("\n");
  mchar_t n = mchar(00);  //I
  print_morse(n);
  return 0;
}
