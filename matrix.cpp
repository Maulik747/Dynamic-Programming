#include<iostream>
# define S 5
using namespace std;

int findmin(int a, int b, int c)
{
    if(a<=b && a<=c)
        return a;
    if(b<=a && b<=c)
        return b;
    else
        return c;
}

int main()
{
    int dp[S][S];
    int matrix[S][S];
    for (int i=0; i<S;++i)
    {
        for (int j=0; j<S;++j)
        {
            matrix[i][j]= (rand() & 1);///generate 0s and 1s
        }
    }
    for (int i=0; i<S;++i)
    {
        for (int j=0; j<S;++j)
        {
           cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    for (int i=0; i<S;++i)
    {
        dp[i][0]=matrix[i][0];
        dp[0][i]=matrix[0][i];
    }
    for (int i=1; i<S;++i)
    {
        for (int j=1; j<S;++j)
        {
            if(matrix[i][j]!=0)
            {
                dp[i][j]= findmin(dp[i-1][j-1],dp[i-1][j],dp[i][j-1])+matrix[i][j];//recursive formula
            }
            else{
                dp[i][j]=matrix[i][j];
            }
            
        }
    }
    cout<<endl;
    for (int i=0; i<S;++i)//dp matrix
    {
        for (int j=0; j<S;++j)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }

    int max=dp[0][0];
    for (int i=0; i<S;++i)
    {
        for (int j=0; j<S;++j)
        {
            if (dp[i][j]>max)
            {
                max=dp[i][j];
            }
        }
    } 
    cout<<"The largest sqaure with 1s is "<<max<<"X"<<max<<endl;

    
    
}