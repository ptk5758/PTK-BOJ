function solution(arr, n) {
    return arr.map((num, index) => {
        if (arr.length % 2 === 0) {
            if (index % 2 === 1) {
                return num + n
            } else {
                return num
            }
        } else {
            if (index % 2 === 0) {
                return num + n
            } else {
                return num
            }
        }
    })
}