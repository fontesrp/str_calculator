# str_calculator
Calculate the value of a math expression

Given a string containing a valid math expression, calculate the result. Eg: "2 * 3 * (8 / 2) + 5 + 18 / 3 + 63 % 8" = 42.
I saw a simplified version of this problem somewhere and that got me curios.

I believe the solution here is to construct a binary tree from the expression. The challenge is finding the right place for each operation. I will first make a version that does not accept parenthesis and then try to improve it.

In the example above, the tree would be:

```
(+)
|-- (+)
|   |-- (*)
|   |   |-- (2)
|   |   `-- (*)
|   |       |-- (3)
|   |       `-- (÷)
|   |           |-- (8)
|   |           `-- (2)
|   `-- (+)
|       |-- (5)
|       `-- (÷)
|           |-- (18)
|           `-- (3)
`-- (%)
    |-- (63)
    `-- (8)
```
