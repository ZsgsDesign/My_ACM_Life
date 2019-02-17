#include <cstdio>  
#include <cstring>  
#include <cmath>  
#include <iostream> 

using namespace std;
 
void output(int pos)  
{  
    switch(pos)  
    {  
        case 1: printf("p"); break;  
        case 2: printf("q"); break;  
        case 3: printf("r"); break;  
        case 4: printf("u"); break;  
        case 5: printf("v"); break;  
        case 6: printf("w"); break;  
        case 7: printf("x"); break;  
        case 8: printf("y"); break;  
        case 9: printf("z"); break;  
    }  
}  
int main()  
{  
    int t;  
    long long num[20];  
    cin >> t;
    while(t--)  
    {  
        for(int i = 1; i <= 10; i++) cin >> num[i];
        int k = 0;
		int sum = 0;
        for(int i = 1; i <= 9; i++)  
        {  
            if(num[i] == 0)  
            {  
                sum++;  
                continue;  
            }  
            if(num[i] > 0)  
            {  
                if(k > 0) cout << "+";  
                if(num[i] != 1) cout << num[i];  
                k++;  
            }  
            else  
            {  
                if(num[i] != -1)  
                    cout << num[i];  
                else  
                    cout << "-";  
                k++;  
            }  
            output(i);  
        }
        if(num[10] == 0 && sum == 9) cout << 0 << endl;
        else if(num[10] == 0) cout << endl; 
        else
        {
            if(num[10] > 0)  
            {  
                if(sum == 9) cout << num[10] << endl;  
                else cout << "+" << num[10] << endl;  
            }  
            else cout << num[10] << endl;  
        }  
    }  
    return 0;  
}  
