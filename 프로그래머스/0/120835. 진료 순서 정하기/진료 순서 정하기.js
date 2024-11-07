function solution(arr) {
    const result = []
    for (let i=0; i<arr.length; i++) {
        let index = 1
        for (let j=0; j<arr.length; j++) {
            if (arr[i] < arr[j]) {
                index++
            }
        }
        result.push(index)
    }
    return result
}