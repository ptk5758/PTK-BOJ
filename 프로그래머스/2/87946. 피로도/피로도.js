let max = -1
function adventure(k, cnt, target) {
    if (cnt > max) max = cnt
    for (let i=0; i<target.length; i++) {
        const arr = [...target]
        const dungeon = arr[i]
        arr.splice(i, 1)
        if (k < dungeon[0]) continue
        adventure(k - dungeon[1], cnt + 1, arr)
    }
}
function solution(k, dungeons) {
    adventure(k, 0, dungeons)
    return max
}

