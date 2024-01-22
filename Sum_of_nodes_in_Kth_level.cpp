/*
Given an integer ‘K’ and a tree in string format. 
print the sum of all elements at Kth level from root.
Constraints

1 < k < 10

Output Format

single integer

Sample Input 0

2
(0(5(16()())(4()(9()())))(7(1()())(3()())))

Sample Output 0

24


*/
#include <iostream>
#include<string>
#include <vector>
using namespace std;
int main()
{
	#ifndef ONLINE_JUDGE
 
    freopen("input.txt", "r", stdin);
 
    freopen("output.txt", "w", stdout);

	#endif
	string s;
	int k,i=0,sum=0,level=-1;
	cin>>k>>s;
	while(i<s.size())
	{
		if(s[i]=='(') level++,i++;
		else if (s[i]==')') level--,i++;
		else
		{
			string temp;
			while(i<s.size()&& s[i]>='0' && s[i]<='9')
			{
				
				temp.push_back(s[i]);
				i++;
			}
			
			int ans= stoi(temp);
			if(level==k)
				sum+=ans;
		}
	}
	cout<<sum<<endl;




	return 0;
}