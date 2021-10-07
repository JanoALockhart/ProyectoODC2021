#include <stdlib.h>
#include <stdio.h>

int isValid(char * n, int * base){
    int * validity;
    int * cantFrac;
    int * dEnteros;
    int * dFracciones;
    int * i;
    int * value;
    validity=(int *) malloc(sizeof(int));
    cantFrac=(int *) malloc(sizeof(int));
    dEnteros=(int *) malloc(sizeof(int));
    dFracciones=(int *) malloc(sizeof(int));
    i=(int *) malloc(sizeof(int));
    value=(int *) malloc(sizeof(int));
    *validity=1;
    *dEnteros=0;
    *dFracciones=0;
    *cantFrac=0;
    *i=0;
    for(;(*(n+*i)) && (*dFracciones)<5 && (*cantFrac)<2 && (*validity); (*i)++){
        if((*(n+*i))=='.' || (*(n+*i))==',') (*cantFrac)++;
        else{
            value=getValue((n+*i));
            if((*value)>=base) *validity=0;
            if(*cantFrac) (*dFracciones)++; else (*dEnteros)++;
            free(value);
        }
    }
    if(*(cantFrac)>=2 || *(dEnteros)>=10 || *(dFracciones)>5) *validity=0;
    free(cantFrac);
    free(dEnteros);
    free(dFracciones);
    free(i);
    return validity;
}

int * getValue(char * value){
    int * output;
    output=(int *) malloc(sizeof(int));
    switch(tolower(*value)){
        case 'a':{ *output=10; break; }
        case 'b':{ *output=11; break; }
        case 'c':{ *output=12; break; }
        case 'd':{ *output=13; break; }
        case 'e':{ *output=14; break; }
        case 'f':{ *output=15; break; }
        case '0':{ *output=0; break; }
        case '1':{ *output=1; break; }
        case '2':{ *output=2; break; }
        case '3':{ *output=3; break; }
        case '4':{ *output=4; break; }
        case '5':{ *output=5; break; }
        case '6':{ *output=6; break; }
        case '7':{ *output=7; break; }
        case '8':{ *output=8; break; }
        case '9':{ *output=9; break; }
        default:{ *output=100000; break; }
    }
    return output;
}

char * isValue(int * n){
    char * output;
    output=(char *) malloc(sizeof(char));
    switch(*n){
        case 10:{ *output='a'; break; }
        case 11:{ *output='b'; break; }
        case 12:{ *output='c'; break; }
        case 13:{ *output='d'; break; }
        case 14:{ *output='e'; break; }
        case 15:{ *output='f'; break; }
        case 0:{ *output='0'; break; }
        case 1:{ *output='1'; break; }
        case 2:{ *output='2'; break; }
        case 3:{ *output='3'; break; }
        case 4:{ *output='4'; break; }
        case 5:{ *output='5'; break; }
        case 6:{ *output='6'; break; }
        case 7:{ *output='7'; break; }
        case 8:{ *output='8'; break; }
        case 9:{ *output='9'; break; }
        default: printf("GIGA FAIL \n"); break;
    }
    return (output);
}

int * stringLength(char * string){
    int * length;
    length=(int *) malloc(sizeof(int));
    *length=0;
    while(*(string+*length)) (*length)++;
    return (length);
}

void separateComma(char * n, char * parteEntera, char * parteFraccionaria){
    int * pos;
    int * i;
    pos=(int *) malloc(sizeof(int));
    i=(int *) malloc(sizeof(int));
    *pos=0;
    *i=0;
    *parteFraccionaria='\0';
    while(*(n+*i) && *(n+*i)!='.' && *(n+*i)!=','){
        *(parteEntera+*pos)=*(n+*i);
        (*pos)++;
        (*i)++;
    }
    *(parteEntera+*pos)='\0';
    *pos=0;
    if(*(n+*i)=='.' || *(n+*i)==','){
        while(*(n+*i)){
            *(parteFraccionaria+*pos)=*(n+*i);
            (*pos)++;
            (*i)++;
        }
        *(parteFraccionaria+*pos)='\0';
    }
    free(pos);
    free(i);
}

void addTerminalChar(char * string, int * stringLength, int * n){
    *(string+(*stringLength)) = *(isValue(n));
    *(string+(*stringLength)+1) = '\0';
}

void reverse(char * string, int * stringLength){
    int * count;
    char * aux;
    count=(int *) malloc(sizeof(int));
    aux=(char *) malloc(sizeof(char));
    *count=0;
    while((*count)<((*stringLength)/2)){
        *(aux)=*(string+*count),*(string+*count)=*(string+((*stringLength)-(*count))),*(string+((*stringLength)-(*count)))=*(aux);
        (*count)++;
    }
}

//#define TEST_UTIL
#ifdef TEST_UTIL
int main(){
    int base, bingChilling;
    int * tres;
    int * bingus;
    tres=(int *) malloc(sizeof(int));
    bingus=(int *) malloc(sizeof(int));
    *tres=1;
    *bingus=11;
    char * string[3];
    *string='n';
    *(string+1)=' ';
    *(string+2)='\n';
    addTerminalChar(string, tres, bingus);
    printf("%s",string);
   /* base=16;
    if(*isValid(string,base)){
        printf("TRUE\n");
    }else{
        printf("FALSE\n");
    }
    int * testIsValue;
    testIsValue=(int *) malloc(sizeof(int));
    for(int i=0;i<16;i++){
        *testIsValue=i;
        printf("1 a %c \n",*isValue(testIsValue));
    }
    bingChilling=
    printf("Length of string %i \n",*stringLength(string));
    char entera[4];
    char fraccionaria[4];
    separateComma(string,entera,fraccionaria);
    printf("Parte entera %s \n",entera);
    printf("Parte fraccionaria %s",fraccionaria);*/
    return 0;
}
#endif // TEST_UTIL
