
package main

import ("fmt" 
	"time" 
	"math/rand"
)


//thread 1
func main() {

	rand.Seed(time.Now().UTC().UnixNano())
	
	fmt.Printf("\n começando \n")

	c := make (chan int) 
	
	//thread 2
	go func() {						//funcao anonima
		i := 0
		for {		 
			c  <- rand.Intn(1000) 	//coloca o valor no canal
			i ++
			time.Sleep(1 * time.Second)
		}
	} ()


	for x := range c  { 			//retira o valor do canal					
		fmt.Printf("\n numero retirado do chan %d\n", x)
	}
	
	fmt.Printf("\n terminando \n\n")
}




