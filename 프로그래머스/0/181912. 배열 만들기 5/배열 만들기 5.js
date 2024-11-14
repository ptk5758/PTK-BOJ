function solution(intStrs, k, s, l) {
    const result = []
    intStrs.forEach(str => {
        const value = +str.split("").splice(s, l).join("")
        if (value > k) result.push(value)
    })
    return result
}