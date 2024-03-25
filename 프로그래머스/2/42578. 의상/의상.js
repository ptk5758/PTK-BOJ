function solution(clothes) {
    const obj = clothes.reduce((prev, current) => {
        const temp = {...prev}
        if (current[1] in temp) {
            temp[current[1]]++
        } else {
            temp[current[1]] = 1
        }
        return temp
    }, {})
    let answer = 1
    const keys = Object.keys(obj)
    if (keys.length === 1) return obj[keys[0]]
    keys.forEach(key => {
        answer *= obj[key] + 1
    })
    return answer - 1 
}