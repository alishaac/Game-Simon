//dptr_type 4:dir 8:file
//DIR *d dir pointer
//opendir
//readdir
//closedir
//dirent = dir entry str (name inode etc)

#include<stdio.h>
//#include<stdlib.h> if use exit then include
#include<dirent.h> 	//enable us to read the directory(dir entry)

struct dirent *dptr;

int main(int argc, char *argv[]){
	char name[100];
	DIR* dir; //pointer to directory
	int noargs = argc==1;
	for(int i=1;i<argc||noargs;i++){
		char * name; 
		if(noargs){
			name=".";
			noargs=0; //break
		}else{
			name=argv[i];
		}
		printf("%s\n",name);
		dir = opendir(name);
		if(dir!=NULL){
			dptr = readdir(dir);
			while(dptr!=NULL){
				printf("%s\t%ld,%d\n",dptr->d_name,dptr->d_ino,dptr->d_type);
				dptr=readdir(dir);
			}
			closedir(dir);
		}else{
			printf("Directory not found!\n");
		}
		printf("\n");
	}
	return 0;
}
