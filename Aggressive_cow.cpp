/*
You are given an array of integers which represents positions available and an integer c(cows).
Now you have to choose c positions such that minimum difference between cows is maximized.
For example,
1 3 5 8 10
c=3

Output: 4
1 5 10
*/

#include <bits/stdc++.h>
using namespace std;

int count(vector<int>& position, int d) {
        int ans = 1, last = position[0];
        for (int i = 1; i < position.size(); ++i) {
            if (position[i] - last >= d) {
                ans++;
                last = position[i];
                
            }
        }
        return ans;
    }

int maxDistance(vector<int>& position, int m) {
      sort(position.begin(), position.end());
        int l = 0, r = position.back() - position.front();
        while (l <= r) {
            int mid = r - (r - l) / 2;
            if (count(position, mid)>=m)
                l = mid+1;
            else
                r = mid - 1;
        }
        return r;  
    }


main()
{
	#ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);

	#endif

	vector<int> nums;
   int i,n,x,m;
   cin>>n;
   for(i=0;i<n;i++)
   {
   	cin>>x;
   	nums.push_back(x);
   }
   
   cin>>m;
   cout<<maxDistance(nums,m)<<endl;
}
