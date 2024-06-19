function solution(my_string, n) {
    var answer = '';
    my_string.split("").forEach(c => {
        for (let i=0; i<n; i++) answer += c
    })
    return answer;
}