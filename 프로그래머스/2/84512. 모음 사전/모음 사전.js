let speling = ['A', 'E', 'I', 'O', 'U']
function solution(word) {
    function check(arr) {        
        return word === arr.reduce((prev, current) => prev += speling[current], '')
    }
    var answer = 0
    let arr = []
    while (true) {
        if (check(arr)) break
        answer++
        if (arr.length < 5) {
            arr.push(0)
        } else {
            arr[arr.length - 1]++
            while (arr[arr.length - 1] === 5) {                                
                arr.pop()
                arr[arr.length - 1]++
            }
        }
    }
    return answer;
}
