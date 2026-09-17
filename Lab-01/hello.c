#include <stdio.h> // preprocessor directive

void foo(); // global prototype

int main(){ // main() declaration
    foo();
    return 0;
}

void foo(){ // Function declaration
    printf("Hello World\n");
}