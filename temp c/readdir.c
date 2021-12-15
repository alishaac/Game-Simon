#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
struct dirent *dptr;
int main(){
DIR *d; //pointer to a dir
char name[100];
printf("\n enter dir name : ");
scanf("%s",name);
if((d = opendir(name))==NULL){
printf("no entries with name provided\n");
exit(0);
}
while(dptr = readdir(d))
{
printf("\n%s",dptr -> d_name);
}
closedir(d);
}
