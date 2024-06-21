function solution(my_string) {
    var answer = 0;
    for (let i=0; i<my_string.length; i++) {
        if (my_string[i] >= '0' && my_string[i] <= '9')
            answer += my_string[i] - '0'
    }
    return answer;
}