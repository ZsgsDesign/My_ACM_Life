#include <iostream>  
#include <string>
#include <cstring>
#include <vector>
int ans_tot=0;
using namespace std; 
//vector<string> ans;
void is_legal(string seq)
{
    int ans = 0, temp = 0;
    char sign = '+';
    for(int i=0; i< seq.size();i++)
	{
		int temp2=0;
    	while(seq[i]>='0' && seq[i]<='9')
		{
			if(seq[i]>'0' && seq[i]<='9' && temp2!=999) 
			{
				if(temp2==0)temp2=999;
				else return ;
			}
			if(seq[i]=='0' && temp2!=999)temp2++;
			if(temp2==2)return ;
			temp=temp*10+(seq[i]-'0');
			i++;
		}
        if(seq[i] == '*'){
            int t = 0; 
			i++;
			temp2=0;
            for(;i<seq.size();i++)
			{
				if(seq[i]>'0' && seq[i]<='9' && temp2!=999)
				{
					if(temp2==0)temp2=999;
					else return ;
				}
				if(seq[i]=='0' && temp2!=999)temp2++;
				if(temp2==2)return ;
	            if(seq[i]>='0' && seq[i]<='9' ) t=t*10+seq[i]-'0'; 
				else
				{
					i--;
					break;
				}
			}            
			temp *= t;
			//假装有优先级 
        }
        else
		{
            if(sign=='+')ans+=temp;
            else ans-=temp;
            sign=seq[i];
			i++;
			temp=0;//假装有优先级 
			temp2=0;
            for(;i<seq.size();i++) 
			{
				if(seq[i]>'0' && seq[i]<='9' && temp2!=999)
				{
					if(temp2==0)temp2=999;
					else return ;
				}
				if(seq[i]=='0' && temp2!=999)temp2++;
				if(temp2==2)return ;
				if(seq[i]>='0' && seq[i]<='9') temp=temp*10+seq[i]-'0'; 
				else
				{
					i--;
					break;
				}
			}
        }
    }
    if(sign=='+') ans+=temp;
	else ans-=temp;
    if(ans == 2000) 
	{
    	ans_tot++;
    	cout << "  " << seq << endl;
	}
}

void dfs(int cur, string seq)
{
    if(cur == seq.size()-1)
	{
        is_legal(seq);
        //ans.push_back(seq);
        return ;
    }
	char signseq[5]={0,'+','-','*'};
    for(int i=1;i<=3;i++)
	{
        string temp=seq;
        temp.insert(cur,1,signseq[i]);
        dfs(cur+2,temp);
    }
    dfs(cur+1,seq); //这一位空 
}

int main()  
{
	ios::sync_with_stdio(false); 
	string seq;
	int i=0;
	while(cin >> seq && seq[0]!='=' )
	{
		i++;
		if(seq=="2000=" || seq.size()<=3)cout << "Problem "<< i << endl << "  IMPOSSIBLE" << endl;
		else
		{
			ans_tot=0;
			cout << "Problem "<< i << endl;
			dfs(1,seq);
			//cout << ans[j] << endl;
			if(ans_tot==0) cout << "  IMPOSSIBLE" << endl;
		}
	}
	//is_legal("2100-100");
    return 0;  
}  
