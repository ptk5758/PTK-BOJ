function solution(rsp) {
    return rsp.split("").reduce((p,c)=>{
        if (c === "0") {
            return p += "5"
        } else if (c === "2") {
            return p += "0"
        } else {
            return p += "2"
        }
    }, "")
}