
package main

import ("fmt" 
        "time"
		"math/rand"
)


const TAM int = 5 
var vet [TAM]int
 

func main() {

	fmt.Printf("\n começando \n\n")

    inicializavetor()
 
    mostravetor()

	fmt.Printf("\n terminando \n\n")

}



 
func inicializavetor() {

    rand.Seed(time.Now().UTC().UnixNano())
	for i := 0; i < TAM; i++ {
        vet[i] = rand.Intn(100)  
    }

}







func mostravetor() {

	for k := 0; k < TAM; k++ {
            fmt.Printf("posicao %d  valor %d \n \n",k, vet[k])
    }
}

 












 


 