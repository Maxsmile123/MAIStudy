import os


prefix = str(input())
suffix = str(input())

def rewiewDir(pwd):
    listdir = os.listdir(pwd)
    for element in listdir:
        print(element, " - ")
        if os.path.isdir(element):
            print("Dir")
            rewiewDir(pwd + "/" + element)
        elif os.path.isfile(element):
            if element.rfind(suffix) == len(element) - len(suffix):
                os.rename(element, prefix + element)

rewiewDir(os.getcwd())

