
package main

import ("fmt" 
	"time" 
	"math/rand"
)

func calcula(id int, c chan int){
	for x := range c  { 								
		fmt.Printf("\n thread %d retirando numero %d do canal\n", id, x)
		time.Sleep(1 * time.Second)
	}	
}


func main() {

	rand.Seed(time.Now().UTC().UnixNano())
	
	fmt.Printf("\n começando \n")

	c := make (chan int) 
	
	go calcula(1, c) 
	go calcula(2, c) 
	go calcula(3, c) 
	go calcula(4, c) 

	for i := 0; i < 5; i++ {		 //so consegue enviar outro num qdo o primeiro for retirado
		c  <- rand.Intn(1000) 			
	}
	
	fmt.Printf("\n terminando \n\n")
}



