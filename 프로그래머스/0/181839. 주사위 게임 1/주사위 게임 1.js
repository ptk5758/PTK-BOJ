function solution(a, b) {
    const isEven = (num) => num % 2 === 0
    const isEvenA = isEven(a)
    const isEvenB = isEven(b)
    if (isEvenA === isEvenB) {
        if (isEvenA) {
            return a > b ? a - b : b - a
        } else {
            return a * a + b * b
        }
    } else {
        return 2 * (a + b)
    }
}