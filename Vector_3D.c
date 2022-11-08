#ifndef __3DVECT__
#define __3DVECT__
#include "Point_3D.c"
#include <math.h>

struct Vector{
    double x;
    double y;
    double z;
};

struct Vector newVector(double x_mag, double y_mag, double z_mag);
struct Vector addVectors(struct Vector v1, struct Vector v2);
struct Vector subVectors(struct Vector v1, struct Vector v2);
struct Vector rotateXY(struct Vector v, double r);
struct Vector rotateYZ(struct Vector v, double r);
struct Vector rotateXZ(struct Vector v, double r);
struct Vector scaleVect(struct Vector v, struct Vector scale);

struct Vector newVector(double x_mag, double y_mag, double z_mag){
    struct Vector newVect;
    newVect.x = x_mag;
    newVect.y = y_mag;
    newVect.z = z_mag;
    return newVect;
}

struct Vector addVectors(struct Vector v1, struct Vector v2){
    return newVector(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

struct Vector subVectors(struct Vector v1, struct Vector v2){
    return newVector(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

struct Vector rotateXY(struct Vector v, double r){
    double x = (v.x * cos(r)) + (v.y * -sin(r));
    double y = (v.x * sin(r)) + (v.y * cos(r));
    double z = v.z;
    return newVector(x,y,z);
}

struct Vector rotateYZ(struct Vector v, double r){
    double x = v.x;
    double y = (v.y * cos(r)) + (v.z * -sin(r));
    double z = (v.y * sin(r)) + (v.z * cos(r));
    return newVector(x,y,z);
}

struct Vector rotateXZ(struct Vector v, double r){
    double x = (v.x * cos(r)) + (v.z * sin(r));
    double y = v.y;
    double z = (v.x * -sin(r)) + (v.z * cos(r));
    return newVector(x,y,z);
}

struct Vector scaleVect(struct Vector v, struct Vector scale){
    double x = v.x * scale.x;
    double y = v.y * scale.y;
    double z = v.z * scale.z;
    return newVector(x,y,z);
}
#endif