function solution(num_list, n) {
    var answer = [];
    while (num_list.length > 0) {
        const temp = []
        let index = n
        while (index--) {
            temp.push(num_list[0])
            num_list.shift()
        }
        answer.push(temp)
    }
    return answer;
}