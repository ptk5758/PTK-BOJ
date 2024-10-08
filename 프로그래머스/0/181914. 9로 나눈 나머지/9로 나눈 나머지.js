function solution(number) {
    return number.split("").reduce((p,c) => p + +c, 0) % 9
}