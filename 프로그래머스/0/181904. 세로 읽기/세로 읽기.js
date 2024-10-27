function solution(my_string, m, c) {
    const lines = []
    let index = 0
    while (index + m <= my_string.length) {
        lines.push(my_string.substring(index, index + m))
        index = index + m
    }
    let result = ""
    lines.forEach(str => {
        // result += str.split("")[c]
        if (str.length > 1) {
            result += str.split("")[c-1]
        } else {
            result += str
        }
    })
    return result
}