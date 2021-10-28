#include<unistd.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<dirent.h>
#include <sys/stat.h>
#include <unistd.h>

void show_all(const char* path)
{

	DIR* dirp=opendir(path); //������FILE
	struct dirent* de=NULL; //dirent ��ȡ�ļ���Ŀ¼����
	struct stat st; //stat ��ȡ�ļ�����
	char path2[500];
	while(de=readdir(dirp))
	{
		if(strcmp(de->d_name,".")==0 || strcmp(de->d_name,"..")==0) continue;
		printf("%s\n",de->d_name);
		strcpy(path2,path);
		strcat(path2,"/");
		strcat(path2,de->d_name);
		stat(path2,&st);
		if(S_ISDIR(st.st_mode))
		{
			show_all(path2);
		}
	}
	closedir(dirp);
}

int main()
{
// 	DIR* dirp=opendir("./");
// 	chdir("./");
// 	struct dirent* de=NULL;
// 	struct stat st;
// 
// 	
// 
// 	while(de=readdir(dirp))
// 	{
// 		if(strcmp(de->d_name,".")!=0 && strcmp(de->d_name,"..")!=0)
// 		{
// 			printf("%s ",de->d_name);
// 			stat(de->d_name,&st);
// 
// 			if(S_ISDIR(st.st_mode))
// 			{
// 				printf("Ŀ¼\n");
// 			}
// 			else
// 			{
// 				printf("��Ŀ¼\n");
// 			}
// 		}
// 	}
// 	closedir(dirp);
	char* path = "./";
	show_all(path);
	return 0;
}





