#include<iostream>  
#include<algorithm>  
#include<vector>  
  
using namespace std;  
//返回两部分的差值  
int diff(vector<int>& vec)  
{  
    int len = vec.size();  
  	len--;
    int sum = 0;  
    for (int i = 1; i <= len; ++i) {  
        sum += vec[i];  
    }  
  
    vector< vector<int> > dp;  
    for (int i = 0; i <= len; i++) {  
        vector<int>tmp;  
        for (int j = 0; j <= sum / 2; ++j) {  
            tmp.push_back(0);  
        }  
        dp.push_back(tmp);  
    }  
  
    for (int i = 1; i <= len; ++i) {  
        for (int j = 1; j <= sum / 2; ++j) {  
            if(j>=vec[i])dp[i][j] = max(dp[i-1][j],dp[i-1][j-vec[i]]+vec[i]);  
            else dp[i][j] = dp[i - 1][j];  
        }  
    }  
  
    return sum - 2*dp[len][sum / 2];  
}  
  
int main()  
{  
    vector<int> vec = {0,1,2,3 ,4,5};   
    cout << diff(vec) << endl;  
    return 0;  
}  
