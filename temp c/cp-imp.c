#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/stat.h>

int main(int argc,char *argv[]){
    // if(argv[1]=="-r"){
    //     execlp("/mnt/e/codes/OS/offline/1/cp-r-implementation","/mnt/e/codes/OS/offline/1/cp-r-implementation",)
    // }
    FILE* fpr= fopen(argv[1],"r");
    FILE* fpw=fopen(argv[2],"w");
    char ch;
    if(fpr==NULL){
        printf("No file exist!\n");
        exit(0);
    }
    ch=fgetc(fpr);
    while(ch!=EOF){
        fputc(ch,fpw);
        ch=fgetc(fpr);
    }
    fclose(fpr);
    fclose(fpw);
    return 0;
}