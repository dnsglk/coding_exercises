# https://www.hackerrank.com/challenges/is-binary-search-tree/problem

""" Node is defined as
class node:
  def __init__(self, data):
      self.data = data
      self.left = None
      self.right = None
"""
def check_binary_search_tree_(root):
    if root == None:
        return True
    
    stack = []
    #find smallest first
    node = root
    while node.left != None:
        stack.append(node)
        node = node.left
         
    while len(stack) != 0 or node != None:
        # get next
            
        if node.right != None:
            nxt = node.right
                   
            while nxt.left != None:
                stack.append(nxt)
                nxt = nxt.left
                               
        else:    
            if len(stack) != 0:
                nxt = stack.pop()
                
        if node == nxt:
            break
            
        # compare
        if node.data >= nxt.data:
            return False
        node = nxt

    
    return True

