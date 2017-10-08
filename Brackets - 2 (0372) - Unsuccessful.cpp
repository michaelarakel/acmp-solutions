#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <algorithm>

using namespace std;

bool isright(string& s)
{
	stack <char> st;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '(' ||
			s[i] == '[')
			st.push(s[i]);
		if (s[i] == ')')
		{
			if (st.empty() || st.top() == '[')
				return false;
			st.pop();
		}
		if (s[i] == ']')
		{
			if (st.empty() || st.top() == '(')
				return false;
			st.pop();
		}
	}
	return st.empty();
}

int main ()
{
	freopen ("INPUT.TXT", "r", stdin);
	freopen ("OUTPUT.TXT", "w", stdout);
	int n;
	cin >> n;
	for (int count = 0; count <= n; count += 2)
	{
		string s = "";
		for (int i = 0; i < (n - count)/2; ++i)
			s.push_back('(');
		for (int i = 0; i < (n - count)/2; ++i)
			s.push_back(')');
		for (int i = 0; i < count/2; ++i)
			s.push_back('[');
		for (int i = 0; i < count/2; ++i)
			s.push_back(']');
		do
		{
			if (isright(s))
				cout << s << endl;
		}
		while (next_permutation(s.begin(), s.end()));
	}
}