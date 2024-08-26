class Student:
    def __init__(self,name,id):
        self.name=name
        self.id=id
        self.grades={"语文":0,"数学":0,"英语":0}
    def setgrsde(self,course,grade):
        if course in self.grades:
            self.grades[course]=grade
    def printall(self):
        print(f"学生{self.name}(学号:{self.id})的成绩为:")
        for course in self.grades:
            print(f"{course}:{self.grades[course]}分")
chen=Student("小陈","100")
zeng=Student("小曾","101")
print(chen.name)
print(chen.id)
zeng.setgrsde("数学",95)
print(zeng.grades)
zeng.printall()