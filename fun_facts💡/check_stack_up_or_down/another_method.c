#include <stdio.h>
#include <stdbool.h>

bool where_stack_grows() {
    volatile int x = 0;
    volatile int y = 0;

    if ( &x > &y ) {
        return false;
    } else {
        return true;
    }
}

int main(int argc, char** argv) {
    printf("The Stack Grows %s\n",where_stack_grows() == true ? "Upward" : "Downward" );
}

