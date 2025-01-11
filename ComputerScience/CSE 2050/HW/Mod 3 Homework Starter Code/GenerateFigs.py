# from matplotlib import pyplot as plt        # import plotting funcs
# from TimeFunctions import  time_function    # import the time function you will write
# from FindMissing import *   # import the has_duplicates functions you are interested in

# # All code below is included as a demo. Feel free to change any of it.
# N = 1000
# my_list = list(range(N + 1))
# random.seed()
# random.shuffle(my_list)
# my_list.pop()

##### Initialize datasets
# Pick 3 x-values
# x = [i for i in range (1000001) if (i % 50000) == 0]
# def help(N):
#     my_list = list(range(N + 1))
#     random.seed()
#     random.shuffle(my_list)
#     my_list.pop()
#     return my_list


##### Measure the running times
# Generate 3 corresponding y-values
# y1 = []
# for n in x:
#     L = help(n) # Worst case: A list with no duplicates
#     y1.append(time_function(find_missing_3, L)) # append running time to y

# y2 = []
# for n in x:
#     L = help(n) # Worst case: A list with no duplicates
#     y2.append(time_function(find_missing_4, L)) # append running time to y

##### Plot datasets
# plt.figure()                                                        # create a new figure
# plt.scatter(x, y1, c='r', marker='2', label='find_missing_3')     # add scatter plot to figure
# plt.scatter(x, y2, c='lime', marker='d', label='find_missing_4') # scatter plot 
# plt.ylabel("running time (s)")                                      # label y axis
# plt.xlabel("number of iterations (n)")
# plt.xlim(.1, 1000000)                                                         # label x axis
# plt.legend()                                                       # add legend to figure
# #plt.show()                                                          # show figure on local computer
# plt.savefig('find_missing_34.png')                                          # save figure

# Note: You can either use plt.show() or plt.savefig(). Using both does not work.

