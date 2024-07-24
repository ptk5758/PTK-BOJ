function solution(my_string, alp) {
    return my_string.split("").reduce((p,c) => {
        if (c === alp) {
            c = c.toUpperCase()
        } 
        return p + c
    }, "")
}