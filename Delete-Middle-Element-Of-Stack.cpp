// Delete Middle Element of Stack
// Recursive Approach

#include<bits/stdc++.h>
using namespace std;

void deleteMid(stack <int> &S, int n, int curr=0){

	if(S.empty() or curr==n) return;
	int x=S.top();
	S.pop();
	deleteMid(S,n,curr+1);
	if(curr != n/2) S.push(x);
}

int main(){

	stack <int> S;
	S.push(1);
	S.push(2);
	S.push(3);
	S.push(4);
	S.push(5);
	S.push(6);
	S.push(7);

	deleteMid(S,S,size());

	return 0;
}