function solution(n) {
    let result = 0
    function check(value) {
        for (let i=2; i<value; i++) {
            if (value % i === 0) {
                return true
            }
        }
        return false
    }
    for (let i=1; i<=n; i++) {
        if (check(i)) result++
    }
    return result
    
}