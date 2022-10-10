
package main

import ("bufio"
    	"fmt"
    	"os"
)
 

func main() {

	fmt.Printf("\n começando \n\n")



	    reader := bufio.NewReader(os.Stdin)
	    fmt.Print("Digite um numero: ")
	    num, _ := reader.ReadString('\n')

	    fmt.Print("numero " + num)
    
    
	fmt.Printf("\n terminando \n\n")


}


 




 










 


 
