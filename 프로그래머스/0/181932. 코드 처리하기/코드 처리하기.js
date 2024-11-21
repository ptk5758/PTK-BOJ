function solution(code) {
    let mode = 0
    const result = []
    for (let i=0; i<code.length; i++) {
        if (mode) {
            if (code[i] === "1") {
                mode = 0
            } else {
                if (i % 2 === 1) {
                    result.push(code[i])
                }
            }
        } else {
            if (code[i] === "1") {
                mode = 1
            } else {
                if (i % 2 === 0) {
                    result.push(code[i])
                }
            }
        }
    }
    return result.length > 0 ? result.join("") : "EMPTY"
}