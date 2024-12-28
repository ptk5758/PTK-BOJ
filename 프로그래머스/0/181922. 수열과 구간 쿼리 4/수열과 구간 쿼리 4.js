function solution(arr, queries) {
    const result = [...arr]
    queries.forEach(([s,e,k]) => {
        for (let i=s; i<=e; i++) {
            if (i % k === 0) result[i]++            
        }
    })
    return result
}