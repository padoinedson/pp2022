
package main

import ("fmt" 
			"time" 
			"math/rand"
)


func main() {

	fmt.Printf("\n começando \n")

	c := make (chan int) 
	
	go geranumero(c)

	vlr2 := <- c 					//chamada bloqueante

	fmt.Printf("\n numero retirado do chan %d\n", vlr2)

	fmt.Printf("\n terminando \n\n")
}



 
func geranumero(c chan int) {

	time.Sleep(5 * time.Second)

	rand.Seed(time.Now().UTC().UnixNano())
	vlr:= rand.Intn(1000) 

	fmt.Printf("\n numero gerado na func %d\n", vlr)
	c  <- vlr

}

 



/*
Channels
----------

Abstração para viabilizar a comunicação entre as threads

Comando  "make" - cria um canal com o tipo da dado especificado Ex.:

 
	c := make (chan int)

Comando " <- " - envia um valor para o channel. Ex.:

  "c <- 10 "    


Comando " var := <- ch" - recebe um valor do channel. Ex.:
												-  esta função é bloqueante !!

  "vlr := <- c"   


*/
