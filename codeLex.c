/*Ejemplo del analisis lexico en Lex*/
%{
#include<stdio.h>
%}

digit       [0-9]
number            [digit]+
letter     [a-z,A-Z]
identifier {letter}+{number}+
newline           \n
whilespace  [\t]+
simbolos    [@|#|&]+
conditional [if|then|else|for]+

%option noyywrap

%%
{digit}       {printf("Encontrado el digito: %s\n",yytext);}
{simbolos}    {printf("An special character found: %s\n",yytext);}
{number}      {printf("Encontrado un numero: %s\n",yytext);}
{identifier}  {printf("Encontrado un identificador: %s\n",yytext);}
{conditional} {printf("Palabra reservada: %s\n",yytext);}
.             { }
              
%%

int main(void)
{
      yylex();
      return 0;
}    
