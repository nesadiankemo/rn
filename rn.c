#include<stdio.h>
#include<string.h>
#define BUFFSIZE 4096
const char dir[] = "./create/";
int main()
{
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;
	FILE *fp_o = NULL;
	FILE *fp_d = NULL;
	char name_o[100];
	char name_d[100];
	char buff[BUFFSIZE];
	char path[200];
	int success = 0, n;
	int fail = 0;
	
	fp1 = fopen("origin", "r");
	if(fp1 == NULL){
		printf("origin open err\n");
		return 0;
	}
	fp2 = fopen("./destination", "r");
	if(fp1 == NULL){
		printf("destination open err\n");
		return 0;
	}
	while(fgets(name_o, 100, fp1) && fgets(name_d, 100, fp2)){
		n = strlen(name_o);
		name_o[n - 1] = '\0';
		fp_o = fopen(name_o, "r");
		if(fp_o == NULL){
			printf("%s open err1\n", name_o);
			fail ++;
			continue;
			//return 0;
		}
		n = strlen(name_d);
		name_d[n - 1] = '\0';
		strcpy(path, dir);
		strcat(path, name_d);	
		fp_d =fopen(path, "w");
		if(fp_d == NULL){
			printf("%s open err2\n", name_d);
			return 0;
		}
		printf("rename file %s to %s.\n ", name_o, name_d);
		while((n = fread(buff, 1, BUFFSIZE, fp_o)) != 0){
			//printf("n = %d\n", n);
			if(fwrite(buff, 1, n, fp_d) != n){
				printf("file %s write error\n", path);
				return 0;
			}
		}
		fclose(fp_o);
		fclose(fp_d);
		success ++;
	}	
	printf("success = %d, fail = %d\n", success, fail);
	return 1;
}
