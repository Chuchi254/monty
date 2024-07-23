,          Read the first digit
>++++++[<-------->-]    Subtract '0' (48 in ASCII) to get the numeric value
[->+>+<<]      Copy the first digit to a new cell for multiplication
>,         Read the second digit
>++++++[<-------->-]    Subtract '0' to get the numeric value
>[-<->]    Prepare for multiplication
[<->-]     Multiply the two digits
<          Move to the cell with the result
++++++++++  Add '0' (48 in ASCII) to get the ASCII value of the result
.          Print the result
