function solution(slice, n) {
    const t = Math.floor(n / slice)
    return n % slice !== 0 ? t + 1 : t
}