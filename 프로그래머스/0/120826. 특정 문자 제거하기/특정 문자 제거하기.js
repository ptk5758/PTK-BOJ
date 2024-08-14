function solution(my_string, letter) {
    return my_string.split("").reduce((p,c) => c !== letter ? p+c : p, "")
}