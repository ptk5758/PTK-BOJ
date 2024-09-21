function solution(order) {
    const arr = order.toString().split("").map(e => +e).filter(e => e === 3 || e === 6 || e === 9)
    return arr.length
}