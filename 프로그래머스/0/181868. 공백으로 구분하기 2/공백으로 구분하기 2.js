function solution(my_string) {
    var answer = [];
    my_string.split(" ").forEach((word) => {
        if (word !== "") answer.push(word)
    })
    return answer;
}