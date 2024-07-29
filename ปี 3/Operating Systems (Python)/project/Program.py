from tkinter import * 
from tkinter import ttk
from policy import FIFO,RANDOM,LRU
from workload import x_ywork,no_local,loop
import tkinter.font as font

root = Tk()
root.geometry("1000x400")
root.resizable(0, 0)
root.title("Swapping: Policies")

frame = Frame(root)
bottomframe = Frame(root)
poliframe = Frame(root)
listframe = Frame(root)
T = Text(root, height=40, width=1000)


def back(cur,prev):
    cur.pack_forget()
    prev.pack()
    
def firstpage():
    frame.pack()
    bottomframe.pack(side = BOTTOM)

def policy_but(po):
    global p
    p=po
    frame.pack_forget()
    poliframe.pack()

def loadlist(wtype=2, poli=1 ,csize=3 ,total=20 ,limit=5 ,per_hwork=80, per_hpage=20):
    poliframe.pack_forget()
    q = [FIFO(csize),RANDOM(csize),LRU(csize)]
    wl_nl = [no_local(limit,total),x_ywork(limit,total, per_hwork, per_hpage),loop(limit,total)]
    p = ["FIFO","RANDOM","LRU"]
    wl = ["no-local",str(per_hwork)+"-"+str(per_hpage)+" Workload","loop"]
    hit=commiss=j=0
    allwork = []
    for i in wl_nl[wtype]:
        j+=1
        ret = q[poli].use(i)
        if(ret == -1):
            hit+=1
            Tview.insert(parent='',index='end',iid=j-1,text='',values=[j,i,'Hit',' ',q[poli].list])
            #tablerow = [i,j,'Hit',' ',q[p_select].list]
        elif(ret == -2):
            Tview.insert(parent='',index='end',iid=j-1,text='',values=[j,i,'Miss',' ',q[poli].list])
            #tablerow = [i,j,'Miss',' ',q[p_select].list]
        else:
            Tview.insert(parent='',index='end',iid=j-1,text='',values=[j,i,'Miss',ret,q[poli].list])
            #tablerow = [i,j,'Miss',ret,q[p_select].list]
        if(i not in allwork):
            allwork.append(i)
    Tview.pack()
    listframe.pack()
    word = "policy : "+p[poli]+"\nworload type : "+wl[wtype]+"\ntotal pages accessed : "+str (total) +"\ntotal unique pages : "+str (
        limit) + "\nCache size : "+str(csize) + "\nhit rate = "+str(hit)+"/"+str(total)+ " = {0:.02f}".format(
            hit/total) + "\nhit rate(compulsory miss) = "+str(hit)+"/("+str(total)+"-"+str(len(
                allwork))+") = {0:.02f}".format(hit/(total-len(allwork)))
    T.insert(END, word)
    T.pack()
            

nolocal_b = Button(poliframe, text = 'no local',height= 2, width=10,bg='pink', fg ='black',
                   command=lambda: loadlist(poli=p,wtype=0,csize=cs.get(),total=ta.get(),limit=up.get()))
nolocal_b['font'] = font.Font(size=20)
w80_20_b = Button(poliframe, text = 'n-m workload',height= 2, width=10,bg='yellow', fg='black',
                  command=lambda: loadlist(poli=p,wtype=1,csize=cs.get(),total=ta.get(),limit=up.get(),
                                           per_hwork=perhw.get(), per_hpage=perhp.get()))
w80_20_b['font'] = font.Font(size=20)
loop_b = Button(poliframe, text ='loop',height= 2, width=10,bg='lightblue', fg ='black',
                command=lambda: loadlist(poli=p,wtype=2,csize=cs.get(),total=ta.get(),limit=up.get()))
loop_b['font'] = font.Font(size=20)
back_b = Button(poliframe, text ='back',height= 2, width=10,bg='lightgreen', fg ='black',
                command=lambda:back(poliframe,frame))
