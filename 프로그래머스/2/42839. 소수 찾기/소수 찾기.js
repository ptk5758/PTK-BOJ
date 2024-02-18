function solution(numbers) {
    let answer = 0
    const nums = numbers.split("")
    const set = new Set()
    func(set, "", nums)
    set.forEach(value => {
        if (isPrime(value)) answer++
    })
    return answer
}
function isPrime(num) {
    if (num <= 1) return false
    if (num === 2) return true
    for (let i=2; i<=Math.sqrt(num); i++) {
        if (num % i === 0) return false
    }
    return true
}
function func(set, str, nums) {
    if (nums.length == 0) return
    for (let i=0; i<nums.length; i++) {
        const temp = str + nums[i]
        if (temp !== "") set.add(parseInt(temp))
        const arr = [...nums]
        arr.splice(i,1)
        func(set, temp, arr)
    }
}
