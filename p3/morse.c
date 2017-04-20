#include <stdio.h>
#include <string.h>
#include "streamencoder.h"



int main(int argc, char *argv[]){
    streamencoder_init();
    if(argc>1){
      if(strcmp(argv[1],"-d")==0){
	do_descodifica(stdin,stdout);
      }
      else if(strcmp(argv[1],"-c")==0){
	do_codifica(stdin, stdout);
      }
    }
    else
        do_codifica(stdin,stdout);
    return 0;
}
