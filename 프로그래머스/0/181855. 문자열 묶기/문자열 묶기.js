function solution(strArr) {
    const obj = {}
    strArr.forEach(str => {
        if (str.length in obj) {
            obj[str.length].push(str)
        } else {
            obj[str.length] = [str]
        }
    })
    let answer = 0
    Object.keys(obj).forEach((key) => {
        if (answer < obj[key].length) {
            answer = obj[key].length
        }
    })
    return answer
    
}