
/*
Evaluate the value of an arithmetic expression in Reverse Polish Notation.

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
  ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
  ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
 */


////////////////////////////////////////////////////////////////////////////////

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if ( tokens.empty() ) return 0;
        stack<int> mystack;
        for ( int i=0; i<tokens.size(); i++ ) {
            switch( tokens[i][ tokens[i].size()-1 ] ) {
                case '+':
                {
                    int a = mystack.top();  mystack.pop();
                    int b = mystack.top();  mystack.pop();
                    mystack.push( b+a );
                }
                break;
                
                case '-':
                {
                    int a = mystack.top();  mystack.pop();
                    int b = mystack.top();  mystack.pop();
                    mystack.push( b-a );
                }
                break;
                
                case '/':
                {
                    int a = mystack.top();  mystack.pop();
                    int b = mystack.top();  mystack.pop();
                    mystack.push( b/a );
                }
                break;
                
                case '*':
                {
                    int a = mystack.top();  mystack.pop();
                    int b = mystack.top();  mystack.pop();
                    mystack.push( b*a );
                }
                break;
                
                default:
                {
                    mystack.push( atoi( tokens[i].c_str() ) );
                }
                break;
            }
        }
        return mystack.top();
    }
};