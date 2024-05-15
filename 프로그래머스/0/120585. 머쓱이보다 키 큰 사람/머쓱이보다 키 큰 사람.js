function solution(array, height) {
    let answer = 0
    array.forEach(n => {
        if (n > height) answer++
    })
    return answer
}