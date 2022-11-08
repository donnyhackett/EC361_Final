#include "Point_3D.c"
#include "Vector_3D.c"
#include <stdio.h>
#include <math.h>

int main(void){
    struct Point p1 = newPoint(1, 2, 1);
    struct Point p2 = newPoint(0, 4, 4);
    struct Vector v1 = newVector(2, 0, 0);
    struct Vector v2;

    printf("x = %f, y = %f, z = %f\n",p1.x, p1.y, p1.z);
    printf("x = %f, y = %f, z = %f\n",p2.x, p2.y, p2.z);

    v2 = subPointFromPoint(p1,p2);
    v1 = addVectors(v1,v2);
    p1 = addVectorToPoint(p1,v1);

    printf("x = %f, y = %f, z = %f\n",p1.x, p1.y, p1.z);

    p2 = subVectorFromPoint(p2,v2);
    printf("x = %f, y = %f, z = %f\n",p2.x, p2.y, p2.z);
}