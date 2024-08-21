function solution(myString) {
    return myString.split("").reduce((p,c) => c < 'l'? p+"l":p+c,"")
}