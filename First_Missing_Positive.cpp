/*First_Missing_Positive.cpp
LEETCODE 41

Given an unsorted integer array nums, return the smallest missing positive integer.

You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

Input: nums = [1,2,0]
Output: 3

Input: nums = [3,4,-1,1]
Output: 2

*/

#include <bits/stdc++.h>
using namespace std;
int firstMissingPositive(vector<int>& nums) {
        int i,j,n,ind;
        n= nums.size();
        for(i=0;i<n;i++)
            if(nums[i]<1) nums[i]= n+1;
        for(i=0;i<n;i++)
        {
            ind = abs(nums[i])-1;
            if(ind<n && nums[ind]>0)
                nums[ind]= -1* nums[ind];
        }
        for(i=0;i<n;i++)
            if(nums[i]>0) return i+1;

        return n+1;
        
    }

main()
{
	#ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);

	#endif

   vector<int> nums;
   int i,n,x;
   cin>>n;
   for(i=0;i<n;i++)
   {
   	cin>>x;
   	nums.push_back(x);
   }
   

  cout<< firstMissingPositive(nums);

   
}