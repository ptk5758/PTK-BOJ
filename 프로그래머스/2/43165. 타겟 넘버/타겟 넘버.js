function solution(numbers, target) {
    let answer = 0;
    let tree = [0]
    while (numbers.length > 0) {
        const value = numbers[0]
        numbers.shift()
        const temp = []
        tree.forEach(num => {
            temp.push(num + value)
            temp.push(num + value * -1)
        })
        tree = temp
    }
    tree.forEach(num => {
        if (target === num) answer++
    })
    return answer;
}