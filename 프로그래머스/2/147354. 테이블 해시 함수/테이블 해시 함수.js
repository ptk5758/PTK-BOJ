function solution(data, col, row_begin, row_end) {
    data.sort((a,b) => {
        const c = col - 1;
        if (a[c] != b[c]) {
            return a[c] - b[c]
        } else {
            return b[0] - a[0]
        }
    })
    const values = []
    for (let i = row_begin - 1; i <= row_end - 1; i++) {
        let sum = 0
        const target = [...data[i]]
        target.forEach(value => {
            sum += value % (i + 1)
        })
        values.push(sum)
        
    }
    return values.reduce((prev, current) => {
        return prev ^ current
    })
}