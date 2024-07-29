import random

class FIFO:
    def __init__(self, msize):
        self.list = []
        self.msize = msize
    def add(self,num):
        if(self.msize == len(self.list)):
            self.list.append(num)
            return self.list.pop(0)
        self.list.append(num)
        return -2
    def use(self,num):
        if num not in self.list:
            return self.add(num)
        else:
            self.list.pop(self.list.index(num))
            self.list.append(num)
            return -1
        
    
class RANDOM:
    def __init__(self,msize):
        self.list = []
        self.msize = msize
    def add(self,num):
        if(self.msize == len(self.list)):
            self.list.append(num)
            return self.list.pop(random.randint(0,self.msize-2))
        self.list.append(num)
        return -2
    def use(self,num):
        if num not in self.list:
            return self.add(num)
        return -1

class LRU:
    def __init__(self, msize):
        self.list = []
        self.call = []
        self.come = []
        self.turn = 0
        self.msize = msize
    def lru(self):
        self.luserate=self.call[0]/(self.turn-self.come[0])
        self.delete = 0
        for i in range(1,self.msize):
            self.puserate = self.call[i]/(self.turn-self.come[i])
            if(self.puserate < self.luserate):
                self.delete = i
                self.luserate = self.puserate
        return self.delete
    def add(self,num):
        if(self.msize == len(self.list)):
            self.d=self.lru()
            self.r=self.list.pop(self.d)
            self.come.pop(self.d)
            self.call.pop(self.d)
            self.list.append(num)
            self.come.append(self.turn)
            self.call.append(1)
            return self.r
        self.list.append(num)
        self.come.append(self.turn)
        self.call.append(1)
        return -2
    def use(self,num):
        self.turn += 1
        if(num not in self.list):
            return self.add(num)
        else:
            self.call[self.list.index(num)]+=1
            return -1
        
        
        