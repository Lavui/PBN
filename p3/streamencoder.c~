#include <stdbool.h>

#include "streamencoder.h"

void streamencoder_init(void){ // Inicialitza el modul itu
  itu_init();
}

void do_codifica(FILE *in, FILE *out){
  morse_char_t missatge;
  char c;
  int i;
  bool primerespai=true; //per no tenir en compte tots els espais inicials (avans de qualsevol caracter)
  int dosespais=0; //per capar el limit de espais concatenats a 2 (com a maxim)
  int iespai=0;
  c = fgetc(in);
  while(c != EOF && c!='\n'){
    if (c==32){ //32 = espai(ASCII)
      if(primerespai==false && dosespais<1){
	dosespais++;
	fputc(c,out);
      }
    }
    
    else{
      primerespai=false;
      dosespais=0;
      to_morse(itu_table, c, missatge);
      if (iespai>0){
	iespai++;
	fprintf(out," %s",missatge);
      }
      else{
	iespai++;
	fprintf(out,"%s",missatge);
      }
    }
    c=fgetc(in);
  }
}

void do_descodifica(FILE *in, FILE *out){
  int countl=0;
  int cactual;
  bool isspace=false; /*Definim si abans hi ha hagut un espai*/
  morse_char_t seqactual;
	
  while ((cactual=getc(in))!= EOF){
    if((cactual == '.') || (cactual=='-')){
      seqactual[countl++]=cactual;
      isspace=false;	
    }

    else if(cactual==' '){
      if(isspace){
	fprintf(out,"%c",' ');
	isspace=false;
	countl=0;
      }
			
      else if (countl>0){
	isspace=true;
	seqactual[countl] = '\0';
	fprintf(out,"%c",to_ascii(itu_table,seqactual));
	countl=0;
      }
    }		
  }
  if(countl>0){
    seqactual[countl] = '\0';
    fprintf(out,"%c",to_ascii(itu_table,seqactual));
  }
  fprintf(out,"%c",'\0');
  return;
}

		
