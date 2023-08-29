import requests

#
url="https://baidu.com"
resp=requests.get(url)
resp.encoding="utf-8"

print(resp.text)