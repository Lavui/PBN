#include <stdio.h>
#include <ctype.h>
#include <stdint.h>
#include <stdbool.h>
#include "itu.h"
#include "codif.h"
#include "streamencoder.h"

void streamencoder_init(void){ // Inicialitza el modul itu
  itu_init();
}

void do_codifica(FILE *in, FILE *out){
  morse_char_t missatge;
  char c;
  int i;
  int iespai=0;
  c = fgetc(in);
  while(c != EOF && c!='\n'){
    if (c==32){
      fputc(c,out);
      }
    
    else{
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
  printf("\n");
}

void do_descodifica(FILE *in, FILE *out){
  morse_char_t missatge;
   char c,d; 
   int i=0,j;
   bool espai=false;

   while(c = getc(in) != EOF && c!='\n'){ 
     if ((c == '.')||(c == '-')){
       missatge[i++]=c;
       espai=false;
     }

     else if(c == ' '){
       if (espai){
	 fprintf(out,"%c",' ');
	 i=0;
	 espai=false;
       }
       else if(i>0){
	 missatge[i]= '\0';
	 fprintf(out,"%c",to_ascii(itu_table,missatge));
	 i=0
	 espai=true;
       }
     }
     
     if(countl>0){
       missatge[i] = '\0';
       fprintf(out,"%c",to_ascii(itu_table,missatge));
     }
     fprintf(out,"%c",'\n');
   }

     ////////
   /*
     for(i=0 ; c!=' ' ; i++){ 
       missatge[i] = c; 
       c = fgetc(in); 
       j=0; 
     } 
     if (c == ' '){ 
       j++; 
       if (j==2){ 
 	fputc(' ',out); 
 	j=0; 
       } 
     } 
    
     missatge[i]='\0'; 
     d = to_ascii(itu_table,missatge); 
     fputc(d, out); 
   } 
 } 
   */
