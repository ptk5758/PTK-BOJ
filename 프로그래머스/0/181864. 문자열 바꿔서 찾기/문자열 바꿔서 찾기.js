function solution(myString, pat) {
    const a = pat.split("").reduce((p,c)=> p + (c === "A" ? "B" : "A"),"")
    return myString.includes(a) ? 1 : 0
}