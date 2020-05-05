#include <stdio.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C"
{
#endif
#include "../libs/mymath.h"
#ifdef __cplusplus
}
#endif


int main(int argc, char *argv[])
{
    if (argc < 3){
        printf("Usage: %s base exponent \n", argv[0]);
        return 1;
    }
    float a1 = atof(argv[1]);
    float a2 = atoi(argv[2]);
    double result = bigger(a1, a2);
    printf(" result is %d \n", result);
    return 0;
}