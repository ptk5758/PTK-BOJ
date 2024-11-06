function solution(my_string, indices) {
    const arr = my_string.split("")
    
    indices.forEach(i => {
        arr[i] = " "
    }, "")
    
    return arr.reduce((p,c) => c !== " " ? p + c : p).trim()
}