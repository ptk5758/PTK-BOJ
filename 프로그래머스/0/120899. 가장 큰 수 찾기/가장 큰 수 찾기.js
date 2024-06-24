function solution(array) {
    
    let maxValue = -1
    let maxIndex = -1
    for (let i=0; i<array.length; i++) {
        if (maxValue < array[i]) {
            maxValue = array[i]
            maxIndex = i
        }
    }
    return [maxValue, maxIndex]
}