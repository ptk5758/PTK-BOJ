function solution(s)
{
    const stack = []
    for (let i=0; i<s.length; i++) {
        const c = s[i]
        // words.shift()
        const last = stack.length - 1
        if (stack[last] === c) {
            stack.pop()
        } else {
            stack.push(c)
        }
    }
    return stack.length > 0 ? 0 : 1
}