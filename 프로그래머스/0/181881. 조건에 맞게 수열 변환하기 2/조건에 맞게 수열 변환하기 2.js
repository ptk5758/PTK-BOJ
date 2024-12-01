function same(a, b) {
    if (a.length !== b.length) return false
    for (let i=0; i<a.length; i++) {
        if (a[i] !== b[i]) {
            return false
        }
    }
    return true
}
function solution(arr) {
    let answer = 0
    while (true) {
        const copy = [...arr]
        for (let i=0; i<arr.length; i++) {
            if (arr[i] >= 50 && arr[i] % 2 === 0) {
                arr[i] = arr[i] / 2
            } else if (arr[i] < 50 && arr[i] % 2 === 1) {
                arr[i] = arr[i] * 2 + 1
            }
        }
        if (same(copy, arr)) {
            return answer
        }
        answer++
    }
}