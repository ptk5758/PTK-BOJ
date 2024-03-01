function solution(keymap, targets) {
    const keys = {}
    keymap.forEach(str => {
        str.split("").forEach((c, index) => {
            if (c in keys) {
                if (keys[c] > index + 1)
                    keys[c] = index + 1
            } else {
                keys[c] = index + 1
            }
        })
    })
    return targets.reduce((prev, current) => {
        let value = 0
        for (let i=0; i<current.length; i++) {
            if (current[i] in keys) {
                value += keys[current[i]]
            } else {
                return [...prev, -1]
            }
        }
        return [...prev, value]
    },[])
}