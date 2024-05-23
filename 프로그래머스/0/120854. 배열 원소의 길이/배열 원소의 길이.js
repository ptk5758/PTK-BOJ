function solution(strlist) {
    return strlist.reduce((prev, current) => {
        return [...prev, current.split("").length]
    }, [])
}