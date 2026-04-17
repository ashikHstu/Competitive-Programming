/**
 * @return {Function}
 */
var createHelloWorld = function() {
    
    return function(...args) {
        return "Hello World";
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */


/*
Why return another function?
This is a closure (function inside a function).
The outer function (createHelloWorld) creates and returns a new function.
Common use cases:
        Function factory (generate customized functions)
        Encapsulation of logic
        Used in problems like currying / higher-order functions

What is ...args?
...args is called the rest parameter.
It collects all passed arguments into an array.

Example:
function test(...args) {
  console.log(args);
}

test(1, 2, 3); // [1, 2, 3]

Summary
Returning a function → enables higher-order functions / closures
...args → collects unlimited arguments into an array
Here, arguments are ignored → always returns "Hello World"

*/