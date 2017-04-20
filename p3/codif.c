#include "codif.h"

//crear mes de una pestanya->  Ctrl+X +3

void empty_morse_table(morse_table_t t){
  int i;
  for(i=0;i<(LEN_MORSE_TABLE-1);i++)
    t[i]='@';
  t[i]='\0';
  return;
}

void set_translation(morse_table_t t, char c, morse_char_t m){

  int i=1;
  for(int j=0 ; m[j]!='\0' ; j++){
    i=i*2;
    if (m[j]=='.')
      i++;
  }

  t[i-1]=c;
  return;
}


char to_ascii(const morse_table_t t, morse_char_t m){
  int i=1;

  for(int j=0 ; m[j]!='\0'; j++){
    i=i*2;
    if (m[j]=='.')
      i++;
  }  
  return t[i-1];
}

void to_morse(const morse_table_t t, char c, morse_char_t m){
  
  int i=0,j=0,cont=0;
  if (c!='@' && c!= '\0'){
    //trobem el morse revertit
    for(i=0 ; t[i]!=c && i<LEN_MORSE_TABLE-1 ; i++);
    if (i==LEN_MORSE_TABLE-1){
      m[0]='\0';
      return;
    }
    if (i==1){
      m[cont++]='-';
    }
    else{
      i=i+1;
      while(i!=1){
	if(i%2==0){
	  m[cont]='-';
	}
	else
	  m[cont]='.';
	cont++;
	i=i/2;
      }
    }
    m[cont]='\0';
    //invertim la string
    int i=0,k=cont-1-i;
    while (i<k){
      char cc=m[i];
      m[i]=m[k];
      m[k]=cc;
      i++;
      k--;
    }
  }
  else{
    m[j]='\0';
  }
  return;
  }

/*
void main(){
  morse_table_t t;
  empty_morse_table(t);
  set_translation(t,'F',"..-.");
  set_translation(t,'5',"......");

  morse_char_t m;
  to_morse(t,'\0',m);
  printf("to morse: %s\n",m);
  printf("to ascii: %c\n",to_ascii(t, "------"));
}



*/

