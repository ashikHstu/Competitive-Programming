/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let cur = init;
    return {
        increment:function()
        {
            cur=cur+1;
            return cur;
        },
        decrement:function()
        {
            cur = cur-1;
            return cur;
        },
        reset:function()
        {
            cur=init;
            return cur;
        }
    }
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */

/*
Key Takeaways (Short)
var → old, unsafe, function scoped ❌
let → modern, block scoped, mutable ✔️
const → modern, block scoped, immutable reference ✔️
Always prefer const + let in modern JS 

*/