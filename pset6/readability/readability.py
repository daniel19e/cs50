text = input("Text: ")
num_words = num_sentences = num_letters = 0

for i in range(len(text)):
    if text[i].isalpha():
        num_letters += 1
    if ((i == 0 and text[i] != ' ') or (i != len(text) - 1 and text[i] == ' ' and text[i + 1] != ' ')):
        num_words += 1
    if text[i] == "." or text[i] == "?" or text[i] == "!":
        num_sentences += 1

L = num_letters / num_words * 100
S = num_sentences / num_words * 100
index = round(0.0588 * L - 0.296 * S - 15.8)

if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print(f"Grade {index}")