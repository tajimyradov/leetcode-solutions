package main

import "fmt"

func possibleStringCount(word string) int {
	var res string
	last := ""

	word += " "
	count := 0

	for _, c := range word {
		if string(c) != last {
			res += string(c)
			last = string(c)
		} else {
			count++
		}
	}

	return count + 1
}

func main() {
	fmt.Println(possibleStringCount("abbcccc"))
}
