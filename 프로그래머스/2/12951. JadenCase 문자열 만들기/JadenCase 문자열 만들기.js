function solution(s) {
    var answer = s.split(" ").reduce((prev, current) => {
        let i = 0
        return prev += " " + current.split("").reduce((_prev, _current) => {
            return _prev += i++ ? _current.toLowerCase() : _current.toUpperCase()
        }, '')
    }, '')
    return answer.slice(1);
}