#include <stdint.h>

#include "mtbl.h"
#include "codif.h"
#include "mchar.h"
#include "itu.h"


char mtbl_m2a(mchar_t c){

    morse_char_t segon;
    int i=0,j=0;
    uint8_t len;
    len=0x07&c;
    for(int z;z<8;z++)segon[z]='@';
    for(i=7;i>=3 && j<longit;i--){
        if(c&(1<<i))
            temp[j]='-';
        else
            temp[j]='.';
        j++
    }
    temp[j]='\0';
    return to_ascii(itu_table, temp);
}

mchar_t mtbl_a2m(char c){
    morse_char_t morse;
    mchar_t res=0;
    uint8_t i=0,c=0,j=0;
    for(i=0;i<5;i++)m[i]='@';
    to_morse(itu_table,c,m);

    j=7;
    for(i=0;i<5 && (m[i]=='.' || m[i]=='-');i++){
        if (m[i]=='-'){
            res |= (1<<j);
        }
        j--;
        c+=1;
    }
    res |=c;
    return res;
}