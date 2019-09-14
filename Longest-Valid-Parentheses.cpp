// Program to Find Length of Longest Valid Parentheses
// https://leetcode.com/problems/longest-valid-parentheses/
// https://www.youtube.com/watch?v=r0-zx5ejdq0

#include<bits/stdc++.h>
using namespace std;

int longestValidParentheses(string str){

	stack <int> S;
	S.push(-1);

	int mx = 0;

	for(int i=0;i<str.length();i++){

		if(S.top() != -1 and str[i] == ')' and str[S.top()] == '('){
			S.pop();
			mx = max(mx, i - S.top());
		}
		else S.push(i);
	}

	return mx;
}

int main(){

	string str;
	cin>>str;

	cout << longestValidParentheses(str);

	return 0;
}