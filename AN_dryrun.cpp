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
	     cout << """I is " << i << endl;
        if (isalnum(infix[i])) { // isalnum is a built-in function that checks if the character is an alphabet or digit
            cout << "if i " << i << endl;
            postfix += infix[i]; // if infix at the ith index is a character or digit, store it into the postfix expression
            cout << "Postfix " << postfix;
        } else if (infix[i] == '(') { // if infix at the ith index has an opening bracket, then push it into the stack because parentheses have the highest precedence
            cout << "else if i " << i;
			charstack.push(infix[i]);
		
        } else if (infix[i] == ')') { // if infix at the ith index has a closing bracket, then pop all opening brackets
            while (charstack.top() != '(') {
            	cout << "2nd else if i" << i;
                postfix += charstack.top();
                cout << "Postfix after 2nd else if " << postfix << endl; 
                charstack.pop();
            }
            charstack.pop(); // pop '('
        } else { // If it's an operator
            while (!charstack.empty() && precedence(infix[i]) <= precedence(charstack.top())) {
                postfix += charstack.top();
                cout << "Postfix after else "<< postfix << endl;
                charstack.pop();
                cout << "else i" << i;
            }
            charstack.push(infix[i]); // Push the current operator onto the stack
            cout << "Push " << i << endl;
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
    	cout << "I " << i << endl; 
    	cout << "infix at " << i << "th index " << infix[i] << endl; 
            
        if (isalnum(infix[i])) {
            prefix = infix[i] + prefix;
            
            cout << "if prefix " << prefix << endl; 
        } else if (infix[i] == ')') {
            charstack.push(infix[i]);
            cout << "i " << i << " ";
            cout << "Else if (push)" << endl;   
        } else if (infix[i] == '(') {
            while (!charstack.empty() && charstack.top() != ')') {
            	cout << " 2nd else if i " << i << " ";
           
                prefix = charstack.top() + prefix;
                cout << "2nd else if prefix " << prefix << endl;
                charstack.pop();
            }
            charstack.pop(); // Pop ')'
        } else {
        	cout << "else " << endl;
            while (!charstack.empty() && precedence(infix[i]) < precedence(charstack.top())) {
            	cout << "while i " << i << " ";
                prefix = charstack.top() + prefix;
                cout << "Prefix of while " << prefix << endl;
                charstack.pop();
            }
            cout << "push" << endl;
            charstack.push(infix[i]);
        }
    }
   cout << "for Loop  terminate" << endl;
    while (!charstack.empty()) {
        prefix = charstack.top() + prefix;
        cout << "for loop kay outside wala while " << prefix << endl;
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
    	cout <<"I = " << i << endl;
    	cout << "Prefix" << i << "th index" << prefix[i] << endl;
        if(isalnum(prefix[i])) {
            string operand(1, prefix[i]); // Create a string from the operand character
            cout << "if push operand and i = " << i << endl;
            charstack.push(operand); // Push operands onto the stack
        } else if(isOperator(prefix[i])) {
        	cout << "else if i " << i << endl;
            string operand1 = charstack.top();
            cout << "Operand 1 " << operand1 << endl;
            charstack.pop();
            string operand2 = charstack.top();
             cout << "Operand 2 " << operand2 << endl;
            charstack.pop();

            string result = operand1 + operand2 + prefix[i]; // Combine operands and operator
            cout << "Result " << result << endl;
            charstack.push(result); // Push the intermediate result back to the stack
            cout << "Push result " << endl;
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
       cout << "I " << i << endl;
    // check if symbol is operator
    if (isOperator(prefix[i])) {
     cout << "if i " << i << endl;
      // pop two operands from stack
      string op1 = s.top();   
	  cout << "op1 " << op1 << endl;
	  s.pop();
      string op2 = s.top();   s.pop();
      cout << "op2 " << op2 << endl;
 
      // concat the operands and operator in between them
      string temp = "(" + op1 + prefix[i] + op2 + ")";
      cout << "temp " << temp << endl;
      // Push string temp back to stack
      s.push(temp);
      cout << "push temp " << endl;
    }
 
    // if symbol is an operand
    else {
 
      // push the operand to the stack
      cout << "else i " << i << endl; 
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
        cout << "I " << i << endl;
        if (isOperand(postfix[i])) {
            cout << "If i " << i << endl;
            string op = "";
            op += postfix[i];
            cout << "op after concatenation" << op << endl;
            cout << "push operand " << endl;
            s.push(op);
        }
        // If operator
        else {
        	cout << "else " << endl;
            string op1 = s.top();
            cout << "Op1 " << op1 << endl;
            s.pop();
            string op2 = s.top();
            cout << "Op2 " << op2 << endl;
            s.pop();
            // Concatenate strings directly
            cout << "push op2 + postfix[" << i << "]" << endl;
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
    cout << "\n\n\n\n\n\n\n\n";
    cout << "2nd infix to prefix " << endl;
    infixto_prefix(iinfix);
    // Function call for prefix to postfix
    cout << "\n\n\n\n\n\n";
    cout << "Prefix to postfix dry run";
     string prefix = "*+AB-CD";
    prefixto_Postfix(prefix);
    prefix = "*-A/BC-/AKL";
     prefixto_Postfix(prefix);
     cout << "\n\n\n\n\n\n";
    cout << "Prefix to infix dry run";
    prefix = "*+AB-CD";
    cout << "Infix from prefix " << prefix << " is " << prefix_ToInfix(prefix) << endl;
     prefix = "*-A/BC-/AKL";
    cout << "Infix from prefix " << prefix << " is " << prefix_ToInfix(prefix) << endl;
    string postfix;
    postfix = "abc++";
    cout << "Post fix to Infix Expression is " << posttoInfix(postfix) << endl;
    postfix = "ab*c+";
    cout << "Post fix to Infix Expression is " << posttoInfix(postfix) << endl;
     
    return 0;
}

