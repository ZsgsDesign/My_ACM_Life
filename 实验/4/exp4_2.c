#include<stdio.h>

char temp;

int main()
{
	FILE* fp;
	FILE* fp2;
	fp=fopen("D:\\f1.txt","r");
	fp2=fopen("D:\\f2.txt","w+");
	while(~fscanf(fp,"%c",&temp))
	{
		printf("%c",temp); //Êä³öf1
		if((temp>='a' && temp<='z') || (temp>='A' && temp<='Z')) 
		{
			fprintf(fp2,"%c%d",temp,temp);
		}
	}
	fclose(fp);
	printf("\n");
	rewind(fp2);
	while(~fscanf(fp2,"%c",&temp)) printf("%c",temp); //Êä³öf2
	fclose(fp2);
	return 0;
}

