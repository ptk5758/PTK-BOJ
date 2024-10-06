function solution(arr, intervals) {
    const result = []
    intervals.forEach(([l, r]) => {
        for (let i = l; i<=r; i++) {
            result.push(arr[i])
        }
    })
    return result
}