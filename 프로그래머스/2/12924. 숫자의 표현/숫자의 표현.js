function solution(n) {
    let cnt = 0
    let sum = 0
    let s = 1
    for (let i=1; i<=n; i++) {
        sum += i
        while (sum > n) {
            sum -= s++;
        }
        if (sum === n) {
            cnt++
        }
    }
    return cnt
}