#include <stdio.h>
#include <stdlib.h>
void  copy_array(int N,int m,int array[N][m], int copy[N][m]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < m; ++j) {
         copy[i][j] = array[i][j];
        }
    }
}
int main() {
    int N, m;
    scanf("%d %d", &N, &m);
    int array[N][m];
    int  copy[N][m];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("array[%d][%d]=", i, j);
            scanf("%d", &array[i][j]);
            printf("\n");
        }
    }
    copy_array(N,m,array,copy);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("copy[%d][%d]=", i, j);
            printf("%d\n", copy[i][j]);
        }
    }
    return 0;
}
