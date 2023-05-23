import matplotlib.pyplot as plt
import numpy as np
import json
import re
from jsonmerge import merge

files=['.\\Semester task\\Graphs\\openmp.json','.\\Semester task\\Graphs\\pthread.json','.\\Semester task\\Graphs\\threading.json']

def merge_JsonFiles(input_files):
    with open(".\\Semester task\\Graphs\\openmp.json", "r") as read_file:
        data1 = read_file.readlines()
    with open(".\\Semester task\\Graphs\\pthread.json", "r") as read_file:
        data2 = read_file.readlines()
    




def draw_graphs():
    with open(".\\Semester task\\Graphs\\test.json", "r") as read_file:
        data = json.load(read_file)

    figure, axis = plt.subplots(3, 2, figsize=(8, 8))
    i = 0
    for d in data:
        for s in data[d]['threads']:
            axis[i, 0].plot(data[d]['data_num'],data[d]['threads'][s], color='red', label=d)
        
        axis[i, 0].set_title(d)
        i += 1

    plt.tight_layout()
    plt.show()

merge_JsonFiles(files)

