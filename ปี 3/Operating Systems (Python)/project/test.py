from policy import FIFO,RANDOM,LRU
from workload import x_ywork,no_local,loop

p_select = 2        #policy     0=FIFO      1=RANDOM            2=LRU
w_type = 0          #workload   0=no-local  1=hotwork-hotpage   2=loop
c_size = 3          #Cache size
u_work = 5          #total unique pages
t_work = 20         #total pages accessed(worload)
per_hwork = 80      #percent of hotwork compared to wokload
per_hpage = 20      #percent of hotpage compared to unique pages


q = [FIFO(c_size),RANDOM(c_size),LRU(c_size)]
wl_nl = [no_local(u_work,t_work),x_ywork(u_work,t_work, per_hwork, per_hpage),loop(u_work , t_work)]
p = ["FIFO","RANDOM","LRU"]
wl = ["no-local",str(per_hwork)+"-"+str(per_hpage)+" Workload","loop"]
hit=0
print("Policy :",p[p_select])
print("Cache size =",c_size)
print("Work type :",wl[w_type])
print("{:<4} {:<8} {:<15} {:<10} {:<10}".format('No.','Access','Hit/Miss','Evict','Cache State'))
j=0
for i in wl_nl[w_type]:
    
    j+=1
    ret = q[p_select].use(i)
    if(ret == -1):
        hit+=1
        print("{:<4} {:<8} {:<15} {:<10} ".format(j,i,'Hit',' '),q[p_select].list)
        #tablerow = [i,j,'Hit',' ',q[p_select].list]
    elif(ret == -2):
        print("{:<4} {:<8} {:<15} {:<10} ".format(j,i,'Miss',''),q[p_select].list)
        #tablerow = [i,j,'Miss',' ',q[p_select].list]
    else:
        print("{:<4} {:<8} {:<15} {:<10} ".format(j,i,'Miss',ret),q[p_select].list)
        #tablerow = [i,j,'Miss',ret,q[p_select].list]
print("hit",hit,"miss",j-hit)
print("hit rate = {0:.02f}".format(hit/j))
print("hit rate(compulsory miss) = {0:.02f}".format(hit/(j-c_size)))
