function solution(n) {
    const arr = [BigInt(0), BigInt(1)]
    for (let i=2; i<=n; i++) {
        arr.push(arr[i - 1] + arr[i - 2])
    }
    return arr[n] % 1234567n
}
