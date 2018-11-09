#!/usr/bin/env python
import random
from binarytree import tree 

'''
Balanced tree should have difference between max height
and min heigt no more than 1. Max height is the max distance from
root to leaf. Min height is the min distance from the root to the
first null child in any node.
'''
def isBalanced(tree):
    
    hMax = getMaxHeight(tree)
    hMin = getMinHeight(tree)

    #print "Max height", hMax, " min height ", hMin

    return True if hMax - hMin <= 1 else False

def getMinHeight(node):
    if node.left == None or node.right == None:
        return 1
    
    hL = getMinHeight(node.left) + 1
    hR = getMinHeight(node.right) + 1

    return hL if hL < hR else hR

def isBalanced2(tree):    
    if tree.left != None and isBalanced(tree.left) == False:
        return False
    if tree.right != None and isBalanced(tree.right) == False:
        return False

    hL = getHeight(tree.left)
    hR = getHeight(tree.right)
    
    return True if (hL - hR) ^ 2 <= 1 else False

def getMaxHeight(node):
    if node == None:
        return 0
    hL = 0
    hR = 0
    if node.left != None:
        hL = getMaxHeight(node.left)
    if node.right != None:
        hR = getMaxHeight(node.right)

    return hL + 1 if hL > hR else hR + 1

def run_algo(iter_num):
    for i in range(iter_num):
        test_tree =  tree(height=random.randint(0,6), is_perfect=False)
        testTreeIsBalanced = isBalanced(test_tree) 

        if testTreeIsBalanced != test_tree.is_balanced:
            print(test_tree)
            print 'Tree is ', '' if test_tree.is_balanced else 'not', ' balanced. Manual algo returns ', testTreeIsBalanced
            print 'Max,min = ', getMaxHeight(test_tree), getMinHeight(test_tree)
            return
    

if __name__  == "__main__":
    run_algo(1000)
