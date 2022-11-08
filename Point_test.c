#include "Point.c"
#include <stdio.h>

int main(void){
    struct Point p = Point.new(3,-4);
    printf("x = %d, y = %d\n",p.x, p.y);
}