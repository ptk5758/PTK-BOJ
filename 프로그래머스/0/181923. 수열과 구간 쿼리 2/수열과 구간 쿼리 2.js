function solution(arr, queries) {
    const result = []
    queries.forEach(([s, e, k]) => {
        let value = -1;
        for (let i=s; i<=e; i++) {
            if (arr[i] > k) {
                if (value === -1) {
                    value = arr[i]
                } else if (value > arr[i]) {
                    value = arr[i]
                }
            }
        }
        result.push(value)
    })
    return result
}

