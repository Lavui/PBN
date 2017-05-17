#ifndef TIMER_H
#define TIMER_H

#include <stdint.h>


#define TIMER_MS(ms) (ms/10)//timer_ms es una funcio que converteix unitats de temps de milisegons a ticks
#define TIMER_ERR (timer_handler_t)-1 //constant de tipus timer_handler_t que indica un error en el moment de planificar funcio

typedef void (*timer_callback_t)(void);//timer callback t es un tipus de dades que denota un apuntador a una funcio sense parametres i que retorna void
typedef int8_t timer_handler_t;//un timerhandler que identifica una funcio que s'executara en un futur

void timer_init(void);//inicialitza el modul, nomes pot cridarse amb les interrupcions inhabiitades

timer_handler_t timer_after(uint8_t ticks, timer_callback_t f);//planifica la funcio f() PER  A SER Executada al cap de x ticks, retorna un handler que identifica aquesta accio

timer_handler_t timer_every(uint8_t ticks, timer_callback_t f);//planifica la funcio f() per a ser executada cada ticks de manera indeifinada, retorna un handler que identifica aquesta accio planificada o be val timer err

timer_handler_t timer_ntimes(uint8_t n,uint8_t ticks,timer_callback_t f);//planifica la funcio f() per a ser executada cada ticks de manera indefinida, retorna un handler que identiica aquesta accio planificada o be val itmer_err en cas que l'accio no es plugi pl

void timer_cancel(timer_handler_t h);//cancela laccio planificada indetificada per h

void timer_cancel_all(void); //cancela totes les accions planificades del serveis

#endif
