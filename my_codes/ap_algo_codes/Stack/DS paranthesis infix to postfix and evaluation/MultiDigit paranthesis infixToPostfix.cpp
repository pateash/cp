//
//   Author: Ashish patel , NIT Bhopal
// postfix_multidigit.cpp : Defines the entry point for the console application.
//

#include<iostream>
#include<algorithm>
#include<string>
#include<cstdio>
#include<vector>
#include<conio.h>
#include<stack>
#include<cstdio>
#include<cctype>
using namespace std;
string find_postfix(string &infix);
bool check_validity(const string &str);
short prs(char ch);
int main()
{
	system("color f9");
	string infix, postfix;
	cout << "enter the infix expressions" << endl;
	cin >> infix;
	postfix = find_postfix(infix);
	if (postfix != "-1")
		cout << "postfix expression is " << postfix << endl;

	_getch();
	return 0;
}
string find_postfix(string &infix) {
	if (!check_validity(infix))
	{
		cout << "invalid expression " << endl;
		return "-1";
	}
	cout << "valid expression \n";
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
					str.push_back(string(1,s.top()));



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
						str.push_back(string(1,s.top()));


						s.pop();
                        if(s.empty())break;
					}
					s.push(ch);


				}
			}
		}
	}
	if (temp != "")
		str.push_back(temp);
	while (!s.empty()) {
		str.push_back(string(1,s.top()));

		s.pop();
	}
	temp = "";
    for (auto vectstr : str) {
		temp += vectstr;
	}

	return temp;

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

