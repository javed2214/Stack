// Delete Even Elements from Stack

#include<bits/stdc++.h>
using namespace std;

int main(){

	int a[]={16,15,29,24,19};
	int n=sizeof(a)/sizeof(int);

	stack <int> S,temp;

	for(int i=0;i<n;i++) S.push(a[i]);

	while(!S.empty()){
		while(!S.empty() and S.top()%2==0){
			S.pop();
		}
		while(!S.empty() and S.top()%2!=0) temp.push(S.top()), S.pop();
	}
	while(!temp.empty()){
		S.push(temp.top());
		temp.pop();
	}

	while(!S.empty()){
		cout<<S.top()<<" ";
		S.pop();
	}

	return 0;
}