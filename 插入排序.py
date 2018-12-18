#!/usr/bin/python3
"""
插入排序就是始终保持左侧有序,将右侧的元素有序插入进左侧序列,直至全部排序完成
"""

M=[2,5,8,3,6,7,22,5]
#A.sort()
def ins_sort(A):
    """定义了一个插入排序"""
    for i in range(1,len(A)):   #可以用 range(1,len(A),1)表示从1开始，每次跨度为1
        key=A[i]
        j=i-1
        while (j>=0 and A[j]>key):
            A[j+1]=A[j]
            j=j-1
        A[j+1]=key
ins_sort(M)
for i in M:
    print (i)

    
