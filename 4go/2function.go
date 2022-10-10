
package main

import ("fmt" 
		"time" 
)


func main() {

	fmt.Printf("\n começando \n\n")

	mostranumero(10)
	mostranumero(20)

	fmt.Printf("\n terminando \n\n")
}



func mostranumero(n int) {


	for k := 0; k < 5; k++ {
		fmt.Printf(" numero %d\n", n)
		time.Sleep(500 * time.Millisecond)
	}
}
