#include <math.h>

int * stringLength(char * string){
    int * length;
    length=(int *) malloc(sizeof(int));
    *length=0;
    while(*(string+*length)) (*length)++;
    return (length);
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

int * decimalOBaseT10Base(char * n, int * Obase, int vervose){
    int * total;
    int * count;
    int * numberLength;
    int * value;
    int * exp;
    total=(int *) malloc(sizeof(int));
    if((*n!='0' || *n!='1') && *(n+1)){
        count=(int *) malloc(sizeof(int));
        numberLength=(int *) malloc(sizeof(int));
        value=(int *) malloc(sizeof(int));
        exp=(int *) malloc(sizeof(int));
        *total=0;
        *count=1;
        numberLength=stringLength(n);
        while((*count)<=(*numberLength)){
            value=(getValue((n+(*count)-1)));
            *exp=((*numberLength)-(*count));
            (*total) += (*value) * (int) pow( (double)(*Obase) , (double) (*exp) );
            //if(vervose) papDecimalOBaseT10Base(total, value, Obase, exp);
            (*count)++;
        }
    } else *total=(*n=='0')?0:1;
    return total;
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

char * decimal10BaseTDBase(char * n, int * DBase, int vervose){
    char * output;
    int * count;
    int * number;
    int * rem;
    output=(char *) malloc(sizeof(char));
    if((*n!='0' || *n!='1') && *(n+1)){
        number=(int *) malloc(sizeof(int));
        rem=(int *) malloc(sizeof(int));
        count=(int *) malloc(sizeof(int));
        *count=0;
        *number=atoi(n);
        while((*number)>=(*DBase)){
            *rem=(*number)%(*DBase);
            printf("horthy \n");
            addTerminalChar(output, count, rem);
            *number=(*number)/(*DBase);
            //if(vervose) papDecimal10BaseTDBase(number, DBase, rem);
            (*count)++;
        }
        addTerminalChar(output, count, number);
        reverse(output, count);
    }else *output=(*n=='0')?0:1;
    return output;
}

void addTerminalChar(char * string, int * stringLength, int * n){
    printf("porong %c, %i, %i \n",*string, *stringLength, *n);
    *(string+(*stringLength)) = *(isValue(n));
    printf("currcuman \n");
    *(string+(*stringLength)+1) = '\0';
    printf("curcura curcu \n");
}

int main(){
    char i[50]="11101";
    char t[50]="29";
    int * base;
    int * vervose;
    base=(int *) malloc(sizeof(int));
    vervose=(int *) malloc(sizeof(int));
    *base=2;
    *vervose=0;
    printf("Decimal %i \n",*decimalOBaseT10Base(&i,base,vervose));
    printf("Decimal %s \n",decimal10BaseTDBase(&t,base,vervose));
    return 0;
}
