# def merge_plannings(p1, p2): 
#     #logic
#         #count through first points
#         #if x of p1 > x of p2
#             #if y of p1 
#     len1 = len(p1)
#     len2 = len(p2)
#     plan = list()
#     curtime = 0
#     curpay = 0
#     i = 0
#     j = 0
#     while i <= len1 and j <= len2:
#         if p1[i][0] <= p2[j][0]:
#             if curpay <= p2[j][1]:
#                 curpay = p2[j][1]
#                 curtime = p2[j][0]
#                 plan.append([curtime, curpay])
#                 j = j+1
#         elif p1[i][0] > p2[j][0]:
#             if curpay <= p1[i][1]:
#                 curpay = p1[i][1]
#                 curtime = p1[i][0]
#                 plan.append([curpay, curtime])
#                 i = i+1
#     return plan


# def merge_plannings(p1, p2):
#     len1 = len(p1)
#     len2 = len(p2)
#     plan = list()
#     t = 0
#     pay1 = 0
#     pay2 = 0
#     curpay = 0
#     i = 0
#     j = 0
#     while (i <= len1 and j <= len2):
#         p1t = p1[i][0]
#         p2t = p2[j][0]
#         p1p = p1[i][1]
#         p2p = p2[i][1]
#         if (t == p1t and t == p2t):
#             if (p1p > p2p):
#                 pay1 = p1p
#                 pay2 = p2p
#                 plan.append((t, pay1))
#                 print(plan)
#                 i = i + 1
#                 t = t + 1
#             else:
#                 pay1 = p1p
#                 pay2 = p2p
#                 plan.append((t, pay2))
#                 print(plan)
#                 j = j + 1
#                 t = t + 1
#         elif(t == p1t):
#             if(p1p > p2p):
#                 pay1 = p1p
#                 plan.append((t, pay1))
#                 print(plan)
#                 i = i + 1
#                 t = t + 1
#             else: 
#                 pass
#         elif(t == p2t):
#             if(p2p > p1p):
#                 pay2 = p2p
#                 plan.append((t, pay2))
#                 print(plan)
#                 j = j + 1
#                 t = t + 1
#         else: 
#             t = t + 1
#     print("finished")
#     return plan




        #after the ifs
        #increment t

# def merge_plannings(p1, p2):
#     len1 = len(p1)
#     len2 = len(p2)
#     plan = []
#     curpay = 0
#     i, j = 0, 0
#     pay1, pay2 = 0, 0
#     while (i <= len1 and j <= len2):
#         t1 = p1[i][0]
#         t2 = p2[j][0]
#         pay1 = p1[i][1]
#         pay2 = p2[j][1]
#         if (t1 > t2):
#             if (curpay <= pay2):
#                 curpay = pay2
#                 plan.append((t2, curpay))
#                 j += 1
#             else:
#                 j += 1
                
#         elif (t1 < t2):
#             if (curpay <= pay1):
#                 curpay = pay1
#                 plan.append((t1, curpay))
#                 i += 1
#             else:
#                 i += 1
#         elif(t1 == t2):
#             if (pay2 == pay1):
#                 if (curpay <= pay1):
#                     curpay = pay1
#                     plan.append((t1, curpay))
#                     i+=1
#                     j+=1
#             elif ((pay1 > curpay)and(pay1 > pay2)):
#                 curpay = pay1
#                 plan.append((t1, curpay))
#                 i+=1
#                 j+=1
#             elif ((pay2 > curpay)and(pay2 > pay1)):
#                 curpay = pay2
#                 plan.append((t2, pay2))
#                 i+=1
#                 j+=1
#             else:
#                 i+=1
#                 j+=1
#     if (len1 - len2) > 1:
#         if (len1 > len2):
#             n = len1 - len2
#             for i in range(len2, len1+1):
#                 plan.append(p1[i])
#         elif (len2 > len1):
#             for i in range(len1, len2+1):
#                 plan.append(p1[i])
#     return plan

def merge_plannings(p1, p2):
    len1 = len(p1)
    len2 = len(p2)
    plan = []
    i, j = 0, 0
    pay1 = 0
    pay2 = 0
    pastpay = 0
    while (i < len1) and (j < len2):
        t1 = p1[i][0]
        t2 = p2[j][0]
        #update pay of most recent
        if (t1 > t2):
            pay2 = p2[j][1]
            now = t2
            #print("setting pay 2")
            #print(plan)
            j += 1
        elif (t1 < t2):
            pay1 = p1[i][1]
            now = t1
            #print("setting pay 1")
            #print(plan)
            i += 1
        else:
            pay2 = p2[j][1]
            pay1 = p1[i][1]
            now = t1
            #print("setting pay 1 and 2")
            #print(plan)
            j += 1
            i += 1
        #set curpay to whichever is the higher pay
        if (pay2 >= pay1):
            curpay = pay2
        else:
            curpay = pay1
        #append if changing lines
        if not(curpay == pastpay):
            plan.append((now, curpay))
            pastpay = curpay
            #print(plan)
    if (i == len1):
        for w in range(j, len2):
            plan.append(p2[w])
    elif (j == len2):
        for w in range(i, len1):
            plan.append(p1[w])
    return plan



# def optimal_planning(jobs):
#     #base
#     if len(jobs) < 2:
#         return
#     #divide
#     mid = len(L) // 2
#     A = L[:mid]
#     B = L[mid:]
#     #conquer
#     optimal_planning(A)
#     optimal_planning(B)
#     #combine
#     plan = [(jobs[0][0], jobs[0][2]), (jobs[0][1], 0)]

def optimal_planning(jobs):
    #basecase
    if len(jobs) == 1:
        return [(jobs[0][0], jobs[0][2]), (jobs[0][1], 0)]
    #other case
    mid = len(jobs)//2
    return merge_plannings(optimal_planning(jobs[:mid]), optimal_planning(jobs[mid:]))




    


if __name__ == '__main__':
    first_planning = [(2, 4), (5, 0), (6, 3), (10, 0)]
    second_planning = [(3, 5), (7, 0), (9, 2), (13, 0)]
    merge_plannings(first_planning, second_planning)
    merged = [(2, 4), (3, 5), (7, 3), (10, 2), (13, 0)]
    res_merge = merge_plannings(first_planning, second_planning)
    assert(res_merge == merged)

    plan1 = [(0, 1), (13, 0)]
    plan2 = [(4, 5), (5, 5), (10, 0)]
    result = merge_plannings(plan1, plan2)
    assert result == [(0, 1), (4, 5), (10, 1), (13, 0)]

    jobs_offers = [(2, 8, 3), (5, 7, 5)]
    optimal = [(2, 3), (5, 5), (7, 3), (8, 0)]
    res_planning = optimal_planning(jobs_offers)
    assert(res_planning == optimal)