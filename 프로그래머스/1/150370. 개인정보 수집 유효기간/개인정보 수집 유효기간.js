function solution(t, a, b) {
    const today = t.split(".").map(e=>+e)
    const term = a.reduce((p,c) => {
        const [type, month] = c.split(" ")
        return {
            ...p,
            [type] : +month
        }
    }, {})
    const result = []
    b.forEach((item, index) => {
        const [date, type] = item.split(" ")
        let [year, month, day] = date.split(".").map(e=>+e)
        month += term[type]
        if (month > 12) {
            year += Math.floor((month - 1) / 12)
            month = (month - 1) % 12 + 1
        }
        const flag = year < today[0]
            || year == today[0] && month < today[1]
            || year == today[0] && month == today[1] && day <= today[2];
        if (flag)
        {
            result.push(index + 1);
        }
    })
    return result
}