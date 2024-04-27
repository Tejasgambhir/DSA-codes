


l=[3,2,8,2]
left_sum,right_sum,j=0,0,0
l_index,r_index=l.index(max(l)),l.index(max(l))
n=len(l)-1
for i in range(len(l)):
    if l_index!=-1:
        left_sum=left_sum + l[l_index]*n
        l_index-=1
        n-=1
    if r_index!=len(l)-1:
        r_index+=1
        right_sum=right_sum + l[r_index]*j
        j+=1
print(right_sum+left_sum)





