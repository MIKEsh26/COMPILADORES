#include <stdio.h>
#include <ctype.h>

/*prototipo de funcion*/
void analiza_linea(char linea[],int*pv, int*pc, int*pd, int*pb, int*po);

int main()
{
    char linea[80];
    int vocales = 0;
    int consonantes = 0;
    int digitos = 0;
    int blancos = 0;
    int otros = 0;

    printf("    Introducir una linea de texto:\n");
    scanf("%[^\n]", linea);
    analiza_linea(linea,&vocales, &consonantes, &digitos, &blancos, &otros);
    printf("\nN° de Vocales:%d", vocales);
    printf("\nN° de consonastes:%d", consonantes);
    printf("\nN° de digitos:%d", digitos);
    printf("\nN° de caracteres en blanco:%d", blancos);
    printf("\nN° de otros caracteres:%d", otros);
}
void analiza_linea(char linea[],int *pv, int *pc, int *pd, int *pb, int *po)
{
    char c;
    int cont = 0;
    while ((c = toupper(linea[cont]))!= '\0'){
        if(c == 'A'|| c == 'E'|| c == 'I' || c == 'O' || c == 'U' )
            ++ * pv;
        else if (c >= 'A' && c <= 'Z')
        ++ *pc;
        else if (c >= 'O' && c <= '9')
        ++ *pd;
        else if (c == ' ' || c == '\t')
        ++ *pb;
        else
        ++ *po;
        ++cont;
        }
        return;
    }
