function solution(phone_book) {
    phone_book.sort((a, b) => {
        return a.length - b.length
    })
    var answer = false;
    let obj = {}
    phone_book.forEach((phone, index) => {
        let target = obj
        const nums = phone.split("")
        for (let i=0; i<phone.length; i++) {
            if (index && target[nums[i]]) {
                if (Object.keys(target[nums[i]]).length === 0) answer = true
            }
            
            target[nums[i]] = {
                ...target[nums[i]]
            }
            target = target[nums[i]]
        }
    })
    return !answer;
}