#include <iostream>
#include <stack>
using namespace std;

// Function to check if brackets are balanced(This functioncode is from website)

bool areBracketsBalanced(string expr) {
    // Declare a stack to hold the previous brackets   
    stack<char> temp;
    
    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] == '[') {
            // If the current character is an opening bracket, push it onto the stack
            temp.push(expr[i]);  
        }
        else if (!temp.empty() && ((temp.top() == '(' && expr[i] == ')') ||
                                   (temp.top() == '{' && expr[i] == '}') ||
                                   (temp.top() == '[' && expr[i] == ']'))) {
            // If we found any complete pair of brackets, then pop
            temp.pop();
        }
        else {
            // If the current character is not a closing bracket or there's no matching opening bracket in the stack,
            // push the current character onto the stack
            temp.push(expr[i]);
        }
    }
    
    // If stack is empty return true, otherwise return false
    return temp.empty();
}

int precedence(char ch) {
    if (ch == '^') {
        return 3;
    } else if (ch == '*' || ch == '/') {
        return 2;
    } else if (ch == '+' || ch == '-') {
        return 1;
    } else {
        return -1;
    }
}

void infixToPostfix_Conversion(string infix) {
    string postfix = "";
    stack<char> charstack;
    for (int i = 0; i < infix.length(); i++) 
	{    
	     
        if (isalnum(infix[i])) { // isalnum is a built-in function that checks if the character is an alphabet or digit
           
            postfix += infix[i]; // if infix at the ith index is a character or digit, store it into the postfix expression
            
        } else if (infix[i] == '(') { // if infix at the ith index has an opening bracket, then push it into the stack because parentheses have the highest precedence
           
			charstack.push(infix[i]);
		
        } else if (infix[i] == ')') { // if infix at the ith index has a closing bracket, then pop all opening brackets
            while (charstack.top() != '(') {
            
                postfix += charstack.top();
                
                charstack.pop();
            }
            charstack.pop(); // pop '('
        } else { // If it's an operator
            while (!charstack.empty() && precedence(infix[i]) <= precedence(charstack.top())) {
                postfix += charstack.top();
               
                charstack.pop();
                
            }
            charstack.push(infix[i]); // Push the current operator onto the stack
            
        }
    }
    
    // After processing the infix expression, empty the stack and append its contents to the postfix expression
    while (!charstack.empty())
	{
        postfix += charstack.top();
        charstack.pop();
    }
    cout << "Postfix: " << postfix << endl;
}
void infixto_prefix(string infix) {
    string prefix;
    stack<char> charstack;
   
    for (int i = infix.length() - 1; i >= 0; i--) {
    
        if (isalnum(infix[i])) {
            prefix = infix[i] + prefix;
            
        } else if (infix[i] == ')') {
            charstack.push(infix[i]);
           
        } else if (infix[i] == '(') {
            while (!charstack.empty() && charstack.top() != ')') {
            	
                prefix = charstack.top() + prefix;
                
                charstack.pop();
            }
            charstack.pop(); // Pop ')'
        } else {
            while (!charstack.empty() && precedence(infix[i]) < precedence(charstack.top())) {
            	
                prefix = charstack.top() + prefix;
                
                charstack.pop();
            }
            charstack.push(infix[i]);
        }
    }
   
    while (!charstack.empty()) {
        prefix = charstack.top() + prefix;
       
        charstack.pop();
    }

    cout << "Prefix: " << prefix << endl;
}

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
void prefixto_Postfix(string prefix) {
    stack<string> charstack;
    string postfix = "";

    for(int i = prefix.length() - 1; i >= 0; i--) {
        if(isalnum(prefix[i])) {
            string operand(1, prefix[i]); // Create a string from the operand character
            charstack.push(operand); // Push operands onto the stack
        } else if(isOperator(prefix[i])) {
            string operand1 = charstack.top();
            charstack.pop();
            string operand2 = charstack.top();
            charstack.pop();

            string result = operand1 + operand2 + prefix[i]; // Combine operands and operator
            charstack.push(result); // Push the intermediate result back to the stack
        }
    }

    postfix = charstack.top(); // The top of the stack will contain the final postfix expression
    cout << "Postfix Expression is " << postfix << endl;
}
string prefix_ToInfix(string prefix) {
  stack<string> s;
 
  // length of expression
  int length = prefix.size();
 
  // reading from right to left
  for (int i = length - 1; i >= 0; i--) {
 
    // check if symbol is operator
    if (isOperator(prefix[i])) {
 
      // pop two operands from stack
      string op1 = s.top();   s.pop();
      string op2 = s.top();   s.pop();
 
      // concat the operands and operator in between them
      string temp = "(" + op1 + prefix[i] + op2 + ")";
 
      // Push string temp back to stack
      s.push(temp);
    }
 
    // if symbol is an operand
    else {
 
      // push the operand to the stack
      s.push(string(1, prefix[i]));
    }
  }
 
  // Stack now contains the Infix expression
  return s.top();
}
bool isOperand(char x) {
    
    // This function checks if the character is an operand
    return isalnum(x);
}

string posttoInfix(string postfix) {
    stack<string> s;

    for (int i = 0; postfix[i] != '\0'; i++) {
        // Push if operands
        if (isOperand(postfix[i])) {
            
            string op = "";
            op += postfix[i];
            s.push(op);
        }
        // If operator
        else {
            string op1 = s.top();
            s.pop();
            string op2 = s.top();
            s.pop();
            // Concatenate strings directly
            s.push("(" + op2 + postfix[i] + op1 + ")");
        }
    }

    // There must be a single element
    // in stack now which is the required
    // infix.
    return s.top();
}
void post_to_pre()
{
	//post to infix 
	// infix to prefix
	//or post to prefix directly
}	


int main() {
    string expr = "[{()}]";

    // Function call of Balanced Parenthesis
    if (areBracketsBalanced(expr))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;
    // Function call for infix to postfix
    string infix = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostfix_Conversion(infix);
    // Function call for infix to prefix
    infix = "A+B*C+D";
    infixToPostfix_Conversion(infix);
    infix = "((A+B)–C*(D/E))+F";
    string iinfix;
	iinfix = "A*B+C/D";
	cout << "First infix to prefix " << endl;
    infixto_prefix(iinfix);
    iinfix = "(A-B/C)*(A/K-L)";
    cout << "2nd infix to prefix " << endl;
    infixto_prefix(iinfix);
    // Function call for prefix to postfix
    string prefix = "*+AB-CD";
    prefixto_Postfix(prefix);
    prefix = "*-A/BC-/AKL";
     prefixto_Postfix(prefix);
   //
    cout << "Infix from prefix " << prefix << " is " << prefix_ToInfix(prefix) << endl;
    string postfix;
    postfix = "abc++";
    cout << "Infix Expression is " << posttoInfix(postfix) << endl;
    postfix = "ab*c+";
    cout << "Infix Expression is " << posttoInfix(postfix) << endl;
     
    return 0;
}

