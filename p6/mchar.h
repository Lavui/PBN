typedef enum {MDot,MDash} msign_t;//Defineix dos tipus de signes de codificacio

typedef uint8_t mchar_t; //defineix la codificacio dun morse

#define mchar(c) (mchar_t)((0b##c<<(8-sizeof(#c)+1))|(sizeof(#c)-1))//magia negra, retorna un mchar constant

#define mchar_len(m) (uint8_t)(m & 0x7)//funcio que retorna la longitutd dun mchar_t, el nombre de signes vamos

#define mchar_empty (mchar_t)0//Constant que defineix un objecte de tipus mchar_t buit sense signe

mchar_t mchar_add(mchar_t m,msign_t s);//retorna el resultat d'afegir a m un nou signe s

typedef struct{//Aquest tipus es un iterador que serveix per recorrer els signes del codi d'un caracter,quan mask??sentinel s'acaba l'interacio
    mchar_t m;
    uint8_t mask,sentinel;
}mchar_iter_t;

mchar_iter_t mchar_iter(mchar_t m); //donat un codi m retorna un iterador sobre el primer signe

msign_t mchar_next(mchar_iter_t *const i);//torna el signe que indica l'interadori postincremneta

bool mchar_valid(mchar_iter_t i);//retorna true si l'interador esta sobre el signe i si pot aplica charnextr

