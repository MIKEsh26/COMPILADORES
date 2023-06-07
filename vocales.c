#include <stdio.h>
#include <ctype.h>
/*prototipo de función*/
void analiza_linea(char linea[], int *pv, int *pc, int *pd, int *pb, int *po);
int main(){
    char linea[80];             /*linea de texto*/
    int vocales = 0;            /* contador de vocales*/
    int consonantes = 0;        /*contador de consonantes*/
    int digitos = 0;            /*contador de digitos*/
    int blancos = 0;            /*contador de espacio en blanco*/
    int otros = 0;              /*contador del resto de caracteres*/

    printf("Introducir una línea de texto:\n");
    scanf("%[^\n]", linea);
    analiza_linea(linea, &vocales, &consonantes, &digitos, &blancos, &otros);

    printf("\nN° de vocales: %d", vocales);
    printf("\nN° de consonantes: %d", consonantes);
    printf("\nN° de digitos: %d", digitos);
    printf("\nN° de caracteres en blanco: %d", blancos);
    printf("\nN° de otros caracteres: %d \n", otros);
}

void analiza_linea(char linea[], int *pv, int *pc, int *pd, int *pb, int *po)
/*analizar los caracteres de un linea de texto*/
 {
    char c;             /*caracteres en mayusculas*/
    int cont = 0;       /*contador de caracteres*/
    while((c = toupper(linea[cont])) != '\0') {
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        ++ *pv;                 /*vocales*/
        else if (c >= 'A' && c <='Z')
            ++ *pc;             /*consonante*/
            else if (c >= '0' && c <= '9')
                ++ *pd;         /*digito*/
                else if(c == ' ' || c == '\t')
                    ++ *pb;     /*espacio en blanco*/
                    else
                        ++ *po; /*otro*/

        ++cont;
    }
    return;
}
