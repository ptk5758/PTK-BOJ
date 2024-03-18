function solution(arr) {
    arr.push(arr[arr.length - 1] > arr[arr.length - 2] ? arr[arr.length - 1] - arr[arr.length - 2] : arr[arr.length - 1] * 2)
    return arr
}