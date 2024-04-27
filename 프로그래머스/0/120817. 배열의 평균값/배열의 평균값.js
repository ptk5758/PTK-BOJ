function solution(numbers) {
    
    let total = 0    
    numbers.forEach(value => {
        total += value;
    })
    return total / numbers.length
}