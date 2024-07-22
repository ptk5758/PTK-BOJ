function solution(arr) {
    var answer = [];
    arr.forEach(v => {
        for (let i=0; i<v; i++) answer.push(v)
    })
    return answer;
}