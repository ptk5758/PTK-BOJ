function solution(n) {
    var answer = [];
    for (let i=0; i<n; i++) {
        const line = []
        for (let j=0; j<n; j++) {
            if (i === j) {
                line.push(1)
            } else {
                line.push(0)
            }
        }
        answer.push(line)
    }
    return answer;
}