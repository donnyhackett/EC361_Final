#include "Point.h"
static struct Point new(int x_pos, int y_pos){
    return (struct Point){.x=x_pos, .y=y_pos};
}
static double dist(struct Point *this){
    
}
const struct PointClass Point={.new=&new};
