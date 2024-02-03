function solution(s) {
    var answer = [0,0];
    while (s !== "1") {
        answer[0]++
        const length = s.split("").filter(num => {
            if (num === "0") answer[1]++
            return num === "1"
        }).length
        
        const arr = []
        let num = length
        while (num / 2 > 0) {
            arr.push(num % 2)
            num = parseInt(num / 2)
        }
        s = arr.reverse().join("")
    }
    
    
    
    return answer;
}