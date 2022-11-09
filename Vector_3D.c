#ifndef __3DVECT__
#define __3DVECT__
#include "Point_3D.c"
#include "Matrix.c"
#include <math.h>

struct Vector{
    double x;
    double y;
    double z;
    double w;
};

struct Vector newVector(double x_mag, double y_mag, double z_mag);
struct Vector newVectorW(double x_mag, double y_mag, double z_mag, double w_mag);
struct Vector addVectors(struct Vector v1, struct Vector v2);
struct Vector subVectors(struct Vector v1, struct Vector v2);
struct Vector rotateXY(struct Vector v, double r);
struct Vector rotateYZ(struct Vector v, double r);
struct Vector rotateXZ(struct Vector v, double r);
struct Vector scaleVect(struct Vector v, struct Vector scale);
double lengthVect(struct Vector v);
struct Vector Unit(struct Vector v);

struct Vector newVector(double x_mag, double y_mag, double z_mag, double w_mag){
    struct Vector newVect;
    newVect.x = x_mag;
    newVect.y = y_mag;
    newVect.z = z_mag;
    newVect.w = 1;
    return newVect;
}

struct Vector newVectorW(double x_mag, double y_mag, double z_mag, double w_mag){
    struct Vector newVect;
    newVect.x = x_mag;
    newVect.y = y_mag;
    newVect.z = z_mag;
    newVect.w = w_mag;
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

double lengthVect(struct Vector v){
    return sqrt((v.x * v.x) + (v.y*v.y) + (v.z*v.z));
}

struct Vector Unit(struct Vector v){
    double length = lengthVect(v);
    return newVector(v.x / length, v.y / length, v.z / length);
}

struct Vector multVectMatrix(struct Vector v, struct Matrix m){
    double x = (v.x * m.data[0]) + (v.y * m.data[4]) + (v.z*m.data[8]) + (v.w*m.data[12]);
    double y = (v.x * m.data[1]) + (v.y * m.data[5]) + (v.z*m.data[9]) + (v.w*m.data[13]);
    double z = (v.x * m.data[2]) + (v.y * m.data[6]) + (v.z*m.data[10]) + (v.w*m.data[14]);
    double w = (v.x * m.data[3]) + (v.y * m.data[7]) + (v.z*m.data[11]) + (v.w*m.data[15]);
    return newVectorW(x,y,z,w);
}

struct Vector* projectAndClip(int width, int height, double near, double far, struct Vector* vertex){
    double halfWidth = width / 2;
    double halfHeight = height / 2;
    double aspect = width / height;
    struct Vector v = newVector();
    struct Matrix clipMatrix = clipMatrix(60 * (M_PI / 180), aspect, near, far);


}
#endif