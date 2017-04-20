#ifndef STREAMENCODER_H
#define STREAMENCODER_H

#include "codif.h"
#include "itu.h"
#include <stdio.h>

void streamencoder_init(void); // Inicialitza el modul
void do_codifica(FILE *in, FILE *out);
void do_descodifica(FILE *in, FILE *out);

#endif
