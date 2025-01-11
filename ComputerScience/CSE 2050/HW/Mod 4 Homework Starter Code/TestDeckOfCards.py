import random
import DeckOfCards as Deck
print("starting tests")
random.seed(658) # Change the seed to generate a new order of cards
my_lst = []
suits = ['hearts', 'diamonds', 'clubs', 'spades']
values = ['two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine', 'ten',
'jack', 'queen', 'king', 'ace']
for suit in suits:
 for value in values:
    my_lst.append(value + ' of ' + suit)
random.shuffle(my_lst)

test_lst = ['purple', 'green', 'blue', 'yellow']
D = Deck.DeckOfCards(test_lst)
assert D.deal_bottom() == 'purple'          #Test deal_bottom()
assert D.deal_top() == 'yellow'             #Test deal_top()
assert D.is_cheating('yellow') == True      #Test is_cheating()
print(D.deal_top())
try:                                        #Runtime Test Try except Block
    D.deal_bottom()
except RuntimeError:
    print("RuntimeError Raised")



print("tests passed")