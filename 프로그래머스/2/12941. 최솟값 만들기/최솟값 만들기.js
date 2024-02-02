function solution(A,B){
    var answer = 0;
    A.sort((a,b) => {
        return b - a
    })
    B.sort((a,b) => {
        return a - b
    })
    for (let i=0; i<A.length; i++) {
        answer += A[i] * B[i]
    }
    
    
    return answer;
}