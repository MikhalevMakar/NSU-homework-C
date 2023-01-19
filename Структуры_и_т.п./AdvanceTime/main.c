#include <stdio.h>
struct TTime {
    int hour;
    int minute;
    int second;
};
void AdvanceTime(struct TTime* t, int n) {
    
    if (n < 0) {
        n = 86400 -(-n % 86400);
    }
    else {
        n=n % 86400;
    }
    int sum = (t->hour * 3600) + (t->minute * 60) + t->second + n;
    t->hour+= sum / 3600;
    t->minute = (sum - (t->hour * 3600)) / 60;
    t->second = sum - 60 * (t->hour * 60 + t->minute);
    if (t->hour >= 24) {
        t->hour = t->hour % 24;
        }
    }
int main() {
    int n;
    struct TTime t;
    scanf("%d%d%d", &t.hour, &t.minute, &t.second);
    scanf("%d", &n);
        AdvanceTime(&t, n);
    printf("%d %d %d", t.hour, t.minute, t.second);
    return 0;
}
