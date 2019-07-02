#include <iostream>
#include <stack>

using namespace std;

int chartoint(char);

int main(){

    stack<string> input;

    stack<double> values;
    stack<char> operators;

    int val;
    char op;

for(int i = 0; i < input.size(); i++){
switch(input[i]){
	case "(":
		break;
	case "+":
	case "-":
	case "*":
	case "/":
	case "^":
		op.push(input[i]);
		break;
	case ")":
	{
		op = operators.pop();
		switch(op){
			case "+": val += values.pop(), break;
			case "-": val -= chartoint(values.pop()), break;
			case "*": val *= chartoint(values.pop()), break;
			case "/": val /= chartoint(values.pop()), break;
			case "^": val = pow(val,chartoint(values.pop())),, break;
		}
	values.push(val);
	}
	break;
}


    return 0;
}
}

int chartoint(char c) {
  if (c < '0' || c > '9')
    throw "Bad character";
  return c - '0';
}
