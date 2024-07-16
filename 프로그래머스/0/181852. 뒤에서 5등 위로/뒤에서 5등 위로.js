function solution(nums) {
    nums.sort((a,b) => a - b)
    for (let i=0; i<5; i++) {
        nums.shift()
    }
    return nums
}