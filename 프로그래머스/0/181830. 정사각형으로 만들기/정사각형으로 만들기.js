function solution(arr) {
    const x = arr.length
    const y = arr[0].length
    const edge = x >= y ? x : y
    while (arr.length < edge) {
            arr.push([])
    }
    for (let i=0; i<edge; i++) {
        while (arr[i].length < edge) {
            arr[i].push(0)
        }
    }
    return arr
}