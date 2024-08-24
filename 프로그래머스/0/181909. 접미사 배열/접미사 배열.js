function stringConcat(arr) {
    return arr.reduce((p,c) => p+c, "")
}
function solution(my_string) {
    const result = []
    const arr = my_string.split("")
    while (arr.length > 0) {
        result.push(stringConcat(arr))
        arr.shift()
    }
    result.sort()
    return result
}