import json

with open("data.txt",encoding='utf-8') as file:

    n,m = map(int,file.readline().split(' '))
    
    json_str=''
    
    for i in range(n):
        json_str += file.readline()

    data = json.loads(json_str)

    querys = []
    for i in range(m):
        s = file.readline().replace('\n','')
        querys.append(s.split("."))

    json_type={
        str:"STRING",
        dict:"OBJECT"
        }

    for q in querys:
        s = ["data"]
        try:
            for x in q:
                s.append("["+repr(x)+"]")
            search = "".join(s)
            # print(search)
            if type(eval(search)) == str:
                print("STRING",eval(search))
            elif type(eval(search)) == dict:
                print("OBJECT")
        except Exception:
            print('NOTEXIST')