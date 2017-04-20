#include<stdio.h>
#include<stdint.h> /* per poder crear int8_t, uint8_t... */
#include<string.h>

//per guardt C+x+w

int main(int argc, char *argv[]){ /*argc = numero d'arguments. *argv = arguments*/

  uint8_t n;

  if(argc>1){
    printf("byte en hex: ");
    scanf("%2hhx",&n);

    if(!strcmp(argv[1],"-o")){
      printf("%#o",n);
    }
    else if(!strcmp(argv[1],"-d")){
      printf("%d",n);
    }
    else if(!strcmp(argv[1],"-x")){
      printf("%#x",n);
    }
    else{
      printf("Opcio incorrecte.");
    }
    
  }
  else{
    printf("Falta opcio -o -d -h\n");
    printf("Nom del programa: %s\n",argv[0]);
  }
  
  printf("\n");
  return 0;
}
