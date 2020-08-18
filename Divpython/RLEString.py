import re
#defining the class RLEString
class RLEString(object):
    #defining the constructor
    def __init__(self, myString):
        #using an assert to raise an exception if the string given to the constructor doesnt contain only alphabetical characters checked through regex, first tried isalpha() but it doesn't discern between a-z and a-å, using assert saves an if sentence
        assert(re.match('^[a-zA-Z]+$', myString)), "'" + myString + "' contains non alphabetical characters" 
        #Sets the object variables, both are private variables
        self.__myString = myString
        self.__compressionstate = False

    #defines the compression method
    def compress(self):
        #asserts that the string is uncompressed
        assert(not(self.__compressionstate)), "the string is already compressed"
        #a temporary variable to hold the unfinished compressed string
        compressedstring = ""
        #a list for storing and counting the consecutive letters
        charlist = []
        #goest through all the letters, and checks whether they match the last letter, is the first letter to be added or if it is a new letter
        for char in self.__myString:
            if(len(charlist) == 0 or charlist[0] == char):
                #adds to the list for counting
                charlist.append(char)
            else:
                #if it didn't match the last letter then the number of consecutive equal letters is added to the compressed string followed by the letter, then the list is "restarted" with the new letter
                compressedstring += str(len(charlist)) + charlist[0]
                charlist = [char]
        #because the if else doesn't add the last character to the compressed string due to the character not changing, it is coded here
        compressedstring += str(len(charlist)) + charlist[0]
        #updates the mystring and compressionstate variables
        self.__myString = compressedstring
        self.__compressionstate = True
    
    #defines the decompress method
    def decompress(self):
        #asserts that the string is compressed
        assert(self.__compressionstate), "the string is not compressed"
        #temporary variable to hold the unfinished decompressed string
        uncompressedstring = ""
        #an int to hold the number of consecutive letters
        curnum = 0
        #goes through the compressed string
        for i in range(0, int(len(self.__myString))):
            #fetching the number and letter from the compressed string
            #if the character is a number it is added to the curnum
            if((self.__myString[i].isnumeric())):
                if(curnum == 0):
                    curnum = int(self.__myString[i])
                else:
                    #if there is already a letter in curnum the new number is added as the lower number such that if it already was a '2' as the old number and the new is '3' the new number would become '23'
                    curnum = int(str(curnum) + self.__myString[i])
            else:
                #if it isn't a number it is a letter
                curchar = self.__myString[i]
                #adding the letter to the uncompressed string curnum number of times
                uncompressedstring += curchar * int(curnum)
                #setting curnum back to 0 for the next letter
                curnum = 0
        #updating the variables
        self.__myString = uncompressedstring
        self.__compressionstate = False
    def iscompressed(self):
        #returns the boolean compressionstate
        return self.__compressionstate
    def __str__(self):
        #returns the string
        return self.__myString

if (__name__ == "__main__"):
    obj = RLEString("AAAAAAAAAAAA")
    print(obj.iscompressed())
    print(obj.__str__())
    obj.compress()
    print(obj.iscompressed())
    print(obj.__str__())
    obj.decompress()
    print(obj.iscompressed())
    print(obj.__str__())