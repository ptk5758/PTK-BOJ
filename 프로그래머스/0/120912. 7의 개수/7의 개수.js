function solution(array) {
    var answer = 0;
    array.forEach(num => {
        const arr = num.toString().split("")
        arr.forEach(w => {
            if (w === '7') answer++
        })
    })
    return answer;
}