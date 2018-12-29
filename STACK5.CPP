// Prefix Expression Evaluation Using Stack
#include<bits/stdc++.h>
using namespace std;

int evaluate(int, int, char);

int main(){
	stack <int> S;
	string str;
	cin>>str;
	int i=str.length()-1;
	while(i>=0){
		if(isdigit(str[i]))
			S.push(str[i]-48);
		else{
			int t1,t2;
			t1=S.top();
			S.pop();
			t2=S.top();
			S.pop();
			int z=evaluate(t1,t2,str[i]);
			S.push(z);
		}
		i--;
	}
	cout<<S.top();
	S.pop();
	
	return 0;
}
int evaluate(int t1, int t2, char ch){
	if(ch=='+')
		return t1+t2;
	else if(ch=='-')
		return t1-t2;
	else if(ch=='*')
		return t1*t2;
	else
		return t1/t2;
}