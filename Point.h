struct Point{
    int x, y;
    double (*dist)(struct Point *this);
};
extern const struct PointClass{
    struct Point (*new)(int x_pos, int y_pos);
} Point;