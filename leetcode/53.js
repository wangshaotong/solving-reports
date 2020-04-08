/**
 * @param {number[]} nums
 * @return {number}
 */
var missingNumber = function(nums) {
  for (let i = 0; i < nums.length; i++) {
    if (i !== nums[i]) {
      return i
    }
  }
  return ++nums[nums.length - 1]
};

console.log(missingNumber([0]))