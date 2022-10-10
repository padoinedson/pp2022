

all: compile
	
compile:
	go build -o 1  1hello.go     
	go build -o 11 1var.go   
	go build -o 12 1varlaco.go   	  
	go build -o 2  2func.go  
	go build -o 21 2function.go  	
	go build -o 22 2goroutine.go     
	go build -o 3  3channel.go  
	go build -o 4  4channel.go  
	go build -o 5  5vetor.go  	
	go build -o 6  6vetorconcorrency.go  
	go build -o 7  7vetortopo.go  
	go build -o 8  8getruntime.go  
	go build -o 9  9goroutine.go
	go build -o 91  9keyboard.go


clean:
	find . -type f -executable -exec sh -c "file -i '{}' | grep -q 'x-executable; charset=binary'" \; -print | xargs rm -f


