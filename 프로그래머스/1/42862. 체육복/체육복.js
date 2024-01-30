function solution(n, lost, reserve) {
    var answer = 0;
    let arr = []
    for (let i=0; i<n; i++) { arr.push(1) }    
    lost.forEach((ele) => arr[ele-1]--)
    reserve.forEach((ele) => arr[ele-1]++)
    for (let i=0; i<arr.length; i++) {
        const target = arr[i]
        if (target > 1) {
            if (i > 0 && arr[i - 1] === 0) {
                arr[i]--
                arr[i - 1]++
            } else if (i < arr.length && arr[i + 1] === 0) {
                arr[i]--
                arr[i + 1]++
            }
        }
    }
    arr.forEach((ele) => {
        if (ele !== 0) answer++
    })
    return answer;
}