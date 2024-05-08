function solution(my_str, n) {
    const result = []
    let temp = ""
    my_str.split("").forEach((c, index) => {
        temp += c;
        if ((index + 1) % n === 0) {
            result.push(temp)
            temp = ""
        }
    })
    if (temp != "") result.push(temp)
    return result
}