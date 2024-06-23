function solution(my_string) {
    var answer = '';
    for (let i=0; i<my_string.length; i++) {
        if (my_string[i] >= 'a' && my_string[i] <= 'z') {
            answer += my_string[i].toUpperCase()
        } else {
            answer += my_string[i].toLowerCase()
        }
    }
    return answer;
}