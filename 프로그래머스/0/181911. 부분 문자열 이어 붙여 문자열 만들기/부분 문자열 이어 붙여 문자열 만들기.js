function solution(my_strings, parts) {
    let result = ""
    for (let i=0; i<parts.length; i++) {
        const part = parts[i]
        for (let j=part[0]; j<=part[1]; j++) {
            result += my_strings[i][j]
        }
    }
    return result
}