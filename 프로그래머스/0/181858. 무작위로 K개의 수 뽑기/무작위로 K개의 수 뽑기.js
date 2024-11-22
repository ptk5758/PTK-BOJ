function solution(arr, k) {
    const list = Array.from(new Set(arr))
    while (list.length !== k) {
        if (list.length > k) {
            list.pop()
        } else {
            list.push(-1)
        }
    }
    return list
}