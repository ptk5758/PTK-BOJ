function solution(my_string) {
    const set = new Set(my_string.split(""))
    let result = ""
    set.forEach(speling => result += speling)
    return result
}