# str_calculator
Calculate the value of a math expression

Given a string containing a valid math expression, calculate the result. Eg: "2 * 3 * (11 - 3) / 2 + 5 + 18 / 3 + 63 % 8" = 42.
I saw a simplified version of this problem somewhere and that got me curious.

The current version does not accept parenthesis yet.

In the example above, the tree would be:

```
(+)
|-- (+)
|   |-- (*)
|   |   |-- (2)
|   |   `-- (*)
|   |       |-- (3)
|   |       `-- (÷)
|   |           |-- (-)
|   |           |   |-- (11)
|   |           |   `-- (3)
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
