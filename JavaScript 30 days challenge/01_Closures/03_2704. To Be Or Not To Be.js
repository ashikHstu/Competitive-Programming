/**
 * @param {string} val
 * @return {Object}
 */
var expect = function(val) {
    return {
        toBe:function(insideVal)
        {
            if(val===insideVal)return true;
            throw new Error("Not Equal");
        },
        notToBe:function(insideVal){
            if(val !== insideVal)return true;
            throw new Error("Equal");
        }
    }
};

/**
 * expect(5).toBe(5); // true
 * expect(5).notToBe(5); // throws "Equal"
 */

/*
Object Creation
{} → creates an object (object literal)
Object can store:
Data (variables)
Functions (methods)
Each call to expect(val) → new object is created
Methods inside object can access val → closure
🔹 Equality Operators
✅ == (Loose Equal)
Compares values only
Performs type conversion (coercion) ❌
Examples:
5 == "5" → true
0 == false → true
null == undefined → true
❌ != (Loose Not Equal)
Opposite of ==
Also does type conversion
Example:
5 != "5" → false
✅ === (Strict Equal)
Compares value + type
No type conversion ✔️
Examples:
5 === 5 → true
5 === "5" → false
Used in your code → safe & predictable
✅ !== (Strict Not Equal)
Opposite of ===
True if value OR type differs
Examples:
5 !== "5" → true
5 !== 5 → false
🔹 How Everything Connects
expect(val) → creates object { toBe, notToBe }
Methods use closure to remember val
toBe() → uses ===
notToBe() → uses !==
🔹 Final Key Points (Short)
{} → object creation
Object can hold functions
Closure → functions remember val
== / != → loose (avoid ❌)
=== / !== → strict (use ✔️)
Enables: expect(5).toBe(5) 🚀


*/