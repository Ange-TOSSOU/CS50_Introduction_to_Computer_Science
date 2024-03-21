#include <stdio.h>

typedef struct
{
    double x;
    double y;
}Point;
int main(void)
{
    Point a = {1, 2}, b = {0, 7};
    printf("a = (%.2f %.2f)\n", b.x, a.y);
    printf("b = (%.2f %.2f)\n", b.x, b.y);
    a = b;
    printf("a = (%.2f %.2f)\n", b.x, a.y);
    printf("b = (%.2f %.2f)\n", b.x, b.y);
    return 0;
}
