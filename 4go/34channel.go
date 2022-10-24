
package main

import ("fmt" 
)


func main() {

	fmt.Printf("\n começando \n\n")



	c := make (chan int) 
	

	go geranumero(c)

	mostranumero(c)

	fmt.Printf("\n terminando \n\n")
}



 
func geranumero(c chan int) {

	c <- 50 
	c <- 100   //nao consegue colocar no canal até que o dado anterior seja retirado
	c <- 150
	c <- 200 
}

 

func mostranumero(c chan int) {

	vlr := <- c 								//bloqueante

	fmt.Printf(" numero gerado %d\n", vlr)

}


/*

se colocar as duas funçoes em paralelo a 
função principal não para/espera

*/
