
package main

import ("fmt" 
		"time" 
		"sync" 
		"math/rand"
)


var wg sync.WaitGroup           			//waits for a collection of goroutines to finish.


const TAM int = 10000
var vet [TAM]int
var topo int


func main() {

	fmt.Printf("\n começando \n\n")
	
    topo = 0


	wg.Add(1)                    	//adds value to the WaitGroup counter.
    go geranumero()
    go retiranumero()


    defer wg.Done()				    //decrements the WaitGroup counter by one.	
    wg.Wait()							//Wait blocks until the WaitGroup counter is zero.


	fmt.Printf("\n terminando \n\n")


}



 
func geranumero() {


 
    for true  {
        if topo < TAM {
            vet[topo] = rand.Intn(100)
            
            fmt.Printf("numero gerado %d topo %d \n \n",vet[topo], topo)
            topo ++

        } else {
                    time.Sleep(2 * time.Second)
        }
    }

}







func retiranumero() {

    for true  {
        if topo > 0 {
            
            fmt.Printf("numero consumido %d  topo %d \n \n",vet[topo], topo)
            topo --
        } else{
            time.Sleep(2 * time.Second) 
        }	
    }
}

 












 


 