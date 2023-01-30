#include <stdio.h>
enum { N = 5 };
struct TPoint2D {
    float x;
    float y;
};
float CalcArea(struct TPoint* d) {
    float S = 0;
    for (int i = 0; i < N - 1; ++i) {
        S += (d[i].x * d[i + 1].y) - (d[i + 1].x * d[i].y);
    }
    S += d[N - 1].x *d[0].y -d[0].x*d[N - 1].y;
    return -S/2;
}
int main() {
    struct TPoint2D  d[N];
    for (int i = 0; i < N; ++i) {
        scanf("%f", &d[i].x);
        scanf("%f", &d[i].y);
    }
    float S = CalcArea(&d);
    printf("%f", S);
    return 0;
}
