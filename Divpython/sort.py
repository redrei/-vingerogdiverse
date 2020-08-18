import time as t
#a function to sort all the strings in a file with the filepath as a parameter
def sortbylength(filepath):
    #a list to contain the strings in a file
    readlist = []
    #opening the file using with open, as it closes the inputstream automatically
    with open(filepath, 'r') as File:
        #adding all the words in the file as individual strings using split, and finding words divided by lines by replacing \n with whitespace
        readlist = File.read().replace("\n", " ").split(" ")
    #removes empty strings from the list, as these are pointless to sort
    while("" in readlist):
        readlist.remove("")
    #creating a list to contain the sorted strings
    outlist = []
    #a counter to hold the expected length of the strings
    i = 0
    #the while loop checks whether the function is finished, which it will be when the readlist has no more strings
    while(len(readlist) != 0):
        #a temporary list to hold all the strings of the same length, which will be sorted lexicographically
        lexicographiclist = []
        #adding all the strings in the inputlist that have equal length to 'i' to the lexicographic list, this is a form of radix sort which i found fitting.
        for string in readlist:
            if(len(string) == i):
                lexicographiclist.append(string)
        #removing the copied strings from the readlist for higher efficency in later for loops of the read list
        for string in lexicographiclist:
            readlist.remove(string)
        #increasing the length of the strings that the function is looking for
        i += 1
        #saying that the loop should continue if there is no strings in this instance of the lexicographiclist, in which case renders everything afterwards pointless
        if(len(lexicographiclist) == 0):
            continue
        #if the length of the lexicographiclist is more than one string it will need to be sorted lexicographically
        if(len(lexicographiclist) > 1):
            #a temporary list to hold the lexicographically sorted list
            sortedlexicographiclist = []
            #loops as long as there is something to sort in the list, the sort algortihm used here is a selection sort,
            # finding the lowest lexicographical value and placing it first opposed to finding the highest value and placing it last which the interavtivepython.org website proposed
            while len(lexicographiclist) != 0:
                #taking the first string in the list and uses it as base smallest string, it doesnt really matter which string is used, only that it is in the list and is not already sorted
                smalleststring = lexicographiclist[0]
                #loops through all the strings in the list
                for string in lexicographiclist:
                    #python supports lexicraphic comparisons so that i can compare them almost directly, i do not ignore case due to it being lexicographic sorting and not alphabetical sorting,
                    #the program doesn't take numbers into account either, again because of it being a lexicographically and not alphabetical sorted list
                    if(string < smalleststring):
                        #updates the smallest string
                        smalleststring = string
                #appends the smallest string found in this loop to the sortedlexicographiclist
                sortedlexicographiclist.append(smalleststring)
                #removes the string from the lexicographiclist to avoid duplicates and to attain higher efficiency
                lexicographiclist.remove(smalleststring)
            #updates the lexicographiclist to now contain the sorted version of the list
            lexicographiclist = sortedlexicographiclist
        #extends the outlist with the sorted lexicographiclist for this iteration of the while-loop
        outlist.extend(lexicographiclist)
    #the program is now finished and returns the strings sorted by length
    return outlist

#runs if this is the main file
if __name__ == "__main__":
    #example of how this could be achieved using the sort method
    #list = []
    #path = input("filepath: ")
    #with open(path, 'r') as file:
    #    list = file.read().replace("\n", "").split(" ")
    #while("" in list):
    #   list.remove("")
    #print(sorted(list, key=lambda x: (len(x), x)))
    ilk = input("filepath: ")
    hai = t.time()
    sortbylength(ilk)
    print(str(t.time()-hai))