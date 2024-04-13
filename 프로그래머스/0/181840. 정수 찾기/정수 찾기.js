function solution(num_list, n) {
    const num = num_list.find(value => value === n)
    return num ? 1 : 0
}