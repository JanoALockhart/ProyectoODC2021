#include <math.h>

#include "Util.h"

#include "impresion.h"

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
            if(vervose) papDecimalOBaseT10Base(total, value, Obase, exp);
            (*count)++;
        }
    } else *total=(*n=='0')?0:1;
    free(count);
    free(numberLength);
    free(value);
    free(exp);
    return total;
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
            if(vervose) papDecimal10BaseTDBase(number, DBase, rem);
            (*count)++;
        }
        addTerminalChar(output, count, number);
        reverse(output, count);
    }else *output=(*n=='0')?0:1;
    free(count);
    free(number);
    free(rem);
    return output;
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
