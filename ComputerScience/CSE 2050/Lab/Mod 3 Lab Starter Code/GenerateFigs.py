from matplotlib import pyplot as plt        # import plotting funcs
from TimeFunctions import  time_function    # import the time function you will write
from Duplicates import has_duplicates_1 , has_duplicates_2     # import the has_duplicates functions you are interested in

# All code below is included as a demo. Feel free to change any of it.

##### Initialize datasets
# Pick 3 x-values
x = [100, 500, 1000]
x = [i for i in range (1001) if (i % 50) == 0]



##### Measure the running times
# Generate 3 corresponding y-values
y1 = []
for n in x:
    L = [i for i in range(n)] # Worst case: A list with no duplicates
    y1.append(time_function(has_duplicates_1, L)) # append running time to y

y2 = []
for n in x:
    L = [i for i in range(n)] # Worst case: A list with no duplicates
    y2.append(time_function(has_duplicates_2, L)) # append running time to y

##### Plot datasets
plt.figure()                                                        # create a new figure
plt.scatter(x, y1, c='g', marker='.', label='has_duplicates_1')     # add scatter plot to figure
plt.scatter(x, y2, c='deepskyblue', marker='*', label='has_duplicates_2') # scatter plot 
plt.ylabel("running time (s)")                                      # label y axis
plt.xlabel("number of iterations (n)")
plt.xlim(.1, 1000)
plt.ylim(0, .35)                                                         # label x axis
plt.legend()                                                        # add legend to figure
#plt.show()                                                          # show figure on local computer
plt.savefig('dups.png')                                          # save figure

# Note: You can either use plt.show() or plt.savefig(). Using both does not work.



