def string_lengths(string_list):
    length_list = [len(s) for s in string_list]
    return string_list, length_list

def main():
    user_input = input("Enter some words >")
    words_list = user_input.split(', ')
    result = string_lengths(words_list)
    print(result[0])
    print(result[1])