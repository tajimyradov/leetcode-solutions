package main

import "fmt"

func generate(numRows int) [][]int {
	var res [][]int
	var old []int = []int{1}
	// res=append(res,old)

	for numRows > 0 {
		res = append(res, old)
		var n []int = []int{1}

		for i := 0; i < len(old)-1; i++ {
			n = append(n, old[i]+old[i+1])
		}

		n = append(n, 1)

		old = n

		numRows--
	}

	return res

}

func main() {
	res := generate(5)
	fmt.Println(res)
}
