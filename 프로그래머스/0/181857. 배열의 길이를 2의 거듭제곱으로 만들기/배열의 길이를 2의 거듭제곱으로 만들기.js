function solution(arr) {
    if (arr.length == 1) return arr
    let x = 2
    while (x < arr.length) {
        x *= 2
    }
    while (arr.length < x) {
        arr.push(0)
    }
    return arr
}