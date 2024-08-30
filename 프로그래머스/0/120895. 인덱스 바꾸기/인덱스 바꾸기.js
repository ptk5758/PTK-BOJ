function solution(my_string, num1, num2) {
    const temp = my_string.split("")
    const t = temp[num1]
    temp[num1] = temp[num2]
    temp[num2] = t
    return temp.reduce((p,c) => p + c ,"")
}