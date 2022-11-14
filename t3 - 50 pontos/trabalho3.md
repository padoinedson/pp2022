# T3 - GPU CUDA - M x V = V

Data de entrega: 28/11  
Local de entrega: somente no portal  
Peso 50 pontos  
Individual  


## Descrição do trabalho:

- Desenvolver um programa que multiplique uma matriz por um vetor em paralelo na GPU.
Explicação: https://docs.google.com/spreadsheets/d/1U0M_DaIcyDOe5mbo4Vk5z1MdRGcwyXYbmgMzF0Eg55A/edit?usp=sharing

Este tipo de cálculo é utilizado em treinamento de IA:
https://www.youtube.com/watch?v=aircAruvnKk&list=PLZHQObOWTQDNU6R1_67000Dx_ZCJB-3pi


O programa deve ser compilado com nvcc e:

> criar um vetor C e uma matriz de L x C posições

> inicializar com números aleatórios

> criar N threads/kernels `CUDA` para utilizar todos os N cuda-cores disponíveis

> calcular matriz * vetor = vetor 

> entregar classroom da disciplina
 



## Entrega do trabalho:  

- arquivo zipado no portal contendo:  
	- codigo.cu  
	- explicação.txt - detalhes da implementação 


## Avaliação do trabalho:  

- 45 pontos - implementação  
-  5 pontos - explicação do trabalho  

