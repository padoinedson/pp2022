
package main

import ("fmt" 
		"time" 
		"sync" 
		"math/rand"
)


const TAM int = 10
var vet [TAM]int
 



var wg sync.WaitGroup           			//waits for a collection of goroutines to finish.




func main() {

	fmt.Printf("\n começando \n\n")


		wg.Add(1)                    	//adds value to the WaitGroup counter.
		go geranumero(0)

		wg.Add(1)                    	//adds value to the WaitGroup counter.
		go geranumero(TAM/2)



	wg.Wait()							//Wait blocks until the WaitGroup counter is zero.


	mostravetor()


	fmt.Printf("\n terminando \n\n")


}



 
func geranumero(start int) {

    rand.Seed(time.Now().UTC().UnixNano())

	for i := start; i < start+TAM/2; i++ {
		time.Sleep(2 * time.Second)	
    	vet[i] = rand.Intn(100)  
        fmt.Printf("posicao %d  valor %d \n \n",i, vet[i])
	}

	defer wg.Done()						//decrements the WaitGroup counter by one.	
	
}


 






func mostravetor() {

	for k := 0; k < TAM; k++ {
            fmt.Printf("posicao %d  valor %d \n \n",k, vet[k])
    }
}

 



