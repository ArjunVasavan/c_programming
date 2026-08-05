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
    
        // 4 -> directory 8 -> file 10 -> softlink
        printf("%hhd %s\n",entity->d_type,entity->d_name);
        entity = readdir(dir);

        if(entity->d_type == DT_DIR ){
            printf("Its an directory\n");
        }

    }

    closedir(dir);

}
