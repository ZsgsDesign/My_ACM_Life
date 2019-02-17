#include<stdlib.h>

int seq[100002]={9,5,1,6,3};
int comp(const void*a,const void*b){return *(int*)a-*(int*)b;}

int main()
{
	qsort(seq,5,sizeof(int),comp);
	return 0;
}
