
package main

import ("fmt" 
		"time" 
)


func main() {

	fmt.Printf("\n começando \n\n")

	go mostranumero(10)					//roda em paralelo em uma nova thread
	mostranumero(20)					//roda no prog 

	fmt.Printf("\n terminando \n\n")
}



func mostranumero(n int) {


	for k := 0; k < 5; k++ {
		fmt.Printf(" numero %d\n", n)
		time.Sleep(500 * time.Millisecond)
	}
}






// Goroutines
// -----------
// "go" define que a função será executada 
// em uma nova thread sem bloquear a função principal
