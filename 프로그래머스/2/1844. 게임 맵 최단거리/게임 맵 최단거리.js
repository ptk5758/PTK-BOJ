function solution(maps) {
    maps = maps.map((line, y) => line.map((state,x) => {
        return {
            state : state,
            isVisited : false,
            depth : -1,
            x : x,
            y : y
        }
    }))
    bfs(maps, {x:0, y:0})
    return maps[maps.length-1][maps[0].length-1].depth
}
const dx = [0, 0, -1, 1]
const dy = [1, -1, 0, 0]
function bfs(maps, start) {
    const queue = []
    queue.push(maps[start.y][start.x])
    maps[start.y][start.x].depth = 1
    while (queue.length > 0) {
        const target = queue[0]
        queue.shift()
        if (!target.isVisited) {
            target.isVisited = true
            for (let i=0; i<4; i++) {
                const nx = dx[i] + target.x
                const ny = dy[i] + target.y
                if (nx < 0 || ny < 0) continue
                if (ny >= maps.length) continue
                if (nx >= maps[ny].length) continue
                const next = maps[ny][nx]
                if (next.state === 1 && !next.isVisited) {
                    next.depth = target.depth + 1
                    queue.push(next)
                }
            }
        }
    }
}