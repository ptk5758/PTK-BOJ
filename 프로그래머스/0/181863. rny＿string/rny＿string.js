function solution(rny_string) {
    while (rny_string.indexOf("m") !== -1) 
        rny_string = rny_string.replace("m", "rn")
    return rny_string
    
}