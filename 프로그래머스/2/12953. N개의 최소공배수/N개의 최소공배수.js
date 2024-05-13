function solution(arr) {
    let i = 0
    while (i < arr.length + 1) {
        if (arr[i + 1]  %  arr[i] === 0) {
            arr.splice(i, 1)
        } else {
            i++
        }
    }
    let max = arr[arr.length - 1]
    const value = max
    while (true) {
        let flag = true
        for (let i=0; i<arr.length - 1; i++) {
            if (max % arr[i] !== 0) {
                flag = false
                max = max + value
                break
            }
        }
        if (flag) break
    }
    return max
}