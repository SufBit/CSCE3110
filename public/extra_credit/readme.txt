Implementing my push funtion: 
    To implement a push function we have to create a new node, which i named head, making sure the current top node points to it, and add the value 
    we are trying to push into the stack, setting the new node item value to it. We then also make it the top node.

Implementing the Pop function: 
    To implement this we first check if the stack is empty or not, if not we create a temporary node which is the current top node, we also assign its item value
    to a variable 'item', which later we return. We make the top next value point to the next in the stack and delete the temporary node we made.

Implementing isEmpty():
    We just check if the top of the stack is NULL or not, returning true or fase depending on the sitatuion