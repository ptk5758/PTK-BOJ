function solution(n_str) {
    let index = 0
    while (n_str[index] === "0") index++
    let result = ""
    for (let i=index; i<n_str.length; i++) {
        result += n_str[i]
    }
    return result
}