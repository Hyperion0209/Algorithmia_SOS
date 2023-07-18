//https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
//Leetcode Easy
//26. Remove Duplicates from Sorted Array
#include<bits/stdc++.h>
#include <iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0)
        {
            return 0;
        }
        int first = 0;
        for (int second = 1; second < nums.size(); second++)
        {
            if (nums[first] != nums[second])
            {
                first++;
                nums[first] = nums[second];
            }
            else
            {
                continue;
            }
        }
        return  first+1;
    }
};