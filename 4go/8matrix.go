
package main

import ("fmt" 
        "time"
		"math/rand"
)


const TAM int = 5 
var mat [TAM][TAM]int
 

func main() {

	fmt.Printf("\n começando \n\n")

    inicializamatriz()
 
    mostramatriz()

	fmt.Printf("\n terminando \n\n")

}



 
func inicializamatriz() {

    rand.Seed(time.Now().UTC().UnixNano())
	for i := 0; i < TAM; i++{
            for j := 0; j < TAM; j++ {
                mat[i][j] = rand.Intn(100)  
            }
    }
}







func mostramatriz() {

    for i := 0; i < TAM; i++ {
            for j := 0; j < TAM; j++ {
                fmt.Printf(" %2d ",mat[i][j])
            }
            fmt.Printf(" \n",)    
    }
}

 












 


 