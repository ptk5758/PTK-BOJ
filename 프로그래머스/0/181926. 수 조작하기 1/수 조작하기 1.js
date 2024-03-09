function solution(n, control) {
    control.split("").forEach(c => {
        switch (c) {
            case 'w':
                n++
                break
            case 's' :
                n--
                break
            case 'd' :
                n += 10
                break
            case 'a' :
                n -= 10
                break
        }
    })
    return n
}