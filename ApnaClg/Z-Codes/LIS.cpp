
//Aryan Mittal

#include <bits/stdc++.h>
using namespace std;

int main()
{
	vector<int> arr{2,5,3,7,11,8,10,13,6};
	int n=arr.size();
	vector<int> lis_array;
	lis_array.push_back(arr[0]);
	
	for(int i=1; i<n; i++){
	if(arr[i] > lis_array.back())
		lis_array.push_back(arr[i]);
	else
	{
		int idx = lower_bound(lis_array.begin(),lis_array.end(),arr[i]) - lis_array.begin();
		lis_array[idx] = arr[i];
	}
	cout <<lis_array.size()<<endl;
	return 0;
}


//Tiling Problem B
int main()
{
	int n,m;
	cin>>n>>m;
	if(n<m) cout<<"1"<<endl;
	else{
		int dp[n+2]={0};
		for(int i=0;i<m;i++)
			dp[i]=1;
		for(int i=m;i<=n;i++)
			dp[i]=dp[i-1]+dp[i-m];

		cout<<dp[n]<<endl;
	}
}
//Tiling Problem B

void abc(int n)
{
	if (n==1 or n==2 or n==3) return 1;
	if (n==4) return 2;
	int dp[n+2]={0};

	for(int i=5;i<=n;i++)
	{
		dp[i]=dp[i-1]+dp[i-4];   //c= a+b;//a=b,b=c;

	}

	return dp[n];
}

//Q3

//To choose minimum in a window of 3

int main()
{
	int n;cin>>n;

	for(int i=0;i<n;i++) cin>>a[i];

	dp[0]=a[0];
	dp[1]=a[1];
	dp[2]=a[2];

	for(int i=3;i<n;i++)
	{
		int dp[i]= min(dp[i-1],dp[i-2],dp[i-3]) + a[i];
	}
	if (n==1)
		cout<<dp[0]<<"\n";
	else if(n==2)
		cout<<min(dp[0],dp[1])<<endl;
	else
		cout<<min(dp[0],dp[1],dp[2])<<endl;

   
}


//Trapping Rain Water for

class Solution {
	public :
	int trap(vector<int> &height)
	{
		int ans=0;
		int n=height.size();
		vector<int> left(n),right(n);

		if(n==0) return ans;
		left[0]=right[0];right[n-1]=height[n-1];

		for(int i=1;i<n;i++)
		{
			left[i]=max(left[i-1],height[i]);
		}
		for(int i=n-2;i>=0;i--)
		{
			right[i]=max(right[i+1],height[i]);
		}

		for(int i=0;i<n;i++)
		{
			ans+= min(left[i],right[i]) - height[i];
		}
		return ans;
	}
}



