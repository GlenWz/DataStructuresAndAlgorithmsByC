
# 统计英文文章中单词出现的次数

word_count={}

with open ("./tmp/paper.txt",encoding="UTF-8") as file:
    for line in file:
        line=line[:-1]
        words=line.split()
        for word in words:
            word=word.replace(",","").replace(".","")
            if word not in word_count:
                word_count[word]=0
            word_count[word]+=1

print(word_count)

print(
    sorted(
        word_count.items(),
        key=lambda x:x[1],
        reverse=True
    )
)