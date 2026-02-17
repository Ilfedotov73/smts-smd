#include <stdio.h>
#include <stdlib.h>

void read_input(int *, char *, int *);

int main()
{
    char op_;
    int a, b, n;
    read_input(&a, &op_, &b);
    
    if (op_ == '+') {
	n = a + b;
    }
    else if (op_ == '-') {
    	n = a - b;
    }
    printf("result: %d\n",n);
    return 0;
}

void read_input(int *pa, char *pop_, int *pb)
{
    printf("Input a, operator (+ or -), b: ");
    int nitems = scanf("%d %c %d", pa, pop_, pb);
    if (nitems != 3) {
    	printf("Error: input invalid.\n");
    	abort();
    }
    if (*pa < '0' || *pa > '9') {
    	printf("Error: input invalid, please input param a between 0 and 9.\n");
	abort();
    }    
    if (*pb < '0' || *pb > 9) {
        printf("Error: input invalid, please input param b between 0 and 9.\n");
        abort();    
    }
    if (*pop_ != '+' && *pop_ != '-') {
    	printf("Error: input invalid, operator input error.\n");
	abort();
    }
}

