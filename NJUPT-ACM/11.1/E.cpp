#include<iostream>
#include<cstring>
#include<algorithm>

int seq[17],n,ans,fseq[17],lseq[17];
int distmap[17][17],path[17][17];
using namespace std;



int main()
{
	for(int i=1;i<=16;i++)
        for(int j=1;j<=16;j++){
            distmap[i][j]=1000000000;
            path[i][j]=j;
    }
    distmap[1][2]=1;
    distmap[2][4]=1;
    distmap[4][12]=1;
    distmap[12][11]=1;
    distmap[11][9]=1;
    distmap[9][1]=1;

    distmap[5][6]=1;
    distmap[6][8]=1;
    distmap[8][16]=1;
    distmap[16][15]=1;
    distmap[15][13]=1;
    distmap[13][5]=1;
    
    distmap[1][5]=1;
    distmap[2][6]=1;
    distmap[4][8]=1;
    distmap[12][16]=1;
    distmap[11][15]=1;
    distmap[13][9]=1;  
    
    distmap[10][9]=1;
    distmap[10][2]=1;
    distmap[10][12]=1;
    distmap[3][1]=1;
    distmap[3][11]=1;
    distmap[3][4]=1;
	
    distmap[7][5]=1;
    distmap[7][8]=1;
    distmap[7][15]=1;
    distmap[14][6]=1;
    distmap[14][13]=1;
    distmap[14][16]=1; 
	distmap[2][1]=1;
    distmap[4][2]=1;
    distmap[12][4]=1;
    distmap[11][12]=1;
    distmap[9][11]=1;
    distmap[1][9]=1;

    distmap[6][5]=1;
    distmap[8][6]=1;
    distmap[16][8]=1;
    distmap[15][16]=1;
    distmap[13][15]=1;
    distmap[5][13]=1;

    distmap[5][1]=1;
    distmap[6][2]=1;
    distmap[8][4]=1;
    distmap[16][12]=1;
    distmap[15][11]=1;
    distmap[9][13]=1;  

    distmap[9][10]=1;
    distmap[2][10]=1;
    distmap[12][10]=1;
    distmap[1][3]=1;
    distmap[11][3]=1;
    distmap[4][3]=1;

    distmap[5][7]=1;
    distmap[8][7]=1;
    distmap[15][7]=1;
    distmap[6][14]=1;
    distmap[13][14]=1;
    distmap[16][14]=1;  
	for(int k=1;k<=16;k++)
        for(int i=1;i<=16;i++)
            for(int j=1;j<=16;j++) {
                if(distmap[i][k]+distmap[k][j]<distmap[i][j]) {
                    distmap[i][j]=distmap[i][k]+distmap[k][j];
                    path[i][j]=path[i][k];
                }
            }
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1;i<=3;i++)
	{
		for(int j=1;j<=16;j++)cin >> seq[j];
		int num=0;
		for(int j=1;j<=8;j++)if(seq[j]){num++;fseq[num]=j;}
		num=0;
		for(int j=9;j<=16;j++)if(!seq[j]){num++;lseq[num]=j;}
		if(num>4)ans=4;
		else if(num==3)
		{
			int temp[16];
			memset(temp,0,sizeof(temp));
			temp[1]=distmap[fseq[1]][fseq[2]]+distmap[fseq[3]][lseq[1]]+distmap[lseq[2]][lseq[3]];
			temp[2]=distmap[fseq[1]][fseq[2]]+distmap[fseq[3]][lseq[2]]+distmap[lseq[1]][lseq[3]];
			temp[3]=distmap[fseq[1]][fseq[2]]+distmap[fseq[3]][lseq[3]]+distmap[lseq[1]][lseq[2]];
			temp[4]=distmap[fseq[1]][fseq[3]]+distmap[fseq[2]][lseq[1]]+distmap[lseq[2]][lseq[3]];
			temp[5]=distmap[fseq[1]][fseq[3]]+distmap[fseq[2]][lseq[2]]+distmap[lseq[1]][lseq[3]];
			temp[6]=distmap[fseq[1]][fseq[3]]+distmap[fseq[2]][lseq[3]]+distmap[lseq[1]][lseq[2]];
			temp[7]=distmap[fseq[1]][lseq[1]]+distmap[fseq[2]][fseq[3]]+distmap[lseq[2]][lseq[3]];
			temp[8]=distmap[fseq[1]][lseq[1]]+distmap[fseq[2]][lseq[2]]+distmap[fseq[3]][lseq[3]];
			temp[9]=distmap[fseq[1]][lseq[1]]+distmap[fseq[2]][lseq[3]]+distmap[fseq[3]][lseq[2]];
			temp[10]=distmap[fseq[1]][lseq[2]]+distmap[fseq[2]][fseq[3]]+distmap[lseq[1]][lseq[3]];
			temp[11]=distmap[fseq[1]][lseq[2]]+distmap[fseq[2]][lseq[1]]+distmap[fseq[3]][lseq[3]];
			temp[12]=distmap[fseq[1]][lseq[2]]+distmap[fseq[2]][lseq[3]]+distmap[fseq[3]][lseq[1]];
			temp[13]=distmap[fseq[1]][lseq[3]]+distmap[fseq[2]][fseq[3]]+distmap[lseq[1]][lseq[2]];
			temp[14]=distmap[fseq[1]][lseq[3]]+distmap[fseq[2]][lseq[1]]+distmap[fseq[3]][lseq[2]];
			temp[0]=distmap[fseq[1]][lseq[3]]+distmap[fseq[2]][lseq[2]]+distmap[fseq[3]][lseq[1]];
			sort(temp,temp+15);
			ans=temp[0];		
		}
		else if(num==2)
		{
			int temp1=distmap[fseq[1]][lseq[1]]+distmap[fseq[2]][lseq[2]];
			int temp2=distmap[fseq[1]][lseq[2]]+distmap[fseq[2]][lseq[1]];
			int temp3=distmap[fseq[2]][lseq[2]]+distmap[fseq[1]][lseq[1]];
			ans=min(temp1,min(temp2,temp3));
		}
		else if(num==1)
		{
			//两个点之间距离为几就是几步
			ans=distmap[fseq[1]][lseq[1]];
		}
		else
		{
			ans=0;
		}
		if(ans>3)cout << "Case #" << i << ": " << "more";
		else cout << "Case #" << i << ": " << ans;
		cout << endl;
	}
	return 0;
}
