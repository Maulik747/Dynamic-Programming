#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int>answer;
    int n;
    int position;
    cin>>n;
    int val[n][n];
    int arr[n][n];
    for (int i=0; i<n;++i)
    {
        for (int j=0 ;j<n;++j)
        {
            val[i][j]=0;
            arr[i][j]=0;
        }
    }
    for (int i=0; i<n;++i)
    {
        for (int j=0;j<=i;++j)
        {
            cin>>val[i][j];
        }
    }
    arr[0][0]=val[0][0];
    for(int i=1; i<n;++i)
    {
        for (int k=0; k<=i;++k)
        {
            if (k==0)
            {
                arr[i][k]=arr[i-1][k]+val[i][k];
            }
            else if(k==i)
            {
                arr[i][k]=arr[i-1][k-1]+val[i][k];
            }
            else
            {
                if(arr[i-1][k]>arr[i-1][k-1])
                {
                    arr[i][k]=arr[i-1][k]+val[i][k];
                }
                else
                {
                    arr[i][k]=arr[i-1][k-1]+val[i][k];
                }
            }
        }
    }
    int max= arr[n-1][0];
    for (int i=0 ;i<n;++i)
    {
        if(arr[n-1][i]>max)
        {
            max=arr[n-1][i];
            position=i;
        }
    } 
    answer.push_back(val[n-1][position]);

    for (int i=n-1; i>0;--i)
    {
        if(arr[i][position]==val[i][position]+arr[i-1][position])
        {
            answer.push_back(val[i-1][position]);
        }
        else{
            answer.push_back(val[i-1][position-1]);
            position--;
        }
    }
    cout<<max<<endl;
    for (auto it= answer.crbegin(); it!=answer.crend();++it)
    {
        cout<<*it<<" ";
    }


}