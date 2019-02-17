#include<bits/stdc++.h>
using namespace std;
int x[205],y[205];
int main(){
	freopen("coordinates.in","r",stdin);
	freopen("coordinates.out","w",stdout);
    int n,x1,y1;
    cin>>n;
    int bx,by,sx,sy;
    cin>>sx>>by;
    x[0]=sx-sx;
    y[0]=-by+by;
    for(int i=1;i<n-1;i++){
    	cin>>x[i]>>y[i];
	}
	cin>>bx>>sy;
	x[n-1]=bx-sx;
    y[n-1]=-sy+by;
    for(int i=1;i<n-1;i++){
    	x[i]=x[i]-sx;
    	y[i]=-y[i]+by;
	}
	int co[by-sy+1][bx-sx+1];
	for(int i=0;i<bx-sx+1;i++)
	    for(int j=0;j<by-sy+1;j++)
	        co[j][i]=0;

	    
	for(int i=0;i<bx-sx+1;i++)co[by][i]=3;
	
	for(int i=0;i<by-sy+1;i++)co[i][-sx]=2;
	
	co[by][-sx]=4;
	
	for(int i=0;i<n;i++){
		co[y[i]][x[i]]=1;
	}
	for(int i=0;i<by-sy+1;i++){
	    for(int j=0;j<bx-sx+1;j++){
	    	if(co[i][j]==0)cout<<".";
	    	else if(co[i][j]==1)cout<<"*";
	    	else if(co[i][j]==2)cout<<"|";
	    	else if(co[i][j]==3)cout<<"-";
	    	else if(co[i][j]==4)cout<<"+";
		}
		cout<<endl;
	}
	return 0;
}
