#include<bits/stdc++.h>
using namespace std;

int main ()
{
    vector<int> v = {3,3};
    sort(v.begin(), v.end());
    int target = 6;
    int start = 0;
    int end = v.size()-1;
    int answer[2];
    int act_sum = v[start] + v[end];
    cout<<act_sum<<endl;
    cout<<1;
    while (start<end)
    {
        cout<<"entered"<<act_sum<<endl;
        
        if (act_sum == target)
        {
            cout<<"found";
            answer[0] = start;
            answer[1] = end;
            cout<<answer[0]<<","<<answer[1];
            break;
        }

        else if (act_sum>target)
        {
            end--;
            cout<<"end"<<v[end]<<endl;
        }
        else if (act_sum<target)
        {
            start++;
            cout<<"start"<<v[start]<<endl;
        }
        act_sum = v[start] + v[end];
        cout<<"sum"<<act_sum<<endl;
    }
}