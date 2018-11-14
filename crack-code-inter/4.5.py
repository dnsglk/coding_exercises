#!/usr/bin/env python

from binarytree import tree
from queue import Queue
import random

def is_bst(node):
    return is_bst_iterative(node)

def is_bst_iterative(node):
    if node == None:
        return False
    #check level 1
    if not node_is_bst_valid(node):
        return False

    next_level = Queue()
    if node.left != None:
        next_level.put((node.left,node))
    #check left subtree
    while not next_level.empty():
        cur_tuple = next_level.get()
        cur_node, parent = cur_tuple[0], cur_tuple[1]

        # the main check of the level
        left_child_isnot_bst = cur_node.left != None and cur_node.left.value < parent.value
        right_child_isnot_bst = cur_node.right != None and cur_node.right.value > node.value

        if not node_is_bst_valid(cur_node) or left_child_isnot_bst or right_child_isnot_bst:
            return False

        # Add children for subsequent processsing
        if cur_node.left != None:
            next_level.put((cur_node.left,cur_node))
        if cur_node.right != None:
            next_level.put((cur_node.right,cur_node))
        
    return True

def node_is_bst_valid(node):
    if node.right != None and node.value > node.right.value:
        return False
    if node.left != None and node.value < node.left.value:
        return False
    return True

'''
Recursive implementation follows
'''    
def is_bst_recursive(node):
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
        if bst1 != bst2 or (bst1 and bst2 and test_tree.size > 5):
            print(test_tree)
            print('Tree is BST = {0}, isBST={1}'.format(bst1, bst2))
            break
