function solution(numLog) {
    let result = ""
    for (let i=0; i+1<numLog.length; i++) {
        const value = numLog[i]
        if (value + 1 === numLog[i + 1]) {
            result += 'w'
        } else if (value - 1 === numLog[i + 1]) {
            result += 's'
        } else if (value + 10 === numLog[i + 1]) {
            result += 'd'
        } else if (value - 10 === numLog[i + 1]) { 
            result += 'a'
        }
        
    }
    return result
}