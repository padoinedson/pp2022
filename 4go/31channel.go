
package main

import ("fmt" 
	"time" 
	"math/rand"
)


func main() {

	rand.Seed(time.Now().UTC().UnixNano())
	
	fmt.Printf("\n começando \n")

	c := make (chan int) 
	
	go func() {
		i := 0
		for {		 
			c  <- rand.Intn(1000) 
			i ++
			time.Sleep(1 * time.Second)
		}
	} ()


	for x := range c  { 								
		fmt.Printf("\n numero retirado do chan %d\n", x)
	}
	
	fmt.Printf("\n terminando \n\n")
}




