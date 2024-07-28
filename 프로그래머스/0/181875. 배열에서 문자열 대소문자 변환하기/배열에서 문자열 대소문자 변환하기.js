function solution(strArr) {
    return strArr.map((str, index) => {
        return str.split("").reduce((p,c) => {
            if (index % 2 == 0) {
                c = c.toLowerCase()
            } else {
                c = c.toUpperCase()                
            }
            return p + c
        }, "")
    })
}