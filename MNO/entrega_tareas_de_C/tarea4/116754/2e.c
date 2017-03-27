#include<stdio.h>
#include<string.h>
#define MAXLINEA 1000 /*máximo tamaño de una línea*/
/*definición de variables externas*/
int max;
char linea[MAXLINEA];
char linea_max[MAXLINEA];

/*Prototipo de funciones:*/

int obtenlinea(void); 
void copia(void);
void voltea(void);

/*imprime la línea con tamaño más grande*/
int main(void){
    int longitud;
    extern int max;
    extern char linea_max[MAXLINEA];
    max=0;
    while((longitud = obtenlinea()) > 0)
        if( longitud > max){
            max = longitud;
            copia();
        }
    if(max > 0)
        printf("%s", linea_max);
return 0;
}

/*obtenlinea: lee una linea en el arreglo linea, regresa longitud*/
int obtenlinea(void){
    int c;
    int i,j=0;
    extern char linea[];
    for(i=0; i < MAXLINEA-1 && (c=getchar())!=EOF && c!= '\n';i++)
    //if(c != ' ')
    linea[j++] = c;
    if(c == '\n'){
        linea[j] = c;
        j++;
    }
    linea[j]='\0'; //este caracter es necesario para almacenar strings
    return j;
}


/*copia: copia del arreglo "linea" al arreglo "linea_max"*/
void copia(void){ 
    int i;
    extern char linea[], linea_max[];
    i=0;
    while(*(linea+i) != '\0'){
        *(linea_max+i) = *(linea+i);
        i++;    
    }
    voltea();
}

void voltea(void){
    int i=0;
    extern char linea[], linea_max[];
    int length = strlen(linea)-1;
    while(length >= 0){
        *(linea_max+i) = *(linea+length);
        i++, length--;
    }
}
