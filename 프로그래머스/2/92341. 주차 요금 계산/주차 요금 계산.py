import math
from collections import defaultdict

def solution(fees, records):
    answer = []
    min_time, base_fee, unit_time, unit_fee = fees
    rec = dict()
    tim = defaultdict(int)
    res = dict()
    max_time = 23 * 60 + 59

    for r in records:
        cur, num, state = r.split()
        
        h, m = map(int, cur.split(':'))
        now = h*60 + m

        if state == "IN":
            rec[num] = now
        else:
            tim[num] += now - rec[num]
            rec.pop(num)
        
    for n, t in rec.items():
        tim[n] += max_time - t

    for n in tim:
        t = tim[n]
        fee = base_fee
        if(t > min_time):
            fee += math.ceil((t - min_time) / unit_time) * unit_fee
        res[n] = fee
    answer = [res[n] for n in sorted(res.keys())]

    return answer
            
print(solution(
    [180, 5000, 10, 600], 
    ["05:34 5961 IN", "06:00 0000 IN", "06:34 0000 OUT", 
     "07:59 5961 OUT", "07:59 0148 IN", "18:59 0000 IN", 
     "19:09 0148 OUT", "22:59 5961 IN", "23:00 5961 OUT"]
))