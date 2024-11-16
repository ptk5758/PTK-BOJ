function solution(my_string, queries) {
    const arr = my_string.split("")
    queries.forEach(([l, r]) => {
        for (let i=l, j=r; i<j; i++, j--) {
            const temp = arr[i]
            arr[i] = arr[j]
            arr[j] = temp
        }
    })
    return arr.join("")
}