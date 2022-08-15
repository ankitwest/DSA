// C++ program for solution of friends
// pairing problem Using Recursion
#include <bits/stdc++.h>
using namespace std;

int dp[1000];

// Returns count of ways n people
// can remain single or paired up.
int countFriendsPairings(int n)
{
	if (dp[n] != -1)
		return dp[n];

	if (n > 2)
		return dp[n] = countFriendsPairings(n - 1) + (n - 1) * countFriendsPairings(n - 2);
	else
		return dp[n] = n;
}

// Driver code
int main()
{
	memset(dp, -1, sizeof(dp));
	int n = 4;
	cout << countFriendsPairings(n) << endl;
	// this code is contributed by Kushdeep Mittal
}






// C++ program for solution of
// friends pairing problem
#include <bits/stdc++.h>
using namespace std;

// Returns count of ways n people
// can remain single or paired up.
int countFriendsPairings(int n)
{
	int dp[n + 1];

	// Filling dp[] in bottom-up manner using
	// recursive formula explained above.
	for (int i = 0; i <= n; i++) {
		if (i <= 2)
			dp[i] = i;
		else
			dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
	}

	return dp[n];
}

// Driver code
int main()
{
	int n = 4;
	cout << countFriendsPairings(n) << endl;
	return 0;
}

