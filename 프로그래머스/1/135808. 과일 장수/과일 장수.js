function solution(k, m, score) {
    var answer = 0
    score.sort(function(a,b){ return a - b })
    let boxCount = Math.floor(score.length / m)
    while (boxCount--) {
        let min = 11
        for (let i=0; i<m; i++) {
            let target = score.pop()
            if (min > target) min = target
        }
        answer += min * m        
    }
    return answer
}