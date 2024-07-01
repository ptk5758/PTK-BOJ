function solution(str_list, ex) {
    var answer = '';
    str_list.forEach(word => {
        if (!word.includes(ex)) answer += word
    })
    return answer;
}