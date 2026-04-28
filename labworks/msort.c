#include <stdio.h>
#include <stdlib.h>

void msort(int p_input[], size_t p_input_sz);
void merge(int *pa, int *pb, int *p_input, size_t sz_pa, size_t sz_pb, size_t p_input_sz);

int main()
{
    int arr[11] = {1, 0, 3, 2, 18, 43, -2, -3, 6, 1 , 2};
    msort(arr, 11);

    for (int i = 0; i < 11; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void msort(int p_input[], size_t p_input_sz)
{
    if (p_input_sz == 0) { 
        printf("Error: The input buffer size value is zero.");
        abort();
    }
    
    if (p_input_sz == 1) { return; }

    size_t buffsz_a = p_input_sz / 2;
    size_t buffsz_b = p_input_sz % 2 == 0 ? p_input_sz / 2 : (p_input_sz / 2) + 1;

    int buffer_a[buffsz_a];
    int buffer_b[buffsz_b];
    
    int i = 0;
    while(i < buffsz_a) {
        buffer_a[i] = p_input[i];
        ++i;
    }

    int j = 0;
    while(j < buffsz_b) {
        buffer_b[j] = p_input[i];
        ++i, ++j;
    }

    msort(buffer_a, buffsz_a); 
    msort(buffer_b, buffsz_b);
    merge(buffer_a, buffer_b, p_input, buffsz_a, buffsz_b, p_input_sz);
}

void merge(int *pa, int *pb, int *p_input, size_t sz_pa, size_t sz_pb, size_t p_input_sz)
{
    int i = 0, j = 0, k = 0;
    while (i < sz_pa && j < sz_pb && k < p_input_sz) {
        if (pa[i] < pb[j]) { p_input[k++] = pa[i++]; }
        else { p_input[k++] = pb[j++]; }   
    }

    /* Теперь требуется дозаполнить */
    while (i < sz_pa) { p_input[k++] = pa[i++]; }
    /* Можно было написать так:
     * while (j < sz_pb) {
     *     p_input[k] = pb[j];
     *     ++k;
     *     ++j;
     * }
     * */
    while (j < sz_pb) { p_input[k++] = pb[j++]; }
}
