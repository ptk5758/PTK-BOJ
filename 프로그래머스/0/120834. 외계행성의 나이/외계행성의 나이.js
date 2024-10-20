function solution(age) {
    const spling = 'abcdefghijklmnopqrstuvwxyz'
    return age.toString().split("").reduce((p, c)=> p + spling[+c], "")
}