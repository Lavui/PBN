#include "semaph.h"

typedef enum {StreetA,StreetB} street_t;

typedef enum {Aclear, Bclear, AtoB, BtoA, ABoff} estat_general;

void control_int(void);

//Inicialitza el modul de control, inicien apagats i cal engegarlos

void control_force(street_t t);

//Força el carrer t a l'estat Clear. Respecta els temps de seguretat establers

void control_off(void);

//Apaga els semafors de la cruilla

void control_on(void);

//Engega els semafors de la cruilla

semaph_stat_t control_get_stat(street_t s);

//Retorna l'estat del semafor del carrer s
