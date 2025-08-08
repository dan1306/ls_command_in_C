#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>


int main(){

    DIR *directory_stream = opendir("../");
    if(directory_stream == NULL) {
        perror("ERROR: unable to return a pointer to the provided directory stream. \n Check provided input and try again.\n");
        return 0;
    }

    struct dirent *read_ptr = readdir(directory_stream);
    while (read_ptr != NULL) {
        printf("/%s\n",read_ptr->d_name);
        read_ptr = readdir(directory_stream);
    }
    
    return 0;
}