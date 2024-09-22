#include <stdio.h>
#include <stdlib.h>

unsigned long long int fib_wrapper_recursive(unsigned long long int number, unsigned long long int *memo);
unsigned long long int fib_wrapper_iterative(unsigned long long int number, unsigned long long int *memo);
unsigned long long int fibonacci_recursive(unsigned long long int number);
unsigned long long int fibonacci_iterative(unsigned long long int number);

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <integer> <r/i>\n", argv[0]); //no more file name input as per previous
        return 1;
    }

    unsigned long long int input_num = atoll(argv[1]);
    char method = argv[2][0];

    unsigned long long int fibonacci_input = input_num - 1; //makes sequence start from fib(1) = 1

    unsigned long long int result;
    if (method == 'r') {
        result = fibonacci_recursive(fibonacci_input);
    } else if (method == 'i') {
        result = fibonacci_iterative(fibonacci_input);
    } else {
        return 1;
    }

    printf("%llu\n", result); //outputs in unsigned long long int form
    return 0;
}

unsigned long long int fib_wrapper_recursive(unsigned long long int number, unsigned long long int *memo) {
    if (number == 0) return 0; 
    if (number == 1) return 1; 
    if (memo[number] != 0) return memo[number]; 

    memo[number] = fib_wrapper_recursive(number - 1, memo) + fib_wrapper_recursive(number - 2, memo);
    return memo[number];
}


unsigned long long int fib_wrapper_iterative(unsigned long long int number, unsigned long long int *memo) {
    if (number == 0) return 0; 
    if (number == 1) return 1; 

    unsigned long long int a = 0, b = 1;
    memo[0] = a;
    memo[1] = b;

    for (unsigned long long int i = 2; i <= number; i++) {
        unsigned long long int next = a + b;
        a = b;
        b = next;
        memo[i] = next; 
    }
    return b;
}


unsigned long long int fibonacci_recursive(unsigned long long int number) { //new memoization functions
    unsigned long long int *memo = calloc(number + 1, sizeof(unsigned long long int)); 
    unsigned long long int result = fib_wrapper_recursive(number, memo);
    free(memo); 
    return result;
}

unsigned long long int fibonacci_iterative(unsigned long long int number) {
    unsigned long long int *memo = calloc(number + 1, sizeof(unsigned long long int)); 
    unsigned long long int result = fib_wrapper_iterative(number, memo);
    free(memo); 
    return result;
}
