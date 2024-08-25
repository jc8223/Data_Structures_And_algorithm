// string Generation
//  given a string s1 of length l1 consisting of Latin uppercase alphabet characters, string s2 of length l2 consisting of character 'T' and 'F' only
//  generate a lexico-graphically smallest string s of length l1+l2-1 such that a substring of length l1 in string S starting at index(0<=i<=l2) is equal to string s1 if and only if s2[i] is 'T'(without quotes)
//  if no such string s exists, print -1
//  S1 represents string s1
//  S2 represents string s2
//  input: test cases, S1, S2
//  testcase:1
//  S1: ABCA
//  S2: TFFF
//  output: ABCAAAA

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		int l1 = s1.length();
		int l2 = s2.length();
		int l = l1 + l2 - 1;
		string s(l, 'A');
		for (int i = 0; i < l2; i++)
		{
			if (s2[i] == 'T')
			{
				for (int j = 0; j < l1; j++)
				{
					s[i + j] = s1[j];
				}
			}
		}
		for (int i = 0; i < l; i++)
		{
			if (s[i] == 'A')
			{
				s[i] = 'A' ;
			}
		}
		cout << s << endl;
	}
	return 0;
}
