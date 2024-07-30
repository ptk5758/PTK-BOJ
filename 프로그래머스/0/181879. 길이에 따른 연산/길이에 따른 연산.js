function solution(num_list) {
    if (num_list.length > 10) {
        return num_list.reduce((p,c)=>p+c,0)
    } else {
        return num_list.reduce((p,c)=>p*c,1)
    }
}