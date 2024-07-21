function solution(arr1, arr2) {
    if (arr1.length !== arr2.length) {
        let x = arr1.length
        let y = arr2.length
        if (x > y) {
            return 1
        } else if (x < y) {
            return -1
        } else {
            return 0
        }
    } else {
        let x = arr1.reduce((p,c) => p + c)
        let y = arr2.reduce((p,c) => p + c)
        if (x > y) {
            return 1
        } else if (x < y) {
            return -1
        } else {
            return 0
        }
    }
}