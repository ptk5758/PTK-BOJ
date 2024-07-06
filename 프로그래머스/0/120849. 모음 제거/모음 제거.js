function solution(s) {
    let answer = ""    
    for (let i=0; i<s.length; i++) {
        if (s[i] == 'a') continue;
        if (s[i] == 'e') continue;
        if (s[i] == 'i') continue;
        if (s[i] == 'o') continue;
        if (s[i] == 'u') continue;
        answer += s[i]
        
    }
    return answer
}