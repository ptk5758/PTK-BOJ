function solution(my_string, is_suffix) {
    let j = 0;
    for (let i=my_string.length - is_suffix.length; i<my_string.length; i++, j++) {
        if (my_string[i] !== is_suffix[j]) return 0
    }
    return 1
}