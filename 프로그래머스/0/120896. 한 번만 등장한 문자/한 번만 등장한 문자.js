function solution(s) {
    const temp = {}
    s.split("").forEach((spel) => {
        if (spel in temp) {
            temp[spel]++
        } else {
            temp[spel] = 0
        }
    })
    return  Object.keys(temp).reduce((prev, current) => {
        if (temp[current] === 0) return prev + current
        else return prev        
    },'').split("").sort().join("")    
}