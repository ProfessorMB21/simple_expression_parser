## The Simple Brace Expression Parser task
<br>
<bold>Requirements</bold>
<ul>
  <li>Make a stack data structure</li>
  <li>Let the user input a string of different types of parentheses</li>
  <li>Iterate across the string and perform the operations as follows:
    <li>Push to the stack a character of the supplied string iff it is an opening parenthesis</li>
    <li>
      If a character is a closing parenthesis, perform the following:
      <li>Check if the stack is not empty and the opening parenthesis on top of the stack is corresponding to the closing parenthesis
        <li>If yes, then pop the parenthesis on top of the stack</li>
      </li>
    </li>
  </li>
  <li>Keep on printing the pushed parentheses on the stack as well as the popped</li>
</ul>
