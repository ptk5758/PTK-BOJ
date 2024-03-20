function solution(a, b) {
    const ca = parseInt(a.toString() + b)
    const cb = 2 * a * b
    return ca >= cb ? ca : cb
}