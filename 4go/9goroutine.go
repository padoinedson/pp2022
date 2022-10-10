
package main

import ("fmt" 
        "sync" 
)

var wg sync.WaitGroup     



func main() {

	fmt.Printf("\n começando \n\n")

    wg.Add(1)   
    go geranumero()
    wg.Add(1)   
    go geranumero()

    wg.Wait()   
	fmt.Printf("\n terminando \n\n")


}



 
func geranumero() {

 
    for true  {
            
            fmt.Printf(".",)

    }
    defer wg.Done()     
}






 










 


 