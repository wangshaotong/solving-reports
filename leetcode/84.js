/**
 * @param {number[]} heights
 * @return {number}
 */
var largestRectangleArea = function(heights) {
  let maxArea = 0, length = heights.length, array = heights.concat().sort()
  for (let i = 0; i < length; i++) {
    let cnt = 0, maxCnt = 0
    for (let j = 0; j < length; j++) {
      if (heights[j] >= array[i]) {
        cnt++      
      } else {
        maxCnt = cnt > maxCnt ? cnt : maxCnt
        cnt = 0
      }
    }
    maxCnt = cnt > maxCnt ? cnt : maxCnt
    maxArea = maxCnt * array[i] > maxArea ? maxCnt * array[i] : maxArea
  }
  return maxArea
};

console.log(largestRectangleArea([2, 0, 2]))