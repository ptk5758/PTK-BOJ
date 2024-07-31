function solution(arr) {
    return arr.map(num => {
        if (num >= 50 && num % 2 == 0) {
            return Math.floor(num / 2 )
        } else if (num < 50 && num % 2 == 1) {
            return num * 2
        } else {
            return num
        }
    })
}