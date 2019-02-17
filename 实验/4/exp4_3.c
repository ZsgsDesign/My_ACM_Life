#include<stdio.h>
#include<string.h>

int n; //学生数量 
	
struct student
{
	char ID[20];
	char name[30];
	int age;
	double score;
} students[102];

void swap(int a,int b)
{
	students[100].score=students[a].score;
	students[a].score=students[b].score;
	students[b].score=students[100].score;
	
	students[100].age=students[a].age;
	students[a].age=students[b].age;
	students[b].age=students[100].age;
	
	strcpy(students[100].ID,students[a].ID);
	strcpy(students[a].ID,students[b].ID);
	strcpy(students[b].ID,students[100].ID);
	
	strcpy(students[100].name,students[a].name);
	strcpy(students[a].name,students[b].name);
	strcpy(students[b].name,students[100].name);
}

void ReadOut()
{
	int i;
	FILE* fp;
	fp=fopen("D:\\Info.dat","rb");
	for(i=1;i<=n;i++)
	{
		fscanf(fp,"%s%s%d%lf",students[i].ID,students[i].name,&students[i].age,&students[i].score);
		printf("%s\t%s\t%d\t%lf\n",students[i].ID,students[i].name,students[i].age,students[i].score);
	}
	fclose(fp);
}

void Sort()
{
	int i,j;
	for(i=1;i<n;i++) for(j=1;j<=n-i;j++) if (students[j].score<students[j+1].score) swap(j,j+1);
	for(i=1;i<=n;i++) printf("%s\t%s\t%d\t%lf\n",students[i].ID,students[i].name,students[i].age,students[i].score);
}

int main()
{
	int i;
	char ID[20];
	char name[30];
	int age;
	double score;
	FILE* fp;
	fp=fopen("D:\\Info.dat","wb");
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%s%s%d%lf",ID,name,&age,&score);
		fprintf(fp,"%s\t%s\t%d\t%lf\n",ID,name,age,score);
	}
	fclose(fp);
	printf("\n");
	ReadOut();
	printf("\n");
	Sort();
	return 0;
}

