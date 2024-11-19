function solution(order) {    
    const obj = {
        "iceamericano" : "americano",
        "americanoice" : "americano",
        "hotamericano" : "americano",
        "americanohot" : "americano",
        "icecafelatte" : "cafelatte",
        "cafelatteice" : "cafelatte",
        "hotcafelatte" : "cafelatte",
        "cafelattehot" : "cafelatte",
        "americano" : "americano",
        "cafelatte" : "cafelatte",
        "anything" : "americano",
    }
    let result = 0
    order.forEach(menu => {        
        if (obj[menu] === "americano") {
            result += 4500
        } else {
            result += 5000
        }
    })
    return result
}