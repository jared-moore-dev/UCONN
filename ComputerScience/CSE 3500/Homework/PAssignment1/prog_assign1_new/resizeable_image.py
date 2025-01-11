import imagematrix

class seam():
    def __init__(self, energy, parent=None):
        self.energy = energy
        self.parent = parent
    def __lt__(self, other):
        self.energy < other.energy
class seam_r():
    def __init__(self, energy = 0, array=[]):
        self.energy = energy
        self.array = array
    def __lt__(self, other):
        self.energy < other.energy

class ResizeableImage(imagematrix.ImageMatrix):
    def best_seam(self, dp=True):
        x = self.width
        y = self.height

        energy = {}
        # Initialize energy table
        for j in range(y):
            for i in range(x):
                energy[i,j] = self.energy(i,j)
        if dp == True:
            # Create DPT
            dpt = {}
            for i in range(x):
                dpt[i, y-1] = seam(energy[i,y-1])
            
            for j in reversed(range(y-1)):
                for i in range(x):
                    # Case 1: Left Edge
                    if(i==0):
                        stay = energy[i, j+1]
                        right = energy[i + 1, j + 1]
                        minx = min(stay, right)
                        # Evaluate minx
                        if (minx == stay):
                            dpt[i,j] = seam((energy[i,j]+minx), 0)
                        elif(minx == right):
                            dpt[i,j] = seam((energy[i,j]+minx), 1)
                    # Case 2: Right Edge 
                    elif(i == x-1):
                        stay = energy[i,j+1]
                        left = energy[i-1,j+1]
                        minx = min(stay, left)
                        # Evaluate minx
                        if(minx == left):
                            dpt[i,j] = seam((energy[i,j]+minx), -1)
                        elif(minx == stay):
                            dpt[i,j] = seam((energy[i,j]+minx), 0)
                    else:
                        left = energy[i-1, j+1]
                        stay = energy[i,j+1]
                        right = energy[i+1, j+1]
                        minx = min(stay,left,right)
                        if(minx == left):
                            dpt[i,j] = seam((energy[i,j]+minx), -1)
                        elif(minx == stay):
                            dpt[i,j] = seam((energy[i,j]+minx), 0)
                        else:
                            dpt[i,j] = seam((energy[i,j]+minx), 1)
            # Find first min 
            lastrow = []
            for i in range(x):
                lastrow.append(dpt[i,0])
            minx = min(lastrow, key=lambda x:x.energy)
            minxpos = lastrow.index(minx)

            bestseam = []
            bestseam.append((minxpos,0))

            for j in range(1,y):
                if(minx.parent is None):
                    bestseam.append((minxpos, j))
                elif(minx.parent == -1):
                    minxpos = minxpos - 1
                    minx = dpt[minxpos, j]
                    bestseam.append((minxpos,j))
                elif(minx.parent == 0):
                    minxpos = minxpos
                    minx = dpt[minxpos,j]
                    bestseam.append((minxpos,j))
                else:
                    minxpos = minxpos + 1
                    minx = dpt[minxpos,j]
                    bestseam.append((minxpos,j))
            return bestseam

        if dp == False:
            result = []
            def find_base(i, j, seam_r):
                #Base case
                if j == y:
                    bs = []
                    return self.energy(i,j)
                #Edge left
                elif i == 0:
                    bs.append(min())
                    return energy(x,y)
                
            for w in range(x):
                rec_f(w, y, seam_r)
                result[w] = x
            

    def remove_best_seam(self):
        self.remove_seam(self.best_seam())            
