

#include <bits/stdc++.h>
using namespace std;

//öncelik belirleme
int oncelik(char c)
{
	if (c == '^')
		return 3;
	else if (c == '/' || c == '*')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;
}

// The main function to convert infix expression
// to postfix expression
void infixToPostfix(string s)
{

	stack<char> st; //stack kullanýyoruz
					
	string result;

	for (int i = 0; i < s.length(); i++) {//s.lenght boyunca for döngüsü 
		char c = s[i];

		//girilen karakterleri ttanýmak için
		if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9'))
			result += c;

		// 
		// ‘(‘, eger karakter buysa yýðýna push edilir
		else if (c == '(')
			st.push('(');

		// ')' girilen karakter buysa yýgýna pop edilir
		//bir sonraki  ‘(‘ bu karaktere kadar
		else if (c == ')') {
			while (st.top() != '(') {
				result += st.top();
				st.pop();
			}
			st.pop();
		}

		// If an operator is scanned
		else {
			while (!st.empty()
				&& prec(s[i]) <= prec(st.top())) {
				if (c == '^' && st.top() != '^')
					break;
				else {
					result += st.top();
					st.pop();
				}
			}
			st.push(c);
		}
	}

	// Pop all the remaining elements from the stack
	while (!st.empty()) {
		result += st.top();
		st.pop();
	}

	cout << result << endl;
}

// Driver program to test above functions
int main()
{
	string exp = "a+b*(c^d-e)^(f+g*h)-i";
	infixToPostfix(exp);
	return 0;
}

