package main

import (
    "bufio"
    "fmt"
    "os"
    "strings"
    "reflect"
    "errors"
)

// Question 1

// Helper functions 

// isPrime function from https://www2.cs.sfu.ca/CourseCentral/383/tjd/go/primes.html
// Function to check if number is prime
func isPrime(n int) bool {
  if n < 2 {
    return false
  } else if n == 2 {
    return true
  } else if n%2 == 0 {
    return false
  } else { // n > 2
    d := 3
    for d*d <= n {
      if n%d == 0 {
        return false
      }
      d += 2
    } 
    return true
  } 
}

// Ideas taken from https://stackoverflow.com/questions/35972561/reverse-int-golang
// Function to reverse the digits in a number
func reverseInt (n int) int {
	reversedInt := 0
    for n > 0 {
        remainder := n % 10
        reversedInt = reversedInt*10 + remainder
        n /= 10
    }
    return reversedInt 
}

// Function used to check if the number is an emirp
func isEmirps (n int) bool {
	if ((!(n == (reverseInt (n)))) && (isPrime (n)) && (isPrime (reverseInt (n)))) {
		return true
	} else {
		return false
	}
}


// Main function

// Ideas taken from https://www2.cs.sfu.ca/CourseCentral/383/tjd/go/numstats2.html
func countEmirpsLessThan (n int) int {
	emirpsLst := []int{}
    for i := 1; i < n; i++ {
        if isEmirps(i) {
            emirpsLst = append(emirpsLst, i)
        }
    }
    return len(emirpsLst)
} 

// Question 2

// Ideas for reading file taken from https://www2.cs.sfu.ca/CourseCentral/383/tjd/go/numstats1.html
// Counts the number of times a word occurs in a document
func countwordCounts(filename string) (map[string]int, error) {

    file, err := os.Open(filename)

    defer file.Close()

    if err != nil {
        panic("Couldn't open file")
    }

	var wordCounts map[string]int = make(map[string]int)	
    
    scanner := bufio.NewScanner(file)
    for scanner.Scan() {
        line := scanner.Text()
     
        if err == nil {

        	// Get individual words
        	// Idea from https://stackoverflow.com/questions/13737745/split-a-string-on-whitespace-in-go
        	words := strings.Fields(line)
            
            // Idea taken from "Missing Keys" in https://www2.cs.sfu.ca/CourseCentral/383/tjd/go/go-maps.html
    		for _, word := range words {
       			_, present := wordCounts[word]
        		if present {
                	wordCounts[word] = wordCounts[word] + 1
        		} else {
            		wordCounts[word] = 1
        		}
        	}
        } 
    } 
    return wordCounts, err
}

// Question 3
// Ideas taken from https://www2.cs.sfu.ca/CourseCentral/383/tjd/go/types2.html

type Time24 struct {
    hour, minute, second uint8
}

func equalsTime24(a, b Time24) bool {
	if (a.hour == b.hour) && (a.minute == b.minute) && (a.second == b.second){
		return true
	} else {
		return false
	}
}

func lessThanTime24(a, b Time24) bool {
	switch {
	case (a.hour < b.hour):
		return true
	case (a.hour == b.hour) && (a.minute < b.minute):
		return true
	case (a.hour == b.hour) && (a.minute == b.minute) && (a.second < b.second):
		return true	
	default:
		return false
	}
}

// Time formating idea taken from https://stackoverflow.com/questions/30956224/go-how-to-format-number-digit-count
func (t Time24) String() string {
    return fmt.Sprintf("%02d:%02d:%02d", t.hour, t.minute, t.second)
}

func (t Time24) validTime24() bool {
	if (t.hour >= 0 && t.hour < 24) && (t.minute >= 0 && t.minute < 60) && (t.second >= 0 && t.second < 60){
		return true
	} else {
		return false
	}
}

// Error message idea from https://gobyexample.com/errors
func minTime24(times []Time24) (Time24, error) {
	if len(times) == 0 {
		return Time24{0, 0, 0}, errors.New("There are no Time24 objects in the provided slice")
	} else {

		var min Time24 = times[1]

		for _, i := range times {
			if (i.hour < min.hour) ||
			   ((i.hour == min.hour) && (i.minute < min.minute)) ||
			   ((i.hour == min.hour) && (i.minute == min.minute) && (i.second < min.second)) {
			   		min = i
			   }
		}
		return min, nil
	}
}

