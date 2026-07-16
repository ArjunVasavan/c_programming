#include <stdio.h>

unsigned char table[256];

void build_tabe() {

    table[0] = 0;

    for ( int i = 0; i < 256; i++) {
        table[i] = ( i & 1 ) + table[i>>1];
    }

}

unsigned int count_set_bits(int num) {
    return 
        table[num & 0xff]+
        table[ ( num >> 8 ) & 0xff ] +
        table[ ( num >> 16 ) & 0xff ] +
        table[ ( num >> 24 ) & 0xff ];
}

int main(int argc, char** argv) {

    build_tabe();
    int num = 10;
    printf("Number of set bits of %d is : %d\n",num,count_set_bits(num));
    
}
