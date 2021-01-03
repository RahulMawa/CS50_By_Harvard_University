from cs50 import get_string

text = get_string("Text: ")
numLetters = 0
numWords = 1
numSentences = 0
length = len(text)

#Counting the num of lettters, words and sentences
for i in range(length):
    #Count of number of letters in the text
    if ord(text[i]) >= 65 and ord(text[i]) <= 122:
        numLetters += 1
        
    if ord(text[i]) >= 91 and ord(text[i]) <= 96:
        numLetters -= 1
    
    #Count for number of words in the text
    if ord(text[i]) == 34 or ord(text[i]) == 40 or ord(text[i]) == 32 and ord(text[i+1]) >= 65 and ord(text[i+1]) <= 122:
        numWords += 1
    
    #Count of number of sentences in the text
    if ord(text[i]) == 33 or ord(text[i]) == 46 or ord(text[i]) == 63:
        numSentences += 1

#Calculating the index
L = float((numLetters * 100) / numWords)
S = float((numSentences * 100) / numWords)
index = round((0.0588 * L) - (0.296 * S) - 15.8)

#printing out result
if index <= 1:
    print("Before Grade 1")

elif index > 16:
    print("Grade 16+")

else:
    print(f"Grade {index}")

print(f"{numLetters} , {numWords}, {numSentences}")