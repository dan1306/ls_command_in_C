#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>


int main(int argc, char *argvc[]){

    // for(int i = 0; i < argc; i++) {
    //     printf("%s\n", argvc[i]); 
    // }
    DIR *directory_stream;
    if(argc > 2){
        directory_stream = opendir(argvc[1]);
    } else {
        directory_stream = opendir(".");
    }
   
    if(directory_stream == NULL) {
        perror("ERROR: unable to return a pointer to the provided directory stream. \n Check provided input and try again.\n");
        return 0;
    }

    struct dirent *read_ptr = readdir(directory_stream);
    while (read_ptr != NULL) {
        printf("/%s\n",read_ptr->d_name);
        read_ptr = readdir(directory_stream);
    }
    closedir(directory_stream); 
    return 0;
}