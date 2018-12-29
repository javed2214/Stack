// Check for Balanced Parentheses in an Expression
#include<bits/stdc++.h>
using namespace std;

bool compare(char, char);
int checkParentheses(char);

int main(){
	stack <char> S;
	string str;
	cout<<"Enter Expression: ";
	cin>>str;
	int i=0,x=0,y=0;
	while(str[i]!='\0'){
		char ch=str[i];
		if(checkParentheses(ch)){
			S.push(ch);
			x++;
		}
		else{
			char temp=S.top();
			S.pop();
			y++;
			if(!compare(temp,ch)){
				cout<<"Not Balanced";
				return 0;
			}
		}
		i++;
	}
	if(x==y)
		cout<<"Balanced";
	else
		cout<<"Not Balanced"; 
}
int checkParentheses(char ch){
	if(ch=='{' || ch=='(' || ch=='[')
		return 1;
	else
		return 0;
}
bool compare(char temp, char ch){
	if(temp=='{' and ch=='}')
		return true;
	else if(temp=='(' and ch==')')
		return true;
	else if(temp=='[' and ch==']')
		return true;
	else
		return false;
}
