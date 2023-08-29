
import requests

# 如何做post请求

url="https://fanyi.baidu.com/sug"

hehe={
    "kw":input("请输入一个单词：")
}
headers={
    "User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/116.0.0.0 Safari/537.36"
}

resp=requests.post(url,data=hehe,headers=headers)


print(resp.text)    #拿到的文本
print(resp.json())  #拿到的JSON数据
