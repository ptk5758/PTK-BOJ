function solution(a, b, c) {
    const x = a + b + c
    const y = a*a + b*b + c*c
    const z = a*a*a + b*b*b + c*c*c
    let result = x
    if (a === b || a === c || b === c) {
        result *= y
    }
    if (a === b && b === c) {
        result *= z
    }
    return result
}