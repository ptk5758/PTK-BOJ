function solution(array, n) {
    return array.reduce((prev, current) => current === n ? prev + 1 : prev, 0)
}