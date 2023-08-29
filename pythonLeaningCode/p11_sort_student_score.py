
# 实现学生成绩的排序

score= [
    {'sno':100,'sname':'liMa','sgrade':90},
    {'sno':101,'sname':'jackMa','sgrade':79},
    {'sno':101,'sname':'jackMa','sgrade':101},
    {'sno':102,'sname':'paMa','sgrade':88},
    {'sno':103,'sname':'sMa','sgrade':55},
    {'sno':104,'sname':'ckMa','sgrade':94},
    {'sno':105,'sname':'ckMas','sgrade':84}
]

tup2 = (1,8,6,5,4, 2, 3, 4, 5, 6, 7 )

retScore=sorted(score,key=lambda x:x['sgrade'])

retS=sorted(tup2)
print(f"source{score}")
print(retS)
print(retScore)