// Question 4

// Interface idea from https://www2.cs.sfu.ca/CourseCentral/383/tjd/go/types3.html
func linearSearch (x interface{}, lst interface{}) int {
	switch list := lst.(type) {
    case []string:
        for i, item := range list {
        	// Use of reflect.Typeof(x) to find type of x and item from https://stackoverflow.com/questions/6372474/how-to-determine-an-interface-values-real-type
            if reflect.TypeOf(x) != reflect.TypeOf(item) {
            	panic("Type of target item is not the same type as the elements in list")
            } else if item == x {
	            return i
	        }
        }
    case []int:
        for i, item := range list {
        	// Use of reflect.Typeof(x) to find type of x and item from https://stackoverflow.com/questions/6372474/how-to-determine-an-interface-values-real-type
            if reflect.TypeOf(x) != reflect.TypeOf(item) {
            	panic("Type of target item is not the same type as the elements in list")
            } else if item == x {
	            return i
	        }
        }
	}
	return -1
}

// Question 5

// Helper function used to generate the bit sequences 
func genBitSeq(bitSeqArr [][]int, n int) [][]int {
	if n == 0 {
		return bitSeqArr
	} else {
		if len(bitSeqArr) == 0 {
			bitSeqArr = append (bitSeqArr, []int{0})
			bitSeqArr = append (bitSeqArr, []int{1})
			return(genBitSeq(bitSeqArr, n-1))
		} else {
			tempBitSeq := [][]int{}	
			for i := 0;  i < len(bitSeqArr); i++ {
				a1 := append (bitSeqArr[i], 0)
				a2 := append (bitSeqArr[i], 1)
				tempBitSeq = append (tempBitSeq, a1)
				tempBitSeq = append (tempBitSeq, a2)
			}
			bitSeqArr = tempBitSeq
			return(genBitSeq(bitSeqArr, n-1))
		}
	}
}

// Main function

func allBitSeqs(n int) [][]int {
	bitSeq := [][]int{}

	return genBitSeq(bitSeq, n)
}


func main() {
	fmt.Println(linearSearch(5, []int{4, 2, -1, 5, 0}))
	fmt.Println(linearSearch(3, []int{4, 2, -1, 5, 0}))
	// fmt.Println(linearSearch("up", []int{4, 2, -1, 5, 0}))
	fmt.Println(linearSearch("egg", []string{"cat", "nose", "egg"}))
	fmt.Println(linearSearch("up", []string{"cat", "nose", "egg"}))
	// fmt.Println(linearSearch(3, []string{"cat", "nose", "egg"}))

	results, err := countwordCounts("sample.txt")
	fmt.Println(results,err)
	fmt.Println(allBitSeqs(1))
	fmt.Println(allBitSeqs(2))

	fmt.Println(allBitSeqs(3))
	fmt.Println(allBitSeqs(0))

	linearSearch(5, []int{4, 2, -1, 5, 0})
	a := Time24{hour: 23, minute: 53, second: 40}
	a1 := Time24{hour: 23, minute: 54, second: 40}
	b := Time24{hour: 5, minute: 39, second: 8}
	// d := Time24{hour: 6, minute: 39, second: 8}
	// c := Time24{hour: 7, minute: 39, second: 8}

	fmt.Println(equalsTime24(a,a1))
	fmt.Println(lessThanTime24(a,a1))
	fmt.Println(equalsTime24(a,b))

	var arr = []Time24{{hour: 23, minute: 55, second: 40},{hour: 20, minute: 55, second: 40},{hour: 3, minute: 5, second: 4},{hour: 23, minute: 55, second: 40}}
	var arr2 = []Time24{}

	fmt.Println(a)  // "05:39:08"
	fmt.Println(minTime24(arr))
	fmt.Println(minTime24(arr2))
	fmt.Println(linearSearch("book", []string{"cat", "nose", "egg"}))
	fmt.Println(countEmirpsLessThan(100))
    fmt.Println("Hello from Go!")
}