function solution(hp) {
    let cnt = Math.floor(hp / 5)
    hp %= 5
    cnt += Math.floor(hp / 3)
    hp %= 3
    return cnt + hp
    
}