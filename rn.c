#include<stdio.h>
#include<string.h>
#define BUFFSIZE 4096

int main()
{
	FILE *fp1 = NULL;
	FILE *fp2 = NULL;
	FILE *fp_o = NULL;
	FILE *fp_d = NULL;
	char name_o[100];
	char name_d[100];
	char buff[BUFFSIZE];
	int count = 0, n;
	
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
			printf("%s open err\n", name_o);
			return 0;
		}
		n = strlen(name_d);
		name_d[n - 1] = '\0';

		fp_d =fopen(name_d, "w");
		if(fp_d == NULL){
			printf("%s open err\n", name_d);
			return 0;
		}
		while((n = fread(buff, 1, BUFFSIZE, fp_o)) != 0){
			printf("w");
			fwrite(buff, n, 1, fp_d);
		}
		fclose(fp_o);
		fclose(fp_d);
		count ++;
	}	
	printf("count = %d\n", count);
	return 1;
}
