#!/usr/bin/env python
import random
from binarytree import tree 

'''
DOESN'T WORK!!!

Balanced tree should have difference between max height
and min heigt no more than 1. Max height is the max distance from
root to leaf. Min height is the min distance from the root to the
first null child in any node.
'''
def _isBalanced(tree):
    
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



'''
Recursively check that each subtree doesn't have difference in 
height more than by 1 point.
'''
def isBalanced(node):    
    if node == None or (node.left == None and node.right == None):
        return True

    results_left = getHeight(node.left)
    results_right = getHeight(node.right)
    hL, hR = results_left['height'], results_right['height']
    left_is_balanced, right_is_balanced = results_left['is_balanced'], results_right['is_balanced']
 
    return True if left_is_balanced and right_is_balanced and abs(hL - hR) <= 1 else False

def getHeight(node):
    if node == None:
        return {"is_balanced": True, "height": 0}

    results = getHeight(node.left) 
    hL, is_balanced = results['height'] + 1, results['is_balanced']
    if not is_balanced:
        print "Not balanced ", hL, node.value
        return {'height':hL, 'is_balanced': False} 

    results_tupple = getHeight(node.right)
    hR, is_balanced = results['height'] + 1, results['is_balanced']
    if not is_balanced:
        print "Not balanced ", hR, node.value
        return {'height':hR, 'is_balanced' : False}

    maxH = hL if hL > hR else hR
    balanced =  abs(hL - hR) <= 1

    print node.value, hL, hR, balanced

    return {'height': maxH, 'is_balanced': balanced}
    

def run_algo(iter_num):
    for i in range(iter_num):
        test_tree =  tree(height=random.randint(0,4), is_perfect=False)
        testTreeIsBalanced = isBalanced(test_tree) 

        if testTreeIsBalanced != test_tree.is_balanced:
            print(test_tree)
            print 'Tree is', '' if test_tree.is_balanced else ' not', ' balanced. Manual algo returns ', testTreeIsBalanced
            print 'Max,min = ', getMaxHeight(test_tree), getMinHeight(test_tree)
            #return
    

if __name__  == "__main__":
    run_algo(100)
