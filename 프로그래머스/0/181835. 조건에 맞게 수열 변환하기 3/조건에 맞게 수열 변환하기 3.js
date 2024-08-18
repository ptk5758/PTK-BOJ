function solution(arr, k) {
    if (k % 2 === 0) {
        return arr.map(ele => ele + k)
    } else {
        return arr.map(ele => ele * k)
    }
}