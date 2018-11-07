#!/usr/bin/env python
from binarytree import tree 

def isBalanced(tree):
    
    if tree.left != None and isBalanced(tree.left) == False:
        return False
    if tree.right != None and isBalanced(tree.right) == False:
        return False

    hL = getHeight(tree.left)
    hR = getHeight(tree.right)
    
    return True if (hL - hR) ^ 2 <= 1 else False

def getHeight(node):
    if node == None:
        return 0
    hL = 0
    hR = 0
    if node.left != None:
        hL = getHeight(node.left)
    if node.right != None:
        hR = getHeight(node.right)

    return hL + 1 if hL > hR else hR + 1

if __name__  == "__main__":
    test_tree =  tree(height=3, is_perfect=False)
    print(test_tree)
    testTreeIsBalanced = isBalanced(test_tree) 
    print 'Tree is balanced: ', testTreeIsBalanced
