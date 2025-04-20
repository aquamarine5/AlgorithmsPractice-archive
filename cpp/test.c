#include <stdio.h>
#define PI 3
#define S(r) PI *r *r
int main()
{
    double a = 1, b = 2, c;
    printf("%lf", S(a + b));
    return 0;
}