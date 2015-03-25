#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

bool checkBracket(char open, char close) {
	if(open == '{' && close == '}')
		return true;
	else if(open == '(' && close == ')')
		return true;
	else if(open == '[' && close == ']')
		return true;
	else return false;
}

bool checkParantheses(char str[], int size) {
	stack<char> s;
	char temp;
	for(int i = 0; i < size; i++) {
		if(str[i] == '{' || str[i] == '(' || str[i] == '[') {
			s.push(str[i]);
		}
		else {
			if(!s.empty()) {
				temp = s.top();s.pop();
				if(!checkBracket(temp, str[i])) return false;
			} else return false;
		}
	}
	return true;
}

int main() {
	char str[100];
	cin >> str;
	if(checkParantheses(str, strlen(str)))
		cout << "Parantheses match" << endl;
	else
		cout << "Parantheses Don't Match" << endl;
}
