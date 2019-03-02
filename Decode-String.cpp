// Decode String
// https://www.geeksforgeeks.org/decode-string-recursively-encoded-count-followed-substring/
/*
Input : str[] = "2[ab]"
Output : abab

Input : str[] = "2[a2[b]]"
Output : abbabb
*/

#include<bits/stdc++.h>
using namespace std;

int main(){

	string str,s,res;
	cin>>str;
	
	int n=str.length();
	
	stack <int> integerStack;		// Integer Stack
	stack <char> charStack;			// Character Stack

	for(int i=0;i<n;i++){

		char ch=str[i];
		
		if(isdigit(ch)){

			int count=0;
			while(isdigit(str[i])){
				count=count*10+str[i]-'0';
				i++;
			}
			i-=1;
			integerStack.push(count);
		}
		
		else if(isalpha(ch)) charStack.push(ch);
		
		else if(ch=='['){

			if(str[i-1]>='0' and str[i-1]<='9')
				charStack.push(str[i]);
			else{
				charStack.push(str[i]);
				integerStack.push(1);
			}
		}
		else{

			string temp,res;
			int count=0;
			if(!integerStack.empty()){
				count=integerStack.top();
				integerStack.pop();
			}
			while(!charStack.empty() and charStack.top()!='['){
				temp=charStack.top()+temp;
				charStack.pop();
			}
			if(charStack.top()=='[') charStack.pop();

			for(int j=0;j<count;j++)
				res=res+temp;

			for(int j=0;j<res.length();j++)
				charStack.push(res[j]);
		}
	}
	str.clear();
	while(!charStack.empty()){
		str=charStack.top()+str;
		charStack.pop();
	}
	cout<<str;

	return 0;
}
