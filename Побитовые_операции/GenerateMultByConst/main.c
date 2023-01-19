#include <stdio.h>
#include <math.h>
int* make_array(unsigned int multiplier, int* array) {
    for (int i = 7; i >= 0; --i) {
        int b = multiplier % 2;
        array[i] = b;
        multiplier /= 2;
    }
    return array;
}
int max_degree(int* array) {
    for (int i = 0; i < 8; ++i) {
        if (array[i] == 1) {
            return (i+1);
        }
    }
}
int search_degree(int* array,int q) {
    for (int i = 7; i >= 0; --i) {
        if (array[i] == 1) {
            array[i] = 0;
            return 7-i;
            }
    }
}
void GenerateMultByonst(int search_degree1,int max_degree1,int* array) {
   printf("unsigned int GenerateMultByConst(insigned int multiplier) {\n");
   printf("multiplier=");
   while (search_degree1 != max_degree1) {
         printf("multiplier<< %d  ",search_degree1);
        search_degree1 = search_degree(array, search_degree1);
    }
    printf("multiplier<<%d",max_degree1);
    printf(";\n");
    printf("return multiplier;\n");
    printf("}");
}

int main() {
    int search_degree1= 8;
    int degree = 0;
    int array[8] = {0};
    unsigned int multiplier;
    scanf("%d", &multiplier);
    make_array(multiplier,array);
    //for (int i = 0; i < 8; ++i) {
        //printf("%d", array[i]);
    //}
    int max_degree1=8- max_degree(array);
    search_degree1=search_degree(array,search_degree1);
    GenerateMultByonst(search_degree1,max_degree1,array);
    return 0;
}
