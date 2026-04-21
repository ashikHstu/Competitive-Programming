/**
 * @param {Promise} promise1
 * @param {Promise} promise2
 * @return {Promise}
 */
var addTwoPromises = async function(promise1, promise2) {
    let v1=await promise1;
    let v2=await promise2;
    return v1+v2;
};

/**
 * addTwoPromises(Promise.resolve(2), Promise.resolve(2))
 *   .then(console.log); // 4
 */

// Another way
var addTwoPromises = async function(promise1, promise2) {
    let [v1,v2]= await Promise.all([promise1,promise2]);
    return v1+v2;
};

