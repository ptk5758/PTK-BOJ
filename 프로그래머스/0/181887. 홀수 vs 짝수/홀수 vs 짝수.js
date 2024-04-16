function solution(num_list) {
    let a = 0
    let b = 0
    num_list.forEach((num, index) => {
        if (index % 2 === 0) a += num
        else b += num
    })
    return a > b ? a : b
}