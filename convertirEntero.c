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

int * decimalOBaseT10Base(char * n, int * Obase){
    int * total;
    int * count;
    int * numberLength;
    int * value;
    total=(int *) malloc(sizeof(int));
    count=(int *) malloc(sizeof(int));
    numberLength=(int *) malloc(sizeof(int));
    value=(int *) malloc(sizeof(int));
    *total=0;
    *count=1;
    numberLength=stringLength(n);
    while((*count)<=(*numberLength)){
        value=(getValue((n+(*count)-1)));
        (*total) += (*value) * (int) pow( (double)(*Obase) , (double)(*numberLength)-(*count) );
        (*count)++;
    }
    return total;
}

int * decimal10BaseTDBase(char * n, int * DBase){
    int * output;
    double * count;
    int * number;
    number=(int *) malloc(sizeof(int));
    output=(int *) malloc(sizeof(int));
    count=(double *) malloc(sizeof(double));
    *count=0.0;
    *output=0;
    *number=atoi(n);
    while((*number)>=(*DBase)){
        *output=( ((*number)%(*DBase)) * (int) pow( 10 , (*count)) ) + *output;
        *number=(*number)/(*DBase);
        (*count)++;
    }
    *output+=(*number) * (int) pow( 10 , (*count));
    return output;
}

int main(){
    char i[50]="11101";
    char t[50]="29";
    int * base;
    base=(int *) malloc(sizeof(int));
    *base=2;
    printf("Decimal %i \n",*decimalOBaseT10Base(&i,base));
    printf("Decimal %i \n",*decimal10BaseTDBase(&t,base));
    return 0;
}
