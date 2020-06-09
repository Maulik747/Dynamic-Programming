#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n];
    int dp[n];
    string ans[n];
    int maxlength=1;
    for (int i=0; i<n;++i)
    {
        cin>>arr[i];
    }
    for (int i=0; i<n;i++)
    {
        dp[i]=1;
        ans[i]=to_string(arr[i])+" ";
    }
    for (int k=1; k<n;++k)
    {
        for (int m=0; m<k;++m)
        {
            if (arr[m]<arr[k])
            {
                if(dp[k]<dp[m]+1)
                {
                    dp[k]=dp[m]+1;
                    ans[k]=ans[m]+to_string(arr[k])+" ";
                    if(maxlength<dp[k])
                    {
                        maxlength=dp[k];
                    }
                }
            }
        }
    }
    for (int i=0; i<n;++i)
    {
       if (dp[i]==maxlength)
       {
           cout<<ans[i]<<endl;
           break;
       }
    
    }
    
    return 0;
}