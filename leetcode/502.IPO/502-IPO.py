class Project:

    def __init__(self, capital, profit):
        self.capital = capital
        self.profit = profit
        
    def __gt__(self, other):
        return self.profit > other.profit

    def __str__(self):
        return 'P:{},C:{}'.format(self.profit,self.capital)
    
class Heap:
    
    def __init__(self):
        self.data = []
        
    def add(self, newVal):
        self.data.append(newVal)
        self.__heapify__(len(self.data)-1)
        
    def pop(self):
        if len(self.data) == 0:
            return
        
        topVal = self.data[0] 
        self.data[0] = self.data[-1]
        self.data.pop()
        
        idx = 0
        lIdx = 2 * idx + 1 
        rIdx = 2 * idx + 2
        
        while lIdx < len(self.data):
            swapRight = rIdx < len(self.data) and \
                self.data[rIdx] > self.data[idx] and \
                self.data[rIdx] > self.data[lIdx]   
            swapLeft = self.data[lIdx] > self.data[idx]
            
            if swapRight:
                self.data[idx], self.data[rIdx] = self.data[rIdx], self.data[idx] 
                idx = rIdx
            elif swapLeft:
                self.data[idx], self.data[lIdx] = self.data[lIdx], self.data[idx] 
                idx = lIdx
            else:
                break
            
            lIdx = 2 * idx + 1
            rIdx = 2 * idx + 2               
        
        return topVal
    
    def size(self):
        return len(self.data)
    
    def top(self):
        return self.data[0]
    
    def __heapify__(self, idx):
        parentIdx = (idx-1)//2
        while idx != 0 and self.data[idx] > self.data[parentIdx]:
            self.data[idx],self.data[parentIdx] = self.data[parentIdx], self.data[idx] 
            idx = parentIdx
            parentIdx = (idx-1)//2

class Solution:
    def findMaximizedCapital(self, k, W, Profits, Capital):
        """
        :type k: int
        :type W: int
        :type Profits: List[int]
        :type Capital: List[int]
        :rtype: int
        """
        projects = [Project(Capital[i],Profits[i]) for i in range(len(Profits))]
        projects.sort(key=lambda p : p.capital,reverse=False)
                    
        heap = Heap()
        implementedNum = 0
        activeProjects = 0
        
        while implementedNum != k or activeProjects < len(projects):
            
            if activeProjects < len(projects) and projects[activeProjects].capital <= W:
                heap.add(projects[activeProjects])
                activeProjects = activeProjects + 1
                continue

            if heap.size() == 0 or heap.top().capital > W or implementedNum == k:
                break
            
            # print('Heap size {}, W {}'.format(heap.size(),W))
            proj = heap.pop()
            # print('Project with profit {} and min cap {}'.format(proj.profit, proj.capital))
            implementedNum = implementedNum + 1           
            W = W + proj.profit
            
        return W

if __name__ == '__main__':
    
    testData = open("test_data_31.txt",'r')
    k = int(testData.readline())
    W = int(testData.readline())

    profits = testData.readline().split(',')
    profits[0] = profits[0].replace('[','')
    profits[-1] = profits[-1].replace(']\n','')
    profits = [int(c) for c in profits]

    capital = testData.readline().split(',')
    capital[0] = capital[0].replace('[','')
    capital[-1] = capital[-1].replace(']\n','')
    capital = [int(c) for c in capital]
    testData.close()
    
    solution = Solution()
    print(solution.findMaximizedCapital(k, W, profits, capital))
