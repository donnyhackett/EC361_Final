#include <math.h>
struct Matrix{
    double data[16];
};

struct Matrix Identity();
struct newMatrix(double[16] in);
struct Matrix scaleMatrix(struct Matrix &m, double scale);
struct Matrix multMatrix(struct Matrix d, struct Matrix m);
struct Matrix clipMatrix(double fov, double aspectRatio, double near, double far);

struct Matrix transform(struct Matrix camera);

struct Matrix transform(struct Matrix camera){
    struct Matrix trans;

    return trans;
}

struct newMatrix(double[16] in){
    int i;
    for(i = 0; i < 16; i++){
        data[i] = in[i];
    }
}

struct Matrix Identity(){
    double in[16];
    int i;
    for(i = 0; i < 16; i++){
        in[i] = 0;
    }
    in[0] = in[5] = in[10] = in[15] = 1;
    return newMatrix(in);
}

struct Matrix scaleMatrix(struct Matrix &m, double scale){
    int i;
    for(i = 0; i < 16; i++){
        m[i] *= scale;
    }
}

struct Matrix multMatrix(struct Matrix d, struct Matrix m){
    double[16] in;
    int col, y, x, i;
    for(y = 0; y < 4; ++y){
        col = y * 4;
        for(x = 0; x < 4; ++x){
            for(i = 0; i < 4; ++i){
                in[x + col] += m[i + col]*d[x + i*4];
            }
        }
    }
    return newMatrix(in);
}

struct Matrix clipMatrix(double fov, double aspectRatio, double near, double far){
    struct Matrix m = Identity();
    double f = 1 / tan(fov * 0.5);
    m.data[0] = f * aspectRatio;
    m.data[5] = f;
    m.data[10] = (far + near) / (far - near);
    m.data[11] = 1; //this plus the old z into w
    m.data[14] = (2 * near * far) / (near - far);
    m.data[15] = 0;
    return m;
}