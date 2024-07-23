,          Read the first digit
>++++++[<-------->-]    Subtract '0' (48 in ASCII) to get the numeric value
[->+>+<<]      Copy the first digit to a new cell for multiplication
>,         Read the second digit
>++++++[<-------->-]    Subtract '0' to get the numeric value
<[->[->+>+<<]>[-<+>]<<<<]    Multiply the two digits and store the result in the first cell
++++++++++        Add '0' (48 in ASCII) to get the ASCII value of the result
.                 Print the result
[-]               Clear the result cell
++++++++++.       Print newline character
