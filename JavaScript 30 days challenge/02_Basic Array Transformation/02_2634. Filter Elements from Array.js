/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    return arr.filter((x,i)=>fn(x,i));
};

//without filter method
/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    let result = [];
    for(let i=0;i<arr.length;i++)
    {
        if(fn(arr[i],i))result.push(arr[i]);
    }
    return result;
};
