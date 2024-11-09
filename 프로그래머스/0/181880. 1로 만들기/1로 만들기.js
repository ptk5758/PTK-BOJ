function solution(num_list) {
    let result = 0
    num_list.forEach(num => {
        while (num !== 1) {
            if (num % 2 === 0) {
                num = Math.floor(num / 2)
            } else {
                num = Math.floor((num - 1) / 2)
            }
            result++
        }
    })
    return result
}