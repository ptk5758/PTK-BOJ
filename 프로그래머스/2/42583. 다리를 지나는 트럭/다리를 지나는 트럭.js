function solution(bridge_length, weight, truck_weights) {
    let time = 0
    const stack = []
    while (truck_weights.length > 0 || stack.length > 0) {
        time++
        
        if (stack.reduce((p,c)=>p+c.weight,0) + truck_weights[0] <= weight) {
            stack.push({weight : truck_weights[0], time : bridge_length})
            truck_weights.shift()
        }
        
        for (let i=0; i<stack.length; i++) {
            stack[i].time--
        }

        while (stack.length > 0 && stack[0].time === 0) {
            stack.shift()
        }
        
    }
    return time + 1
    
    
    
}