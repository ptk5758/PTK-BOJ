function solution(todo_list, finished) {
    const result = []
    for (let i=0; i<todo_list.length; i++) {
        if (!finished[i]) result.push(todo_list[i])
    }
    
    return result
}