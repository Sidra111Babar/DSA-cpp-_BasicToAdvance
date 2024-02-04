#include<iostream>
#include<stack>
using namespace std;
int main(){
	string userInput;
	cout << "Enter Your String ";
	getline(cin, userInput);
	stack<char> store_userString;
	for(char c : userInput){
	   store_userString.push(c);
	}
	cout << "Reverse string is ";
	while(!store_userString.empty()){
		cout << store_userString.top();
		store_userString.pop();   //After Printing topmost elment from stack remove it so that next character is topmost
	}
	
	return 0;
}
