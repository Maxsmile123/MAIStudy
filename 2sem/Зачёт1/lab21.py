import os
import sys

prefix = str(input())
suffix = str(input())

def rewiewDir(pwd):
    listdir = os.listdir(pwd) # Создаём список всех элементов в текущей директории
    for element in listdir: # Цикл в питоне
        path = pwd + "/" + element
        if os.path.isdir(path): # если элемент директория
            rewiewDir(path) # рекурсия c погруженнием в эту директорию
        elif os.path.isfile(path): # если элемент файл
            if element.rfind(suffix) == len(element) - len(suffix): # проверка, что суффикс входит в строку и при этом он в конце строки (по определнию суффикса)
                os.rename(element, prefix + element) # переименовываем файл, добавляю к нему префикс

if prefix is None or suffix is None:
    print("Need exactly two arguments")
    sys.exit()
rewiewDir(os.getcwd()) # вызов функции с передачей в неё текущей директории
