function solution(a,b,c) {
    let result = 0
    for (let i=a; i<=b; i++) {
        const arr = i.toString().split("")
        arr.forEach(s => {
            if (s === c.toString()) result++
        })
    }
    return result
}