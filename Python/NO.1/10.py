class Worker:
    def __init__(self,name,id):
        self.name=name
        self.id=id
    def print_intfo(self):
        print(self.name)
        print(self.id)
class FullWorker(Worker):
    def __init__(self,name,id,mouthmoeny):
        super().__init__(name,id)
        self.mouthmoeny=mouthmoeny
    def jisuanyuexin(self):
        return self.mouthmoeny
class PertWorker(Worker):
    def __init__(self,name,id,daymoeny,workdays):
        super().__init__(name,id)
        self.daymoeny=daymoeny
        self.workerdays=workdays
    def jisuanyuexin(self):
        return self.daymoeny*self.workerdays
p=PertWorker("王刚",100,200,10)
print(p.jisuanyuexin())