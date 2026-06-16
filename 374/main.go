package main

import "fmt"

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * func guess(num int) int;
 */

func guess(num int) int {
	pickedNumber := 6 // Example picked number for testing
	if num < pickedNumber {
		return 1
	} else if num > pickedNumber {
		return -1
	} else {
		return 0
	}
}

func guessNumber(n int) int {
	low := 1
	high := n

	for low <= high {
		mid := low + (high-low)/2
		result := guess(mid)

		if result == 0 {
			return mid
		}
		if result < 0 {
			high = mid - 1
		} else {
			low = mid + 1
		}
	}

	return -1
}

func main() {
	fmt.Println(guessNumber(10))
}
