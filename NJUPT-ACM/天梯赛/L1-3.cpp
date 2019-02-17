#include<iostream>
#include<cstring>

using namespace std;
string temp;
int str_len;
int table[25];
int a[25],b[25],ans[25];
int cur=1,mem;

int main()
{
	memset(a,-1,sizeof(a));
	memset(b,-1,sizeof(b));
	ios::sync_with_stdio(false);
	cin >> temp;
	str_len=temp.length();
	for(int i=1;i<=str_len;i++)
	{
		table[i]=temp[str_len-i]-'0';
		if(table[i]==0)table[i]=10;
	}
	cin >> temp;
	str_len=temp.length();
	for(int i=1;i<=str_len;i++) a[i]=temp[str_len-i]-'0';
	cin >> temp;
	str_len=temp.length();
	for(int i=1;i<=str_len;i++) b[i]=temp[str_len-i]-'0';
	while(1)
	{
		if(a[cur]==-1 && b[cur]==-1) break;
		int a_num=a[cur]==-1?0:a[cur];
		int b_num=b[cur]==-1?0:b[cur];
		int temp_sum=a_num+b_num+ans[cur];
		mem=temp_sum/table[cur];
		ans[cur]=temp_sum%table[cur];
		if(mem) ans[cur+1]+=mem;
		cur++;
	}
	int flag=0;
	for(int i=22;i>=1;i--)
	{
		if(ans[i]!=0)flag=1;
		if(flag)cout << ans[i];
	}
	if(!flag)cout << 0;
	cout << endl;
	return 0;
}
