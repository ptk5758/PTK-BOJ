function solution(numbers) {
    const arr = ["zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" ]
    let result = ""
    while (numbers.length > 0) {
        arr.forEach((word, index) => {
            if (numbers.substring(0, word.length) === word) {
                numbers = numbers.substring(word.length)
                result += index
            }
        })
    }
    return +result
    
}