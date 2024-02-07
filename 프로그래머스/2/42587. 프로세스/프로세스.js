function solution(priorities, location) {
    var answer = 0; 
    priorities = priorities.map((num, index) => {
        return {
            value : num,
            flag : location === index
        }
    })
    while (priorities.length > 0) {
        const target = priorities[0]
        priorities.shift()
        let flag = false
        for (let i=0; i<priorities.length; i++) {
            if (target.value < priorities[i].value) {
                priorities.push(target)
                flag = true
                break
            }
        }
        if (flag) continue
        answer++
        if (target.flag) break
    }
    return answer;
}