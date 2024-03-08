function solution(a, b) {
     const pa = parseInt(a.toString() + b)
     const pb = parseInt(b.toString() + a)
     return pa > pb ? pa : pb
}