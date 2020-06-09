#include<iostream>
#include<vector>
#define C 10
using namespace std;

int main()
{
    int num;
    vector<int> answer;
    int arr[C];
    for (int i=0; i<C;++i)
    {
        cin>>num;
        arr[i]=num;
        answer.push_back(1);
    }
    for (int i=0;i<C;++i)
    {
        for (int j=0; j<i;++j)
        {
            if(arr[i]>arr[j])
            {
                if(answer[i]<answer[j]+1)
                {
                    answer[i]=answer[j]+1;
                }
            }
        }
    }
    cout<<"***********************"<<endl;
    int a= answer.size();
    int max= answer[0];
    for (int i=1; i<a;++i)
    {
        if(max<answer[i])
        {
            max=answer[i];
        }
    }
    cout<<max<<endl;
    return 0;

}