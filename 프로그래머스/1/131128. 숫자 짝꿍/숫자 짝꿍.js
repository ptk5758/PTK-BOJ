function solution(X, Y) {
    const obj = {}
    const list = []
    for (let i=9; i>=0; i--) obj[i] = 0
    X.split("").forEach(s => obj[s]++)
    Y.split("").forEach(s => {
        if (obj[s]) {
            obj[s]--
            list.push(s)
        }
    })
    list.sort((a,b) => b-a)
    if (list.length == 0) {
        return "-1"
    } else if (list[0] == "0") {
        return "0"
    } else {
        return list.reduce((prev, current) => {
            return prev + current
        })
    }
        
}