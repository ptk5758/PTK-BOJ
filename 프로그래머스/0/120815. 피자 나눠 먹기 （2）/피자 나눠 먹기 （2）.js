function solution(n) {
    let cnt = 1;
    while ((cnt * 6) % n !== 0) {
        cnt++
    }
    return cnt
}