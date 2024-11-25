function solution(arr) {
    var stk = [];
    let i = 0
    while (i < arr.length) {
        if (stk.length === 0) {
            stk.push(arr[i])
            i++
        } else {
            const last = stk[stk.length - 1]
            if (last < arr[i]) {
                stk.push(arr[i])
                i++
            } else {
                stk.pop()
            }
        }
    }
    return stk;
}