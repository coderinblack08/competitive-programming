# Regex notes
```js
const regex = /literal/g;
```
g flag - is search all (global)
i flag - is stop once found
m flag - 
s flag - 
y flag - 

| logical or, on string or other
() to group logical expressions

```js
const regex = /(Bob|Alice)/g;
```

? allow 0 or 1 times
* allow 0 or more times
+ one or more times

a{5} exactly 5 a's
a{5,} 5 or more a's
a{1,5} 1-5 a's

\ escape special characters

\d any digits
\w word characters
\t tabs
\n line breaks
. any character except newline

\D not digit
\W not word characters

[] character sets
```js
const regex = /[A-Z]/g;
```

^ negation

```js
const regex = /[^ABC]/g
// Not A, B, or C
```

