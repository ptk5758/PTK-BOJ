const location = { x : 0, y : 0 }
function solution(maps) {
    const arr = []
    let y = 0;    
    maps.forEach((element) => {
        arr.push([])
        let x = 0
        element.split("").forEach((speling) => {
            arr[arr.length-1].push({value : speling, flag : false, x : x, y : y, depth : 0})
            if (speling === 'S') {
                location.x = x
                location.y = y
            }
            x++
        })
        y++
    })    
    const a = bfs(arr, location, "L")
    if (!a) return -1    
    arr.forEach(ele => ele.forEach(_ele => {
        _ele.flag = false
        _ele.depth = 0
    }))
    const b = bfs(arr, location, "E")
    if (!b) return -1    
    return a+b;
}
// 상 하 좌 우 
const dx = [0, 0, -1, 1]
const dy = [-1, 1, 0, 0]
function bfs(arr, start, word) {
    const queue = []
    queue.push(arr[start.y][start.x])    
    while (queue.length > 0) {
        const target = queue[0]
        queue.shift()
        if (target.flag) continue
        target.flag = true
        if (target.value === word) {
            location.x = target.x
            location.y = target.y
            return target.depth
        }
        for (let i=0; i<4; i++) {
            let nx = target.x + dx[i]
            let ny = target.y + dy[i]
            if (nx < 0 || ny < 0) continue
            if (ny >= arr.length) continue
            if (nx >= arr[ny].length) continue
            if (arr[ny][nx].value !== "X") {
                arr[ny][nx].depth = target.depth + 1
                queue.push(arr[ny][nx])
            }
        }
    }    
}