function solution(n, m, section) {
    var answer = 0
    let i = 0    
    let count = 0
    while (i++ < n) {
        if (count) count--
        if (i === section[0]) {
            if (!count) {
                answer++
                count = m
            }
            section.shift()
        }
    }
    return answer
}