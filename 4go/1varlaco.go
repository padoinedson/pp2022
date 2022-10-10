
package main

import ("fmt"
        "math/rand"
)



// var global 
var x int


 
func main() {


   // var local 
   var y int = 2

    
    x = 1

    fmt.Printf("\nx = %d, y = %d \n", x, y)


    // declara e inicializa
    z := 3
    fmt.Printf("\nz = %d \n\n", z)



   for k := 0; k < 5; k++ {
      num := rand.Intn(100)
      fmt.Printf("numero gerado %d  \n",num)
   }

}


