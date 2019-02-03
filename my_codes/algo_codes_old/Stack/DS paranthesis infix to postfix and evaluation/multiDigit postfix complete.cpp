//
//   Author: Ashish patel , NIT Bhopal
// postfix_multidigit.cpp : Defines the entry pofloat for the console application.
//

#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
#include<vector>
#include<stack>
#include<math.h>
#include<cctype>
using namespace std;
float solvePostfix(const vector<string> &vect);
float evaluate(float a, float b, char op);
float find_postfix(string &infix);
bool check_validity(const string &str);
short prs(char ch);
int main()
{
	string infix;
	cout << "enter the infix expressions" << endl;
	cin >> infix;
	float ans = find_postfix(infix);
	if (ans != -99999) {
		cout << "postfix expression is " << infix << endl;
		cout << "solution of expression is " << ans << endl;
	}
	
	return 0;
}
float find_postfix(string &infix) {
	if (!check_validity(infix))
	{
		cout << "Invalid expression " << endl;
		return -99999;
	}
	cout << "Valid expression \n";
	vector<string>str;
	stack<char>s;
	short count = 0;
	string temp = "";
	for (char ch : infix) {


		if (isdigit(ch) || ch == '.') {
			temp += ch;
		}
		else {
			if (temp != "") {
				str.push_back(temp);
				temp = "";
			}
			if (s.empty()) {
				if (ch == '(')
					count++;
				s.push(ch);
			}
			else if (ch == '(')
			{
				count++;
				s.push(ch);
			}
			else if (ch == ')')
			{
				while (s.top() != '(') {
					str.push_back(string(1, s.top()));
					s.pop();
				}
				s.pop();
			}
			else {
				if (count > 0) {
					s.push(ch);
					count--;
				}
				else {
					while (prs(s.top()) >= prs(ch)) {//we have not dealt with the presedence of (,) so by default they have come to 1
						str.push_back(string(1, s.top()));
						s.pop();
						if (s.empty())
							break;
					}
					s.push(ch);
				}
			}
		}
	}
	if (temp != "")
		str.push_back(temp);
	while (!s.empty()) {
		str.push_back(string(1, s.top()));
		s.pop();
	}
	temp="";
	for (auto vectstr : str) {
		temp += vectstr;
	}
	infix = temp;
	return solvePostfix(str);
}

bool check_validity(const string &str) {
	stack<char>s;

	for (char ch : str) {
		if (ch == '(' || ch == ')')//means it is '(' or ')'
		{
			if (ch == '(')
				s.push(ch);
			else //if ')'
			{
				if (s.empty())
					return false;
				s.pop();
			}

		}
	}

	if (s.empty())
		return true;
	else
		return false;
}

short prs(char ch) {
	switch (ch) {
	case '^':	return 4;
	case '*':case'/':case'%': return 3;
	case '+':case'-': return 2;
	default: return  1;
	}
}


float solvePostfix(const vector<string> &vect) {
	stack<float>s;
	for (auto x : vect) {
		if (x.size() == 1 )//means operator
		{
			if (x[0] <= '9'&&x[0] >= '0')
			{
				s.push(stof(x));
				continue;
			}
			
			float a, b;
			a = s.top();
			s.pop();
			b = s.top();
			s.pop();
			s.push(evaluate(a, b, x[0]));
		}
		else//means some number 
			s.push(stof(x));
	}
	if (s.size() == 1)
		return s.top();
	else
		cout << "something wrong has happened! " << endl;
}
float evaluate(float a, float b, char op) {
	switch (op) {
	case '+': return a + b;
	case'-': return b - a;
	case '*': return a*b;
	case '/': return b / a;
	case '^': return pow(b, a);
	case '%': return  int(b) % int(a);
	default:	return -1;

	}
}
