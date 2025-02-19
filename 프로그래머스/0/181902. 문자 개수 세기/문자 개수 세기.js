function solution(my_string) {
    let counts = new Array(52).fill(0);
    
    for (let char of my_string) {
        let code = char.charCodeAt(0);
        if (code >= 65 && code <= 90) {
            // 대문자 'A' ~ 'Z' (ASCII 65 ~ 90)
            counts[code - 65]++;
        } else if (code >= 97 && code <= 122) {
            // 소문자 'a' ~ 'z' (ASCII 97 ~ 122)
            counts[code - 97 + 26]++;
        }
    }
    
    return counts;
}
