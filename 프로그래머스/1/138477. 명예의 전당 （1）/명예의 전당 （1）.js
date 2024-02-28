function solution(k, score) {
    const result = []
    const gallery = []
    score.forEach(s => {
        gallery.push(s)
        gallery.sort((a,b) => b - a)
        if (gallery.length > k) 
            gallery.pop()
        result.push(gallery[gallery.length - 1])
    })
    return result
}