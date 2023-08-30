
# 实现两个txt的关联

class TxtWriter:
    def writeToTxt(self,url:str,iptList):
        with open(url,"w",encoding="UTF-8") as txtFlie:
            for line in iptList:
                txtFlie.write(",".join(line)+"\n")
 
class TxtReader:

    def readTeacher(self,url:str)->dict:
        ret={}
        with open(url,encoding="UTF-8") as filesTxt:
            for line in filesTxt:
                line=line[:-1]
                course,teacher=line.split(":")
                print(teacher)
                if course not in ret:
                    ret[course]=[]
                ret[course].append(teacher)
        return ret

    def addTeacherToFile(self,url:str,teachers:dict)->list:
        ret =[]
        with open(url,encoding="UTF-8") as filesTxt:
            for line in filesTxt:
                line=line.replace('\n',"")
                line=line.split(",")
                print(line[len(line)-1])
                line.append(teachers[line[0]][0])
                print(line)
                ret.append(line)
        return ret

txtR=TxtReader()
retdic=txtR.readTeacher("./tmp/teachers.txt")
ret= txtR.addTeacherToFile("./tmp/score.txt",retdic)
txtW=TxtWriter()
txtW.writeToTxt("./tmp/hello.txt",ret)
