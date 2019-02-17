#include<iostream>
#include<cstring>

using namespace std;
long long seq[500002],temp[500002],n,ans=0;

void lalala_sort(int seq_begin,int seq_end)
{
	if(seq_end-seq_begin<=1) return ;
	int mid=seq_begin+(seq_end-seq_begin)/2;
	lalala_sort(seq_begin,mid);
	lalala_sort(mid,seq_end);
	int cur=seq_begin, temp_mid=mid, i=seq_begin;
	while(cur<mid || temp_mid<seq_end)
	{
		if(cur<mid && seq[cur] <= seq[temp_mid]) temp[i++]=seq[cur++];
		else if(temp_mid>=seq_end) temp[i++]=seq[cur++];
		else
		{
			if(cur<mid) ans+=(mid-cur);
			temp[i++]=seq[temp_mid++];      
		}
	}
	for(i=seq_begin;i<seq_end;i++) seq[i] = temp[i];
}

int main()
{
	ios::sync_with_stdio(false);
    while(cin >> n)
    {
    	if(!n)break;
    	ans=0;
    	memset(seq,0,sizeof(seq));
    	memset(temp,0,sizeof(temp));
    	for(int i=0;i<n;i++)cin >> seq[i];
    	lalala_sort(0,n);
    	cout << ans << endl;
	}
    return 0;
}
