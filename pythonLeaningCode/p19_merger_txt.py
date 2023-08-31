
import os

data_dir="./tmp/txt"
contents=[]

for file in os.listdir(data_dir):
    file_path=f"{data_dir}/{file}"
    if os.path.isfile(file_path) and file.endswith(".txt"):
        with open(file_path) as file:
            contents.append(file.read())
final_content="\n".join(contents)

with open("./tmp/all.txt","w") as output:
    output.write(final_content)