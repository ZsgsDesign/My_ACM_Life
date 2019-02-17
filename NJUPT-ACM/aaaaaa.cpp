#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <limits.h>  
#include <malloc.h>  
#include <ctype.h>  
#include <math.h>  
#include <string>  
#include <iostream>  
#include <algorithm>  
using namespace std;  
#include <stack>  
#include <queue>  
#include <vector>  
#include <deque>  
#include <set>  
#include <map>  
#define INF 999999999  
#define eps 0.00001  
#define LL __int64d  
#define pi acos(-1.0)  
  
char str[20]="pqruvwxyzj";  
int num[20];  
int main()  
{  
    int t,i,j,vis[110],a[110],k,n;  
    scanf("%d",&t);  
    while(t--)  
    {  
        scanf("%d%d",&n,&k);  
        memset(vis,0,sizeof(vis));  
        for(i=0;i<n;i++)  
        {  
            scanf("%d",&a[i]);  
            //vis[a[i]]=1;  
        }  
        for(i=0;i<n;i++)  
        {  
            for(j=0;;j++)  
            {  
                if(a[i]>n)  
                    break;  
                if(!vis[a[i]])   
                {   
                    vis[a[i]]=1;   
                    break;  
                }  
                a[i]+=k;  
            }  
        }  
        sort(a,a+n);  
        for(i=0;i<n;i++)  
        {  
            if(a[i]!=i+1)  
                break;  
        }  
        if(i!=n)  
            printf("Tom\n");  
        else   
            printf("Jerry\n");  
    }  
    return 0;  
}  
