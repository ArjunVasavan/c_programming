#include <stdio.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char** argv) {
    
    DIR* dir = opendir(".");

    if ( dir == NULL ){
        return 1;
    }

    struct dirent* entity;

    entity = readdir(dir);

    while (entity != NULL) {
    
        printf("%s\n",entity->d_name);
        entity = readdir(dir);

    }

    closedir(dir);

}
