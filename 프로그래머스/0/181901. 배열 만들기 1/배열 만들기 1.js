function solution(n, k) {
    const arr = []
    for (let i = k; i <= n; i+=k) {
        arr.push(i)
    }
    return arr
}