import imagematrix
from PIL import Image

class ResizeableImage(imagematrix.ImageMatrix):
  def best_seam(self, dp=True):
    # initialize a dynamic programming table where w == width, and h == hight
    dpt = []
    bestseam = []
    width = self.width()
    height = self.height()
    # Populate the table with a list of h # of [] and w # of 0,....,0
    for h in range(height):
      # Make h nested arrays
      temp_list = []
      # populate array's with w 0's
      for w in range(width):
        temp_list.append(0)
      # Append these to dpt
      dpt.append(temp_list)
    print(dpt)

    # Populate the DPT with data
    for h in range(0,height-1):
      for w in range(0,width):
        # Fill the table with the min values
        if (w==0):
          dpt[h][w] = min(dpt[h-1][w], dpt[h-1][w+1]) + self.energy(h,w)
        elif(w==width):
          dpt[h][w] = min(dpt[h-1][w], dpt[h-1][w-1]) + self.energy(h,w)
        else:
          dpt[h][w] = min(dpt[h-1][w-1], dpt[h-1][w], dpt[h-1][w+1]) + self.energy(h,w)
    # calculate the best path (min seam)
    h == height
    while(h > 0):
        if (h==height):
          # On first itteration
          wi = dpt[h].index(min(dp[h]))
          hi = h
          curmin = dpt[hi][wi]
          bestseam.append((hi, wi))
        elif(wi==0):
          if(dpt[hi-1][wi] > dpt[hi-1][wi+1]):
            hi = h-1
            wi = w+1
            curmin = dpt[hi][wi]
            bestseam.append((hi,wi))
          elif(dpt[hi-1][wi] < dpt[hi-1][wi+1]):
            hi = h-1
            wi = wi
            curmin = dpt[hi][wi]
            bestseam.append((hi, wi))
        elif(wi==width): 
          if(dpt[hi-1][wi] > dpt[hi-1][wi-1]):
            hi = h-1
            wi = w-1
            curmin = dpt[hi][wi]
            bestseam.append((hi,wi))
          elif(dpt[hi-1][wi] < dpt[hi-1][wi-1]):
            hi = h-1
            wi = wi
            curmin = dpt[hi][wi]
            bestseam.append((hi, wi))
        else:
          nexti = index(min(dpt[hi-1][wi], dpt[hi-1][wi+1], dpt[hi-1][wi-1]))
          if(dpt[hi-1][wi] < dpt[hi-1][wi+1] and dpt[hi-1][wi] < dpt[hi-1][wi-1]):
            hi = h-1
            wi = wi
            curmin = dpt[hi][wi]
            bestseam.append((hi,wi))
          elif(dpt[hi-1][wi-1] < dpt[hi-1][wi] and dpt[hi-1][wi-1] < dpt[hi-1][wi+1]):
            hi = hi-1
            wi = wi-1
            curmin = dpt[hi][wi]
            bestseam.append((hi,wi))
          elif(dpt[hi-1][wi+1] < dpt[hi-1][wi] and dpt[hi-1][wi+1] < dpt[hi-1][wi-1]):
            hi = hi-1
            wi = wi+1
            curmin = dpt[hi][wi]
            bestseam.append((hi,wi))
    print(bestseam)
    print("done")
    return bestseam


    def remove_best_seam(self):
        self.remove_seam(self.best_seam())
