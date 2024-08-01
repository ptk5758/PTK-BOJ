function solution(numbers, n) {
    return numbers.reduce((p,c)=>{
        if (p > n) return p
        else return p + c
    }, 0)
}