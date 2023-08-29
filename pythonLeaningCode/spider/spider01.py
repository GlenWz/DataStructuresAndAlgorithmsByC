
from urllib.request import urlopen

resp=urlopen("https://baidu.com")
# resp=urlopen('http://127.0.0.1:5000/request/')

# 这里通过 Flask的 print(request.user_agent)还是能监测到用得python
# Python-urllib/3.11
# Python-urllib/3.11
# 国内网站无非就是GBK和UTF-8编码
# print(resp.read().decode("utf-8"))  # 此时拿到的是页面源代码

with open("../tmp/mybaidu.html", mode="w", encoding="utf-8") as f:
    f.write(resp.read().decode("utf-8"))