#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int   day[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
struct TDate {
    int date;
    int month;
    int year;
};
void AdvanceTime(struct TDate* d, int n) {
    if (n >= 365 || n <= -365) {
        int k = n / 365;
        d->year += k;
        n -= k * 365;
    }
    int signd = 1;
    if (n < 0) {
        signd = n / abs(n);
    }
    while (n + (d->date) > day[d->month - 1] || n + (d->date) < 1) {
        n = n + (signd * day[d->month - 1]);
        d->month += signd;
        if (d->month == 13) {
            d->month = 1;
            d->year++;
        }
        if (d->month == 0) {
            d->month = 12;
            d->year--;
        }
    }
    d->date += n;
}
int main() {
    int n;
    struct TDate d;
    scanf("%d", &n);
    scanf("%d %d %d", &d.date, &d.month, &d.year);
    if (n != 0) {
        AdvanceTime(&d, n);
    }
    printf("%d %d %d", d.date, d.month, d.year);
    return 0;
}
