function solution(num_list) {
    const sum = num_list.reduce((p,c)=>p+c)
    const x = num_list.reduce((p,c)=>p*c)
    return Math.pow(sum, 2) > x ? 1 : 0
}