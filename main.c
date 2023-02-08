#include <stdio.h>
#include <stdbool.h>

int different_count (const int *A, const int *B, int len);
int max_value(const int *A, int *B, int len);
void max_sum_neighbours (int *A, int *B);

int main() {
    printf("Enter arrays length: ");
    int len = 0;
    while (len < 1) scanf("%d", &len);
    int A[len];
    int B[len];
    printf("Fill first array\n");
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &A[i]);
    }
    printf("Fill second array\n");
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &B[i]);
    }
    printf("Choose option what to do with arrays\n"
           "1 - Count of different elements\n"
           "2 - Get highest value\n"
           "3 - Get neighbours with the highest sum\n");
    int option = 0;
    scanf("%d", &option);
    switch (option) {
        case 1: {
            printf("%d", different_count(A, B, len));
            break;
        }
        case 2: {
            printf("The highest value in these arrays: %d", max_value(A, B, len));
            break;
        }
        case 3: {
            max_sum_neighbours(A, B);
            break;
        }
        default:
            printf("Incorrect number\n");
    }
    return 0;
}

int different_count (const int *A, const int *B,  int len)
{
    int uniques_count = 0;
    int uniques[2*len];
    for (int i = 0; i < len; i++)
    {
        bool is_new = true;
        for (int u = 0; u < uniques_count; u++) {
            if (A[i] == uniques[u]){
                is_new = false; break;}
        }
        if (is_new) {
            uniques[uniques_count] = A[i]; ++uniques_count;
        }
    }

    for (int i = 0; i < len; i++)
    {
        bool is_new = true;
        for (int u = 0; u < uniques_count; u++) {
            if (B[i] == uniques[u]){
                is_new = false; break;}
        }
        if (is_new) {
            uniques[uniques_count] = B[i]; ++uniques_count;
        }
    }

        return uniques_count;
}

int max_value(const int *A, int *B, int len)
{
    int tmp_max = *A;
    ++A;
    for (int i = 0; i < len; i++){
        if (A[i] > tmp_max)
            tmp_max = A[i];
    }
    for (int i = 0; i < len; i++){
        if (B[i] > tmp_max)
            tmp_max = B[i];
    }
    return tmp_max;
}
void max_sum_neighbours (int *A, int *B)
{
}