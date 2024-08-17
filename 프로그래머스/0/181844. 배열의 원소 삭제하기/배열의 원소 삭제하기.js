function solution(arr, delete_list) {
    return arr.filter(num => !delete_list.find(n => n === num))
}