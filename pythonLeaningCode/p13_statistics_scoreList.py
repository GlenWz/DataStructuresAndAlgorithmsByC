
# 统计最高分，最低分，平均分

# ./tmp/score.txt

class Sta_Utils:
    def max(self,inputlist:list):
        return max(inputlist)
    def min(self,inputlist:list):
        return min(inputlist)
    def avg(self,inputlist:list):
        return sum(inputlist)/len(inputlist)

class StatisicScore:
    def read_score_files(self,url:str)->list:
        ret=[]
        retlist=[]
        try:
            with open(url, encoding="UTF-8") as fileTxt:
                for line in fileTxt:
                    line=line[:-1]
                    print(line)
                    ret=line.split(',')
                    retlist.append(int(ret[-1]))

        except:
            print("read error")
        return retlist

sta=StatisicScore()
retlist=sta.read_score_files("./tmp/score.txt")
sutils=Sta_Utils()
print(retlist)
print(sutils.max(retlist))
print(sutils.min(retlist))
print(sutils.avg(retlist))