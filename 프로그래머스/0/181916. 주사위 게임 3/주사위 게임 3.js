function solution(a, b, c, d) {
    var answer = 0;    
    const arr = [a,b,c,d]
    const obj = {}
    arr.forEach((x) => {
        if (x in obj) obj[x]++
        else obj[x] = 1
    })
    const keys = Object.keys(obj)
    keys.sort((a,b) => {
        return obj[a] - obj[b]
    })
    switch (keys.length) {
        case 4 :
            answer = parseInt(keys[0])
            break
        case 3:
            let temp = 1
            temp *= keys[0]
            temp *= keys[1]
            answer = temp
            break
        case 2:
            if (obj[keys[0]] === 2) {
                let a = parseInt(keys[0])
                let b = parseInt(keys[1])
                let sub = a - b < 0 ? b - a : a - b
                answer = (a + b) * sub
            } else {
                let q = parseInt(keys[0])
                let p = parseInt(keys[1])
                answer = (10 * p + q) * (10 * p + q)
            }
            break
        case 1:
            let p = parseInt(keys[0])
            answer = p * 1111
    }
    return answer
   
}