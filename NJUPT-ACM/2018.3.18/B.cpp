#include<iostream>  
#include<string>
#include<algorithm>

using namespace std;

struct RVC_MEMORY{
	long long s;
	long long h;
	long long sh;
} chip[100002];

int n,s_sum;
long long ans;

bool cmp(RVC_MEMORY a, RVC_MEMORY b)
{
    if(a.s*b.h>a.h*b.s) return true;
    else if (a.s*b.h<a.h*b.s) return false;
    else
	{
        if (a.s > b.s) return true;//judge s, larger first
        else if (a.s < b.s) return false;
        else if(a.h < b.h) return true; else return false;//judge h,smaller first
    }

} 

int main() {
	ios::sync_with_stdio(false);
	cin >> n;
	string temp_string;
	char temp_char;
	for (int i=0; i<n;i++) {
		cin >> temp_string;
		int strlen=temp_string.length();
		for(int j=0;j<strlen;j++)
        {
            if (temp_string[j] == 's')chip[i].s++;
            else if (temp_string[j] == 'h')
			{
				chip[i].h++;
				chip[i].sh+=chip[i].s; // every h means it can coexist with all the s before it 
			}
        }
    }
    sort(chip,chip+n,cmp);
	for (int i=0;i<n;i++)
	{
        ans += chip[i].sh;
        ans += s_sum*chip[i].h;
        s_sum += chip[i].s;
    }
	cout << ans << endl;
	return 0;
}

