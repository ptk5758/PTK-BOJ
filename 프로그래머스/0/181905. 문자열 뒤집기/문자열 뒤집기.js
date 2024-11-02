function solution(my_string, s, e) {
    const arr = my_string.split("")
    for (let i=s, j=e; i<=j; i++,j--) {
        const temp = arr[i]
        arr[i] = arr[j]
        arr[j] = temp
    } 
    return arr.join("")
}