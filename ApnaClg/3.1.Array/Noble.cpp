
#include <bits/stdc++.h>
using namespace std;

int nobleInteger(int arr[], int n)
{
    map<int,int>mp;

	for (int i = 0; i < n; i++) {
		if (arr[i] < 0) {
			continue;
		}
		else if (arr[i] >= n) {
            mp[n]++;
		}
		else {
            mp[arr[i]]++;
		}
	}
	int totalGreater = mp[n];

	for (int i = n - 1; i >= 0; i--) {

		if (totalGreater == i   && mp[i]>0)  {
			return i;
		}
		else if (totalGreater > i) {
			return -1;
		}
		totalGreater +=   mp[i];
	}
	return -1;
}


int main()
{
	int arr[] = { 10, 3, 20, 40, 2 };
	int res = nobleInteger(arr, 5);
	if (res != -1)
		cout << "The noble integer is " << res;
	else
		cout << "No Noble Integer Found";
	return 0;
}
