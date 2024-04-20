function solution(wallpaper) {
    let minX = 51
    let minY = 51
    let maxX = -1
    let maxY = -1
    for (let i=0; i<wallpaper.length; i++) {
        const line = wallpaper[i]        
        for (let j=0; j<line.length; j++) {
            if (line[j] === "#") {
                if (minY > i) minY = i
                if (minX > j) minX = j
                if (i > maxY) maxY = i
                if (j > maxX) maxX = j
            }
        }
    }
    return [minY, minX, maxY+1,  maxX+1]
}