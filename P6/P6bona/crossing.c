#include "control.h"
#include "serial_device.h"
#include <avr/interrupt.h>
#include <string.h>
#include "blck_serial.h"
#include "ether.h"

int main(void) {
  char s[15];
  serial_open();
  ether_init();
  control_init();
  sei();
  control_off();
  print("START");
  while(1) {
    readline(s,2);
    if (!strcmp(s, "R")) {
      if(control_get_state(StreetA)==SemOff && control_get_state(StreetB)==SemOff) {
	control_on();
	ether_put('R');
	ether_put(' ');
	print("ON");
      }
    }

    else if (!strcmp(s, "H")) {
      if(!(control_get_state(StreetA)==SemOff && control_get_state(StreetB)==SemOff)) {
	control_off();
	ether_put('H');
	ether_put(' ');
	print("OFF");
      }
    }

    else if (!strcmp(s, "?A")) {
      switch(control_get_state(StreetA)) {
      case SemClear:
	print("CLEAR");
	break;
      case SemStop:
	print("STOP");
	break;
      case SemApproach:
	print("APPROACH");
	break;
      case SemOff:
	print("OFF");
	break;
      default:
	print("STATEERR");
      }
    }

    else if (!strcmp(s, "?B")) {
      switch(control_get_state(StreetB)) {
      case SemClear:
	print("CLEAR");
	break;
      case SemStop:
	print("STOP");
	break;
      case SemApproach:
	print("APPROACH");
	break;
      case SemOff:
	print("OFF");
	break;
      default:
	  print("STATEERR");
      }
    }
	
    else if (!strcmp(s, "FA")) {
      if(control_get_state(StreetA)==SemOff && control_get_state(StreetB)==SemOff)
	print("SYSOFF");
      else {
	control_force(StreetA);
	ether_put('F');
	ether_put('A');
	ether_put(' ');
	print("OK");
      }
    }
    
    else if (!strcmp(s, "FB")) {
      if(control_get_state(StreetA)==SemOff && control_get_state(StreetB)==SemOff)
	print("SYSOFF");
      else {
	control_force(StreetB);
	ether_put('F');
	ether_put('B');
	ether_put(' ');
	print("OK");
      }
    }
	
    else print("COMERR");  
  }
  serial_close();
  cli();
  return 0;
}
    
  
      
	
