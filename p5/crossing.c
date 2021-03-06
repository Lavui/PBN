#include "control.h"
#include "blck_serial.h"
#include "serial_device.h"
#include <string.h>
#include <avr/interrupt.h>
#include <stdbool.h>


int main(){
  //Inicialitzarem port serie->inicialitzem control->Interrupcions Ok->Iniciem buit
  serial_open();
  control_init();
  sei();
  control_off();

  char s[5];
  print("START");
  while(1){
    readline(s,2);
    
    if(!strcmp(s,"R")){
      if(control_get_state(StreetA)==SemOff && control_get_state(StreetB)==SemOff)
	control_on();
      print("OK");
    }

    else if(!strcmp(s,"H")){
      if(control_get_state(StreetA)!=SemOff && control_get_state(StreetB)!=SemOff)
	control_off();
      print("OK");
    }

    else if(!strcmp(s,"?A")){ //
      switch(control_get_state(StreetA)){
      case SemClear:
	print("A CLEAR");
	break;
      case SemApproach:
	print("A APPROACH");
	break;
      case SemStop:
	print("A STOP");
	break;
      default:
	print("OFF");
	break;
      }
    }

    else if(!strcmp(s,"?B")){
      switch(control_get_state(StreetB)){
      case SemClear:
	print("B CLEAR");
	break;
      case SemApproach:
	print("B APPROACH");
	break;
      case SemStop:
	print("B STOP");
	break;
      default:
	print("OFF");
	break;
      }
    }

    else if(!strcmp(s,"FA")){
      control_force(StreetA);
      if(control_get_state(StreetB)!=SemApproach && control_get_state(StreetB)!=SemOff){
	print("OK");
      }
      else
	print("NO OK");
    }

    else if(!strcmp(s,"FB")){
      control_force(StreetB);
      if(control_get_state(StreetA)!=SemApproach && control_get_state(StreetB)!=SemOff){
	print("OK");
      }
      else
	print("NO OK");
    }

    else
      print("COMERR");
  }

  serial_close();
  cli();
}

