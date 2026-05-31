#include <stdio.h>

#define MAC(EXP) #EXP // stringfication

#define MERGE(a,b) a##b
int main(int argc, char** argv) {

    printf("%s\n",MAC(checking));

    MERGE(long i,nt) x = 10;

    printf("%lu\n",x);
}
