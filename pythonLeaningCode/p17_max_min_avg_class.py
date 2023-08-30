
# 计算每一门课程的最高分最低分和平均分

class txtReader:
    def readFile(self,url:str)->dict:
        ret={}
        try:
            with open(url, encoding="UTF-8")as filesTxt:
                for line in filesTxt:
                    line=line[:-1]
                    course,sno,sname,grade=line.split(",")
                    if course not in ret:
                        ret[course]=[]
                    ret[course].append(int(grade))
            ret.append(course,sno,sname,grade)

        except:
            print("errr")
        return ret

class Statistics_max_min_avg:
    def get_Max(self,iptList:list):
        return max(iptList)

    def get_min(self,iptList:list):
        return min(iptList)

    def get_avg(self,iptList:list):
        return sum(iptList)/len(iptList)


txtreader=txtReader()
getDic=txtreader.readFile("./tmp/score.txt")

sta=Statistics_max_min_avg()

for item in getDic:
    print(f"{item},max:{sta.get_Max(getDic[item])}"
          f",min:{sta.get_min(getDic[item])},"
          f",avg:{sta.get_avg(getDic[item])}")

# print(getDic)


