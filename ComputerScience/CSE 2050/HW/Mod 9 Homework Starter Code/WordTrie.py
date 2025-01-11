# A class for trie nodes
class TrieNode:
    # Initializes a trie node
    def __init__(self):
        # Initialize attributes
        self._children = {}
        self._is_word = False

    # adds a word to the Trie (only used during initialization)
    def add_word(self, word):
        #Basecase (if len(word) == 1)
        if len(word) == 0:
            return None
        if word[0] not in self._children:
            self._children[word[0]]=TrieNode()
        if len(word) == 1:
            self._children[word[0]]._is_word = True
        #reccoursive call
        self._children[word[0]].add_word(word[1:])
        
            



    # Find the node with a given prefix
    def find_node(self, prefix):
        if len(prefix) == 0: 
            return self
        if prefix[0] in self._children:
            return self._children[prefix[0]].find_node(prefix[1:])


    # Generate all the words with the given prefix
    def get_words(self, prefix):
        if self._is_word:
            yield prefix 
        for letter, Trienode in self._children.items():
            yield from Trienode.get_words(prefix + letter)
        


    # Return the number of words in the trie
    def get_nb_words(self):
        return len([i for i in self.get_words("")])
            
            
            
            



# A class that implements a prefix tree for words
# This is the "public facing" interface - users interact with WordTrie directly
# TrieNode is private. Users do not directly use that class, but WordTrie can.
# Note that this class is defined for you - you do not need to make any changes.
class WordTrie:
    def __init__(self, words):
        self._root = TrieNode()                         # root node is empty
        for word in words: self._root.add_word(word)    # add all words to trie

    # Generate all the words with a given prefix
    def get_words(self, prefix=''):
        node = self._root.find_node(prefix)     # Locate the node corresponding to the given prefix

        if node is not None:                
            yield from node.get_words(prefix)   # Yield from the generator defined for trie nodes

    # Generate all the words in the prefix tree
    def __iter__(self):
        yield from self.get_words() # Yield from the more general generator

    # Return the number of words with a given prefix
    def get_nb_words(self, prefix=''):
        node = self._root.find_node(prefix)                   # Locate the node corresponding to the given prefix
        return node.get_nb_words() if node is not None else 0 # Delegate the work to the node class
        
    # Return the number of words in the prefix tree
    def __len__(self):
        return self._root.get_nb_words()    # Delegate the work to the node class

    # Implement the in operator: Returns True if word is in the prefix tree
    def __contains__(self, word):
        node = self._root.find_node(word)           # Locate the node corresponding to the given prefix            
        return (node is not None) and node._is_word  # Return true if the node exists and is a word

