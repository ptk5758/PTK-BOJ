function solution(num_list) {
    num_list.sort((a, b) => a - b)
    return num_list.splice(0, 5)
}