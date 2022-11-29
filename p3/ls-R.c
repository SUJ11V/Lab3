#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>

void Print(DIR *pdir, char *path){
    DIR *pDir;
    struct dirent *pde;
    char *buf[256];
    char *buf2[512];
    while((pde = readdir(pdir)) != NULL){
        if(!strcmp(pde->d_name, ".") || !strcmp(pde->d_name, "..")){
            continue;
        }
        if(pde->d_type == 4){
            sprintf(buf2, "D:%s/", pde->d_name);//출력용
            sprintf(buf, "%s/%s", path, pde->d_name);//디렉토리 경로 전달용

            if((pDir = opendir(buf)) == NULL){
                perror("opendir");
            }
            Print(pDir, buf);
        }
        else{
            sprintf(buf2, "F:%s/\n", pde->d_name);
        }
        printf("%s", buf2);
    }
}

int main(int argc, char *argv[]){
    DIR *dir_struct;//디렉토리 구조체
    char *dir_name;//디렉토리 명

    if (argc == 1){
        strcpy(dir_name ,".");
    }
    if (argc == 2) {
        strcpy(dir_name, argv[1]);
    }
    if((dir_struct = opendir(dir_name)) == NULL){
        perror("opendir");
        exit(1);
    }

    Print(dir_struct, dir_name);
    printf("\n");
    return 0;
}
