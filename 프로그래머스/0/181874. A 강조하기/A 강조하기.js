function solution(myString) {
    return myString.split("").reduce((p, c) => {
        if (c === "a" || c === "A") {
            c = c.toUpperCase()
        } else {
            c = c.toLowerCase()
        }
        return p + c
    }, "")
}