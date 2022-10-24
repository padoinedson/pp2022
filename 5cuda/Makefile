
all: compile
	
compile:
	clear

	gcc  -o 11		1a.c
	nvcc -o 12 		1a.cu
	nvcc -o 13 		1aerro.cu

	nvcc -o 14 		1cria_thread_na_gpu.cu
	nvcc -o 15 		1cria_thread_na_gpu2.cu

	nvcc -o 21 		2identifica_thread_na_gpu.cu
	nvcc -o 22 		2identifica_thread_na_gpu2.cu

	nvcc -o 23 		2variaveis_constant.cu
	nvcc -o 24 		2variaveis_device.cu
	nvcc -o 25 		2variaveis_managed.cu
	nvcc -o 26		2variaveis_managed2.cu
	nvcc -o 27 		2variaveis_shared.cu
	nvcc -o 28 		2variaveis_shared2.cu

	gcc  -o 31 		3lacos1.c
	nvcc -o 32		3lacos2.cu
	nvcc -o 33 		3lacos3.cu

	nvcc -o 41 		4incrementa_valor_na_gpu.cu 
	nvcc -o 42 		4soma_2valores_na_gpu.cu 

	nvcc -o 51 		5incrementa_vetor_na_gpu.cu 
	nvcc -o 52 		5soma_2vetores_na_gpu.cu

	nvcc -o 61 		6alimit.cu 
	nvcc -o 62 		6bnumber_of_blocks.cu 
	nvcc -o 63 		6cstride.cu 

	nvcc -o 71 		7grid1d.cu
	nvcc -o 72 		7grid2d.cu
	nvcc -o 73 		7grid3d.cu

	nvcc -o 81 		8warp.cu

	nvcc -o 91 		9a-get-device-properties.cu 
	nvcc -o 92 		9b-get-device-properties.cu 
	nvcc -o 93 		9c-get-device-properties.cu 

	@echo "Compilaçao concluida"

clean:
	rm -rf ?
	rm -rf ??
	rm -rf *.log
	rm -rf *.out





