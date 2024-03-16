balancing.cpp:
    The program checks first checks if the input is an opening parenthesis, if it is
    the input gets pushed into the stack. If the character is a closing parenthesis, then
    the program will check if the top of the stack has a matching parenthesis, if it does 
    then the opening one is popped out of the stack. After iterating through if the stack is empty
    and all the parenthesis match then it is balanced. If the condifitons are not matched then 
    isBlanced = false; giving an Error statment which shows it is not balanced.

postfixEval.cpp: 
    I first check if the input is an integer, if it is then it is converted into an integer and 
    pushed into the stack. If it is an operator then the last two digits, which are 'A' and 'B' 
    are popped and converted to integers. The depending on the operator the conditions do the math.

infix2postfix.cpp
    First condition is if the value is an operand then it is stored into the result string, then my
    program checks if it is an operator, within this i check for conditions to see if stack is empty,
    if it is then push the operator into the stack and assign the 'top' value to it. Within this i aso 
    check for precedence and the while loop is used to check if the precedence is of the top value which 
    has not yet been stored in the stack is less then the top value in the stack, if it is then the value 
    in the stack is popped into the string 'result'. I also check for if the operators are eclosed in the
    brackets, to see if they should be popped. Using the while loop as a tool to check if there are multiple
    operators inside the parenthesis. 

Push function: 
    I first check if the stack does not reach higher than the maxsize. If it does not then the topIndex is
    incremented and the value at the top is stored into the top of the stack.

Pop function: 
    I first check if the stack does not pop more than it can, then I assign the topIndex value to the value 
    to be popped, then decrementing the total size of the stack and returning the pop value, which i did to make 
    things easier. 