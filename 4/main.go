package main

import "log"

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {

	l1 := len(nums1)
	l2 := len(nums2)
	n := l1 + l2
	var res []int

	if l1 == 0 {
		res = nums2
	} else if l2 == 0 {
		res = nums1
	} else {
		ii := 0
		jj := 0
		for i := 0; i < n; i++ {
			if ii >= l1 || (jj < l2 && nums1[ii] > nums2[jj]) {
				res = append(res, nums2[jj])
				jj++
			} else if jj >= l2 || (ii < l1 && nums1[ii] <= nums2[jj]) {
				res = append(res, nums1[ii])
				ii++
			}
		}
	}

	if len(res)%2 == 1 {
		return float64(res[len(res)/2])
	} else {
		return (float64(res[len(res)/2]) + float64(res[len(res)/2-1])) / 2
	}
}

func main() {
	log.Println(findMedianSortedArrays([]int{1, 3}, []int{2, 4}))
}
