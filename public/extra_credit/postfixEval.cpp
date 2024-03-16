#include "stack.hpp"

using namespace std;

int main(){
  freopen("input_postfixEval.txt", "r", stdin);
  string s;
  int solution;
  int line_counter = 0;
  while(cin>>solution){
    cin>>s;
    Stack<int> stack;
    
    // The input file is in the format "expected_solution postfix_expression"

    // We assume that all operands in the input are one digit (so they range from 0 to 9)
    for(int i=0; i<s.length(); ++i){
      // WRITE CODE HERE to evaluate the postfix expression in s
      // At the end of the loop, stack.pop() should contain the value of the postfix expression
      int c = 0;
      if (isdigit(s[i])){
        c = stoi(string(1, s[i]));
        stack.push(c);
      }
      else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/'){
        //Pop first two elements and depending on the current operartor calculate and push into stack.
        int A = int(stack.pop());
        int B = int(stack.pop());
        if ( s[i] == '+'){
          c = B + A;
          stack.push(c);
        }
        else if (s[i] == '-'){
          c = B - A;
          stack.push(c);
        }
        else if (s[i] == '*'){
          c = B * A;
          stack.push(c);
        }
        else if (s[i] == '/'){
          c = B / A;
          stack.push(c);
        }
      }
    }

    // Checking whether the value you calculated is correct ...
    int value = stack.pop();

    if(solution == value){
      cout << "line " << line_counter << ": OK [" << solution << " " << value << "]" << endl;
    }else{
      cout << "line " << line_counter << ": ERROR [" << solution << " " << value << "]" << endl;
    }
    line_counter++;
  }
}
