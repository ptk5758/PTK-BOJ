function solution(number, k) {
    const arr = []
    
    for (let i=0; i<number.length; i++) {
        arr.push(number[i])
        while (k > 0 && arr.length > 1 && arr[arr.length - 1] > arr[arr.length - 2]) {
            arr[arr.length - 2] = arr[arr.length - 1]
            arr.pop()
            k--
        }
    }
    while (k--) {
        arr.pop()
    }
    return arr.reduce((prev, current) => prev + current)
    
}