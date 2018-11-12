#!/usr/bin/env python

from binarytree import tree 
import random

def getNodesAtDepth(depth, node):
    if node == None :
        return []

    return dfs(stop_height=depth,node=node,current_height=1)

def dfs(stop_height, current_height, node):
    if node == None:
        return []    

    if stop_height == current_height:
        return [node.value]

    results = dfs(stop_height, current_height+1, node=node.left)
    results += dfs(stop_height, current_height+1, node=node.right)
           
    return results 

if __name__ == '__main__':
    test_tree_height = random.randint(0,5)
    test_tree = tree(is_perfect=False, height=test_tree_height)
    print(test_tree)
    for h in range(1,test_tree_height + 2):
        print(getNodesAtDepth(h,test_tree))
