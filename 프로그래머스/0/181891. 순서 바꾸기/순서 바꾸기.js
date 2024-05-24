function solution(num_list, n) {
    const temp = num_list.splice(n, num_list.length - n)
    num_list = [...temp, ...num_list]
    return num_list    
}
