	
package main

import ("fmt"
		"time"
)


func main() {


	t0 := time.Now()
	time.Sleep(250 * time.Millisecond)
	t1 := time.Now()
	fmt.Printf("Tempo de execução : %v.\n", t1.Sub(t0))



	inicio := time.Now()
	for i := 1; i <= 10; i++ {
		executeTask(i)
	}
	fmt.Println("Tempo de execução :", time.Since(inicio))



}

func executeTask(i int) {
	fmt.Println("rodando thread", i)
	time.Sleep(250 * time.Millisecond)
}
