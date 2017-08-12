#include <def_lib.h>
#include "stm32f4xx.h"

#if defined(METH1)
    #define NUM 1
#elif defined(METH2)
    #define NUM 2
#else
    #define NUM 3
#endif

#if defined(NUMBER)
#else
    #define NUMBER 3
#endif

int a = 0;
int b = NUMBER;
int c;

void defMeth();

int main(){
    a = NUM;
    c = defLibTest();
    while(a){
        a = a + b;
        defMeth();
    }
}

#ifdef METH1
void defMeth(){
    b = 10;
}
#endif

#ifdef METH2
void defMeth(){
    b = 20;
}
#endif