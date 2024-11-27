function solution(my_string) {
    let result = 0
    const reg = /[a-zA-Z]/
    const arr = my_string.split(reg)
    arr.forEach(s => {
        if (!isNaN(s)) result += +s
    })
    return result
}