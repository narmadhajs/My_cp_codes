//Time Complexity: O(m+n)
//Auxiliary Space: O(n)



//code
// A C++ program that implements Z algorithm for pattern searching
#include<iostream>
using namespace std;

void getZarr(string str, int Z[]);

void search(string text, string pattern)
{
	
	string concat = pattern + "$" + text;
	int l = concat.length();

	int Z[l];
	getZarr(concat, Z);

	for (int i = 0; i < l; ++i)
	{
		if (Z[i] == pattern.length())
			cout << "Pattern found at index "
				<< i - pattern.length() -1 << endl;
	}
}

void getZarr(string str, int Z[])
{
	int n = str.length();
	int L, R, k;

	L = R = 0;
	for (int i = 1; i < n; ++i)
	{

		if (i > R)
		{
			L = R = i;
			while (R<n && str[R-L] == str[R])
				R++;
			Z[i] = R-L;
			R--;
		}
		else
		{
			// k = i-L so k corresponds to number which
			// matches in [L,R] interval.
			k = i-L;

			// if Z[k] is less than remaining interval
			// then Z[i] will be equal to Z[k].
			// For example, str = "ababab", i = 3, R = 5
			// and L = 2
			if (Z[k] < R-i+1)
				Z[i] = Z[k];

			// For example str = "aaaaaa" and i = 2, R is 5,
			// L is 0
			else
			{
				// else start from R and check manually
				L = i;
				while (R<n && str[R-L] == str[R])
					R++;
				Z[i] = R-L;
				R--;
			}
		}
	}
}

int main()
{
	string text = "ABBCD EFG ABBCD";
	string pattern = "ABBC";
	search(text, pattern);
	return 0;
}
