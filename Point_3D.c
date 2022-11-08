#ifndef __3DPOINT__
#define __3DPOINT__
#include "Vector_3D.c"

struct Point{
    double x, y, z;
};

struct Point newPoint(double x_pos, double y_pos, double z_pos);
struct Point addVectorToPoint(struct Point p, struct Vector v);
struct Point subVectorFromPoint(struct Point p, struct Vector v);
struct Vector subPointFromPoint(struct Point p1, struct Point p2);

struct Point newPoint(double x_pos, double y_pos, double z_pos){
    struct Point newPoint;
    newPoint.x = x_pos;
    newPoint.y = y_pos;
    newPoint.z = z_pos;
    return newPoint;
}

struct Point addVectorToPoint(struct Point p, struct Vector v){
    return newPoint(p.x + v.x, p.y + v.y, p.z + v.z);
}

struct Point subVectorFromPoint(struct Point p, struct Vector v){
    return newPoint(p.x - v.x, p.y - v.y, p.z - v.z);
}

struct Vector subPointFromPoint(struct Point p1, struct Point p2){
    return newVector(p1.x - p2.x, p1.y - p2.y, p1.z - p2.z);
}
#endif

