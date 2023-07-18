#include<bits/stdc++.h>
#include<vector>
using namespace std;
int countsubset(vector<int>& nums, int subsetsum){
    //initialize
    //cout<< "hello";
    int t[nums.size()+1][(subsetsum+1)];
    for (int i=0; i<=nums.size(); i++)
    {
        for (int j=0; j<=subsetsum; j++)
        {
            if (i==0)
            {
                t[i][j] = 0;
            }
            if (j == 0)
            {
                t[i][j] = 1;
            }
            // cout<<"i: "<<i<<" j: "<< j;
            if (i!=0 && j!=0)
            {
                if (nums[i-1] <= j)
                {
                    //cout<<nums[i-1];
                    t[i][j] = t[i-1][j-nums[i-1]] + t[i-1][j];
                    //cout<<"poke";
                }
                
                else 
                {
                    t[i][j] = t[i-1][j]; 
                }
            }
            cout<<t[i][j]<< " ";
        }
        cout<<endl;
    }
    return t[nums.size()][subsetsum];
}

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for (int i=0; i < nums.size(); i++)
        {
            //cout<< "hi";
            sum += nums[i];
        }
        if ((sum+target)%2 == 1)
        {
            int output = 0;
            return output;
        }
        int find_sum = (sum+target)/2;
        sort(nums.begin(), nums.end(), greater<int>());
        return countsubset(nums, find_sum);
    }
};
