#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>

struct dirent *dent;

void displayFiles(DIR *folder){
    while(dent = readdir(folder)){
        printf("%s\n", dent->d_name);
    }
}

int main(int argc, char **argv){
    DIR *folder;
    
    // check if argv provided
    if(argc > 1){
        // no arg provided
        for(int i = 1; i < argc; i++){
            const char *folderName = argv[i];
            printf("Folder %s contents: \n", folderName);
            if((folder = opendir(folderName)) == NULL){
                printf("Sorry no name %s exists", folderName);
                continue;
            }
            displayFiles(folder);
        }
    }
    else{
        const char *folder_c = ".";
        if((folder = opendir(folder_c)) == NULL){
                printf("Sorry no name %s exists", argv[1]);
                exit(0);
        }
        displayFiles(folder);
    }
    // if argv is provided
    return 0;    
}