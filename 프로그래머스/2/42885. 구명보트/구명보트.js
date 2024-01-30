function solution(people, limit) {
    var answer = 0
    people.sort(function(a,b){return b-a})
    let start = 0
    let end = people.length - 1
    while (start <= end) {
        if (people[start] + people[end] <= limit) {
            start++
            end--
            answer++
        } else {
            answer++
            start++
        }
    }
    return answer    
}