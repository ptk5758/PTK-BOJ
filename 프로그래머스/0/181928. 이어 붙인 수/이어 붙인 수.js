function solution(num_list) {
    return parseInt([...num_list].reduce((p,c)=>{
        return c % 2 === 0 ? p : p + c
    },"")) + parseInt([...num_list].reduce((p,c)=>{
        return c % 2 === 0 ? p + c : p
    },""))
}