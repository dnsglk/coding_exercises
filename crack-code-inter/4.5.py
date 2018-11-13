#!/usr/bin/env python

from binarytree import tree
import random

def is_bst(node):
    result =  is_bst_impl(node)
    return result['is_bst'] 

def is_bst_impl(node):
    
    if node.left != None:
        result = is_bst_impl(node.left)
        if not result['is_bst'] or result['value'] > node.value:
            return {'is_bst': False, 'value': node.value}

    if node.right != None:
        result = is_bst_impl(node.right)
        if not result['is_bst'] or result['value'] < node.value:
            return {'is_bst': False, 'value': node.value}
 
    return {'is_bst': True, 'value': node.value}
 

if __name__ == '__main__':
    while True:
        test_tree = tree(is_perfect=False, height=random.randint(0,6))
        bst1,bst2 = test_tree.is_bst, is_bst(test_tree)
        if bst1 and bst2 and test_tree.size > 5:
            print(test_tree)
            print('Tree is BST = {0}, isBST={1}'.format(bst1, bst2))
            break
