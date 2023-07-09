class Solution(object):
    def alienOrder(self, words):
        map = {}
        letters = [0 for i in range(26)]  
        for i in range(len(words)):
            for j in range(len(words[i])):
                key=ord(words[i][j])-ord('a')
                letters[key]=0
                map[key]=set()
        
        for i in range(len(words)-1):
            word1 = words[i]
            word2 = words[i+1]
            idx = 0
            for j in range(min(len(word1),len(word2))):
                if(word1[j]!=word2[j]):
                    key1 = ord(word1[j])-ord('a')
                    key2 = ord(word2[j])-ord('a')
                    count = letters[key2]
                    if(key2 not in map[key1]):
                        letters[key2] =count+1
                        map[key1].add(key2)
                    break
                elif j == min(len(word1), len(word2)) - 1 and len(word1) > len(word2):
                    return ""
        dictionary = collections.deque()
        res = ''
        for i in range(26):
            if(letters[i]==0 and i in map):
                dictionary.appendleft(i)
        
        while(len(dictionary)!=0):
            nextup = dictionary.pop()
            res+=(chr(nextup+ord('a')))
            greaterSet = map[nextup]
            for greater in greaterSet:
                letters[greater]-=1
                if(letters[greater]==0):
                    dictionary.appendleft(greater)
        if(len(map)!=len(res)):
            return ""
        return res