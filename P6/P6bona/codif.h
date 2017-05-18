#ifndef CODIF_H
#define CODIF_H


#define LEN_MORSE_CHAR (6)
#define LEN_MORSE_TABLE (64)

typedef char morse_char_t[LEN_MORSE_CHAR];
typedef char morse_table_t[LEN_MORSE_TABLE];

void empty_morse_table(morse_table_t t);
void set_translation(morse_table_t t, char c, morse_char_t m);
char to_ascii(const morse_table_t t, morse_char_t m);
void to_morse(const morse_table_t t, char c, morse_char_t m);


#endif
