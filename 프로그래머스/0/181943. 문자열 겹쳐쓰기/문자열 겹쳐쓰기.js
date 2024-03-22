function solution(m, o, s) {
    let str = m.substring(0, s)
    str += o
    str += m.substring(str.length) 
    return str
}