/**
 * @param {number[]} A
 * @param {number[][]} queries
 * @return {number[]}
 */
var sumEvenAfterQueries = function(A, queries) {
  let sum = 0, results = []
  A.forEach(el => {
    if (el % 2 === 0) {
      sum += el
    }
  })

  queries.forEach(el => {
    A[el[1]] += el[0]
    if (A[el[1]] % 2 === 0) {
      if (el[0] % 2 === 0) {
        sum += el[0]
      } else {
        sum += A[el[1]]
      }
    } else {
      if (el[0] % 2 !== 0) {
        sum -= A[el[1]] - el[0]
      }
    }    
    results.push(sum)
  })
  return results
};

console.log(sumEvenAfterQueries([1, 2, 3, 4], [[1, 0], [-3, 1], [-4, 0], [2, 3]]))