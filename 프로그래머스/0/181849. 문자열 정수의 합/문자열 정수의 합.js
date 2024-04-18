function solution(num_str) {
    return num_str.split("").reduce((p,c)=>p+parseInt(c),0)
}