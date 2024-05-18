function solution(n) {
    var answer = 0;
    answer = Math.floor(n / 7)
    answer += n % 7 > 0 ? 1 : 0
    return answer;
}