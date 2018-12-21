# https://leetcode.com/problems/count-of-smaller-numbers-after-self/
class BST:
    class bst_node:
        def __init__(self, val, parent=None):
            self.val = val
            self.size = 0
            self.right = None
            self.left = None
            self.parent = parent
        
    def __init__(self):
        self.root = None
    
#     def get(self, num):
#         node = self.root
        
#         while node != None and node.val != num:
#             if num < node.val:
#                 node = node.left
#             else:
#                 node = node.right
    
#         return node
    
    def add(self, num):
        node = self.root
        
        while node != None:
            prev = node
            prev.size += 1
            if num < node.val:
                node = node.left
            else:
                node = node.right
        
        if node == self.root:
            self.root = BST.bst_node(num)
        elif prev.val > num:
            prev.left = BST.bst_node(num, parent=prev)
        else:
            prev.right = BST.bst_node(num, parent=prev) 
        
        return

    def rank(self, num):
        node = self.root
        rank = 0
        while node != None:
            if num < node.val:
                node = node.left
            elif num > node.val:
                rank += 1
                if node.left != None:
                    rank += node.left.size + 1
                    
                node = node.right
            else:
                if node.left != None:
                    rank += node.left.size + 1
                break

        return rank
        
        
class Solution:
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        
        result = [0] * len(nums)
        i = len(nums) - 1
        bst = BST()
        
        while i != -1:
            cur_num = nums[i]
            bst.add(cur_num)
            result[i] = bst.rank(cur_num)
            i -=1
            
        return result
