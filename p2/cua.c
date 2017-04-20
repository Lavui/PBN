#include "cua.h"
#include <stdbool.h>


bool cua_plena(const cua_t *const c){
  return c->valids==MAXCUA;
}

bool cua_buida(const cua_t *const c){
  return c->valids==0;
}

int cua_get(cua_t *const c){
  int temp;
  if (cua_buida(c)){
    temp=-1;
  }
  else{
    temp=c->data[c->last];
    c->valids--;
    c->last=++(c->last)%MAXCUA;
  }
  return temp;
}

void cua_put(cua_t *const c,char e){
  int temp;
  if (!cua_plena(c)){
    temp=c->data[c->first]=e;
    c->valids++;
    c->first=++(c->first)%MAXCUA;
  }
  return ;
}

void cua_buidar(cua_t *const c){
  //buido cua que ja te l'espai reservat
  c->first=0;
  c->last=0;
  c->valids=0;
}
