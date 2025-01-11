import sys
import imagematrix

def flatten(l, a=None):
    # flattens a nested list of lists, recursively.
    if a is None:
        a = []
    for i in l:
        if isinstance(i, list):
            flatten(i, a)
        else:
            a.append(i)
    return a

class ResizeableImage(imagematrix.ImageMatrix):
    def best_seam(self, dp=True):
        # Calculate each energy once.
        energies = {}
        for i in range(self.width):
            for j in range(self.height):
              energies[i,j] = self.energy(i,j)

        if dp:
            return self.best_seam_dp(energies)
        else:
            return self.best_seam_naive(energies)

        

    def best_seam_dp(self, energies):
        dp = {}
        for i in range(self.width):
            dp[i,0] = energies[i,0]

        backpointer = {}
        for j in range(1, self.height):
            for i in range(self.width):
                # Down
                dp[i,j] = energies[i,j] + dp[i,j-1]
                backpointer[i,j] = 0
                # Down-left
                if i != 0:
                    if dp[i,j] > energies[i,j] + dp[i-1,j-1]:
                        dp[i,j] = energies[i,j] + dp[i-1,j-1]
                        backpointer[i,j] = -1
                # Down-right
                if i != self.width-1:
                    if dp[i,j] > energies[i,j] + dp[i+1,j-1]:
                        dp[i,j] = energies[i,j] + dp[i+1,j-1]
                        backpointer[i,j] = 1

        # Find best pixel in bottom row.
        best_value = sys.maxint
        index = None
        for i in range(self.width):
            if dp[i,self.height-1] < best_value:
                best_value = dp[i,self.height-1]
                index = i

        # Follow backpointers up.
        seam = []
        for j in range(self.height-1, 0, -1):
            seam.append((index, j))
            index = index + backpointer[index,j]
        seam.append((index, 0))

        return seam

    def best_seam_naive(self, energies):
        # naive as can be: use depth-first search to generate an exhaustive list 
        # of (energy, endpoint) tuples, and then find the best one 
        seams = []
        start_row = self.height-1
        for i in range(self.width):
            seams.extend(self.dfs(i, start_row, energies, energies[i,start_row]))
        return min(seams)

    def dfs(self, i, j, energies, acc):
        
        if j == 0:
            return [(energies[i,j], i, j)]
        # base case, return a singleton list with a 3-tuple of energy, i, j
        if i == 0:
            # left edge
            children = [self.dfs(iis, j-1, energies, acc + energies[iis, j-1]) for iis in [i, i+1]]
        elif i == self.width-1:
            # right edge
            children = [self.dfs(iis, j-1, energies, acc + energies[iis, j-1]) for iis in [i-1, i]]
        else:
            # general case
            children = [self.dfs(iis, j-1, energies, acc + energies[iis, j-1]) for iis in [i-1, i, i+1]]
        return flatten(children)


    def remove_best_seam(self):
        self.remove_seam(self.best_seam())
