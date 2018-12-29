// Sort Stack Using another Stack.
#include<bits/stdc++.h>
using namespace std;

stack <int> sortStack(stack <int> &s);

int main(){
	stack <int> s;
	stack <int> temp;
	int n,p;
	cout<<"No of Stack Elements: ";
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>p;
		s.push(p);
	}
	temp=sortStack(s);
	while(!temp.empty()){
		cout<<"|\t"<<temp.top()<<"\t|\n";
		temp.pop();
	}
	return 0;
}
stack <int> sortStack(stack <int> &input){
	stack <int> temp;
	while(!input.empty()){
		int x=input.top();
		input.pop();

		while(!temp.empty() && temp.top() > x){
			input.push(temp.top());
			temp.pop();
		}
		temp.push(x);
	}
	return temp;
}