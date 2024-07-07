function solution(n) {
    return n.toString().split("").reduce((p,c) => p + +c, 0)
}