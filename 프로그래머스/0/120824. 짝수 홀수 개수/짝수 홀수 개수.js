function solution(num_list) {
    let a=0,b=0
    num_list.forEach(value => {
        if (value % 2 === 0) a++
        else b++
    })
    return [a,b]
}