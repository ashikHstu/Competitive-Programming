/**
 * @param {number} n
 * @return {Function} counter
 */
var createCounter = function(n) {

    return function() {
        n=n+1;
        return n-1;
    };
    
};

/** 
 * const counter = createCounter(10)
 * counter() // 10
 * counter() // 11
 * counter() // 12
 */

/*
createCounter(n) returns a function
That returned function remembers n (this is called a closure)
Each time you call counter(), it:
1) Increments n
2) Returns the previous value

How it works step-by-step:
const counter = createCounter(10); //n = 10 is stored inside the closure

Now calls:

counter() → returns 10 (then n becomes 11)
counter() → returns 11 (then n becomes 12)
counter() → returns 12 (then n becomes 13)

Why is n increasing inside the inner function?
Because only the inner function runs multiple times
The outer function runs only once when you create the counter

👉 Key idea:

Outer function = setup (runs once)
Inner function = execution (runs every time)

Key Points (Short):
Closure → inner function remembers n
Outer function runs once
Inner function runs every call
So update (n++) must be inside inner function
That’s how the counter increases each time 
*/