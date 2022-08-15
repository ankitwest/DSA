// Recursive C program for
// coin change problem.
#include<stdio.h>

// Returns the count of ways we can
// sum S[0...m-1] coins to get sum n
int count( int array[], int noOfCoins, int money )
{
	// If n is 0 then there is 1 solution
	// (do not include any coin)
	if (money == 0)
		return 1;
	
	// If n is less than 0 then no
	// solution exists
	if (money < 0)
		return 0;

	// If there are no coins and n
	// is greater than 0, then no
	// solution exist
	if (noOfCoins <=0 && money >= 1)
		return 0;

	// count is sum of solutions (i)
	// including array[m-1] (ii) excluding array[m-1]
	return  count( array, noOfCoins, money-S[m-1] ) + count( array, noOfCoins - 1, money ) ;
}

// Driver program to test above function
int main()
{
	int i, j;
	int arr[] = {1, 2, 3};
	int noOfCoins = sizeof(arr)/sizeof(arr[0]);
	printf("%d ", count(arr, noOfCoins, 4));
	getchar();
	return 0;
}

























// C++ program for coin change problem.
#include<bits/stdc++.h>

using namespace std;

int count( int array[], int noOfCoins, int money )
{
	int i, j, x, y;

	// We need n+1 rows as the table
	// is constructed in bottom up
	// manner using the base case 0
	// value case (n = 0)
	int table[money + 1][noOfCoins];
	
	// Fill the enteries for 0
	// value case (n = 0)
	for (j = 0; j < noOfCoins; j++)
		table[0][j] = 1;

	// Fill rest of the table entries
	// in bottom up manner
	for (i = 1; i < money + 1; i++)
	{
		for (j = 0; j < noOfCoins; j++)
		{
			// Count of solutions including S[j]
			x = (i-array[j] >= 0) ? table[i - array[j]][j] : 0;

			// Count of solutions excluding S[j]
			y = (j >= 1) ? table[i][j - 1] : 0;

			// total count
			table[i][j] = x + y;
		}
	}
	return table[money][noOfCoins - 1];
}

// Driver Code
int main()
{
	int arr[] = {1, 2, 3};
	int noOfCoins = sizeof(arr)/sizeof(arr[0]);
	int money = 4;
	cout << count(arr, noOfCoins, money);
	return 0;
}

// This code is contributed
// by Akanksha Rai(Abby_akku)












int count( int S[], int noOfCoins, int n )		
{		
// table[i] will be storing the number of solutions for		
// value i. We need n+1 rows as the table is constructed		
// in bottom up manner using the base case (n = 0)		
int table[money+1];		
// Initialize all table values as 0		
memset(table, 0, sizeof(table));		
// Base case (If given value is 0)		
table[0] = 1;		
// Pick all coins one by one and update the table[] values		
// after the index greater than or equal to the value of the		
// picked coin		
for(int i=0; i<noOfCoins; i++)		
	for(int j=S[i]; j<=money; j++)		
		table[j] += table[j-S[i]];

return table[money];		
}		



