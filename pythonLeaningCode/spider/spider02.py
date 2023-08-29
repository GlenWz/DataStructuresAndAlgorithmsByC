import requests

# get方式

content=input("请输入你要检索的内容")
url=f"http://www.sogou.com/web?query={content}"



headers={
    "User-Agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/116.0.0.0 Safari/537.36"
}
# 处理了一个小小的反爬
resp=requests.get(url,headers=headers)
# resp=requests.get("http://127.0.0.1:5000/request/",headers=headers)
#   print(request.user_agent) # 这里设置请求头修改了
print(resp.text)

print(resp.request.headers)