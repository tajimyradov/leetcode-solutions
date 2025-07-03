package main

/*
3304. Find the K-th Character in String Game I

Alice and Bob are playing a game. Initially, Alice has a string word = "a".

You are given a positive integer k.

Now Bob will ask Alice to perform the following operation forever:

Generate a new string by changing each character in word to its next character in the English alphabet, and append it to the original word.
For example, performing the operation on "c" generates "cd" and performing the operation on "zb" generates "zbac".

Return the value of the kth character in word, after enough operations have been done for word to have at least k characters.

Note that the character 'z' can be changed to 'a' in the operation.


*/

func kthCharacter(k int) byte {
	if k <= 0 {
		return ' '
	}

	word := "a"
	for len(word) < k {
		newWord := ""
		for _, c := range word {
			if c == 'z' {
				newWord += "a"
			} else {
				newWord += string(c + 1)
			}
		}
		word += newWord
	}

	return word[k-1]
}

func main() {
	k := 5
	result := kthCharacter(k)
	println("The", k, "th character is:", string(result))
}
