// Postfix Expression Evaluation using Stack
#include<bits/stdc++.h>
using namespace std;
int evaluate(int, int, char);
int main(){
	int i=0;
	stack <int> S;
	string str;
	cin>>str;
	while(str[i]!='\0'){
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
		i++;
	}
	cout<<S.top();
	S.pop();

	return 0;
}
int evaluate(int t1, int t2, char ch){
	if(ch=='+')
		return t1+t2;
	else if(ch=='-')
		return t2-t1;
	else if(ch=='/')
		return t2/t2;
	else
		return t2*t1;
}