back_b['font'] = font.Font(size=20)
ta = IntVar()
totalacress = Label(poliframe, text = 'total page acress (workload)', font=('calibre',10, 'bold'))
ta_entry =Entry(poliframe,textvariable = ta, font=('calibre',10,'normal'))
ta_entry.delete(0,END)
ta_entry.insert(0,20)
totalacress.pack()
ta_entry.pack()
up = IntVar()
uqpage = Label(poliframe, text = 'total unique page', font=('calibre',10, 'bold'))
up_entry =Entry(poliframe,textvariable = up, font=('calibre',10,'normal'))
up_entry.delete(0,END)
up_entry.insert(0,5)
uqpage.pack()
up_entry.pack()
cs = IntVar()
csize = Label(poliframe, text = 'cache size', font=('calibre',10, 'bold'))
cs_entry =Entry(poliframe,textvariable = cs, font=('calibre',10,'normal'))
cs_entry.delete(0,END)
cs_entry.insert(0,3)
csize.pack()
cs_entry.pack()
perhw = IntVar()
perhotwork = Label(poliframe, text = 'percentage of hotwork compared to all work (n)', font=('calibre',10, 'bold'))
phw_entry =Entry(poliframe,textvariable = perhw , font=('calibre',10,'normal'))
phw_entry.delete(0,END)
phw_entry.insert(0,80)
perhotwork.pack()
phw_entry.pack()
perhp = IntVar()
perhotpage = Label(poliframe, text = 'percentage of hotpage compared to all page (m)', font=('calibre',10, 'bold'))
php_entry =Entry(poliframe,textvariable = perhp, font=('calibre',10,'normal'))
php_entry.delete(0,END)
php_entry.insert(0,20)
perhotpage.pack()
php_entry.pack()

nolocal_b.pack( side = LEFT)
w80_20_b.pack( side = LEFT )
loop_b.pack( side = LEFT )
back_b.pack( side = LEFT)


ptitle = Label(frame, text = 'Please select Policy', font=('calibre',40, 'bold'))
ptitle.pack()
space = Label(frame, text = '', font=('calibre',30, 'bold'))
space.pack()
FIFO_b = Button(frame, text = 'FIFO',height= 2, width=10,bg='purple', fg ='white',command=lambda: policy_but(0))
FIFO_b['font'] = font.Font(size=30)
RAND_b = Button(frame, text = 'RANDOM',height= 2, width=10,bg='brown', fg='white',command=lambda: policy_but(1))
RAND_b['font'] = font.Font(size=30)
LRU_b = Button(frame, text ='LRU',height= 2, width=10,bg='darkblue', fg ='white',command=lambda: policy_but(2))
LRU_b['font'] = font.Font(size=30)
FIFO_b.pack( side = LEFT)
RAND_b.pack( side = LEFT )
LRU_b.pack( side = BOTTOM )



scroll = Scrollbar(listframe)
scroll.pack(side=RIGHT, fill=Y)
Tview = ttk.Treeview(listframe,yscrollcommand=scroll.set)
Tview.pack()
scroll.config(command=Tview.yview)
Tview['columns'] = ('No.', 'Access', 'Hit/Miss', 'Evict', 'Cache State')
Tview.column("#0", width=0,  stretch=NO)
Tview.column("No.",anchor=CENTER, width=100)
Tview.column("Access",anchor=CENTER,width=100)
Tview.column("Hit/Miss",anchor=CENTER,width=100)
Tview.column("Evict",anchor=CENTER,width=100)
Tview.column("Cache State",anchor=CENTER,width=800)
Tview.heading("#0",text="",anchor=CENTER)
Tview.heading("No.",text="No.",anchor=CENTER)
Tview.heading("Access",text="Access",anchor=CENTER)
Tview.heading("Hit/Miss",text="Hit/Miss",anchor=CENTER)
Tview.heading("Evict",text="Evict",anchor=CENTER)
Tview.heading("Cache State",text="Cache State",anchor=CENTER)
Tview.pack()


Exit_b = Button(bottomframe, text ='Exit',height= 1, width=5,bg='black', fg ='white',command=root.destroy)
Exit_b['font'] = font.Font(size=20)
Exit_b.pack( side = BOTTOM)

firstpage()

root.mainloop()
