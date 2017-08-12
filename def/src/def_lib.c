//
// Created by Aleksey on 06.08.2017.
//

#include "../inc/def_lib.h"

int var1;

#if defined(FUNC1)
int defLibTest(){
    var1 = 10;
    return var1;
}
#endif

#if defined(FUNC2)
int defLibTest(){
    var1 = 20;
    return var1;
}
#endif
