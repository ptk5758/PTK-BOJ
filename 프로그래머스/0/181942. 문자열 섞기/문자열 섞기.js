function solution(str1, str2) {
    let str = ""
    str1.split("").forEach((c, index) => {
        str += c
        str += str2[index]
    })
    return str;
}