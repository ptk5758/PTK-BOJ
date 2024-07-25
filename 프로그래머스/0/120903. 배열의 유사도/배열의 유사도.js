function solution(s1, s2) {
    var answer = 0;
    s1.forEach(w => {
        s2.forEach(x => {
            if (x === w) answer++
        })
    })
    return answer;
}