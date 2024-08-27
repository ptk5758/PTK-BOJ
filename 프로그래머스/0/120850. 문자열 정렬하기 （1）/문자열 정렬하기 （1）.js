function solution(my_string) {
    const result = []
    my_string.split("").forEach((c) => {
        if (/[0-9]/.test(c)) {
            result.push(+c)
        }
    })
    result.sort()
    return result
}