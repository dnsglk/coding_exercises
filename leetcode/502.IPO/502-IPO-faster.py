class Solution:
    def findMaximizedCapital(self, k, W, Profits, Capital):
        """
        :type k: int
        :type W: int
        :type Profits: List[int]
        :type Capital: List[int]
        :rtype: int
        """
        
        projects = sorted(zip(Capital,Profits), key=lambda p : p[0], reverse=False)
        # print(projects)
        heap = []
        implementedNum = 0
        activeProjects = 0
        
        while implementedNum != k or activeProjects < len(projects) or len(heap) > 0:
            
            if activeProjects < len(projects) and projects[activeProjects][0] <= W:
                # print('push {},{}'.format(projects[activeProjects][0], projects[activeProjects][1]))
                heapq.heappush(heap, -projects[activeProjects][1])
                activeProjects += 1
                continue

            # print('heap size {}'.format(len(heap)))
            if len(heap) == 0 or implementedNum == k:
                break
            
            # print('next {}'.format(heap[0]))
            W -= heapq.heappop(heap)
            # print('Project with profit {} and min cap {}'.format(proj.profit, proj.capital))
            implementedNum += 1           
            
            
        return W
