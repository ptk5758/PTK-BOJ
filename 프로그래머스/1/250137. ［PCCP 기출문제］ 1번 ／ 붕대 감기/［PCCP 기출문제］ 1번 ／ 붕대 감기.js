function solution(bandage, health, attacks) {
    const MAX_HP = health
    let secound = 1
    let count = 0
    while (attacks.length > 0) {
        const attack = attacks[0]
        if (attack[0] === secound) {
            health -= attack[1]
            if (health <= 0) return -1
            attacks.shift()
            count = 0
            
        } else {
            health += bandage[1]
            count++
            if (bandage[0] === count) {
                health += bandage[2]
                count = 0
            }
            if (health > MAX_HP) health = MAX_HP
        }
        secound++
    }
    return health
}