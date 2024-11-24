function solution(n, slicer, num_list) {
    const result = []
    if (n === 1) {
        for (let i=0; i<=slicer[1]; i++) {
            result.push(num_list[i]);
        }
    } else if (n === 2) {
        for (let i=slicer[0]; i<num_list.length; i++) {
            result.push(num_list[i]);
        }
    } else if (n === 3) {
        for (let i=slicer[0]; i<=slicer[1]; i++) {
            result.push(num_list[i]);
        }
        
    } else {
        for (let i=slicer[0]; i<=slicer[1]; i += slicer[2]) {
            result.push(num_list[i]);
        }
    }
    return result
}