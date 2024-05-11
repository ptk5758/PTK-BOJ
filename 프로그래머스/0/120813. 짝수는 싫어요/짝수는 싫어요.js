function solution(n) {
    const arr = []
    for (let i=1; i<=n; i++) {
        if (i % 2 === 1) arr.push(i)
    }
    return arr
}