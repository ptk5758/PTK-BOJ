function solution(arr) {
    let result = true
    for (let i=0; i<arr.length; i++) {
        if (!result) 
            break
        const length = arr[0].length
        for (let j=0; j<length; j++) {
            if (arr[i][j] != arr[j][i]) {
                result = false
                break
            }
        }
    }
    return result ? 1 : 0
}