function solution(n) {
    const arr = []
    arr[0] = false
    arr[1] = false
    for (let i=2; i<=n; i++) {
        arr[i] = true
    }
    for (let i=2; i<=n; i++) {
        if (arr[i]) {
            for (let j = i * i; j <=n; j += i) {
                arr[j] = false
            }
        }
    }
    return arr.filter(item => item).length
}