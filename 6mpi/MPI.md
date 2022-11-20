# Programação Paralela


## Message Passing Interface (MPI) Documentation 
https://www.open-mpi.org/



https://computing.llnl.gov/tutorials/mpi/





## Steps to install openmpi



### Instalar g++
 
> $ sudo apt install g++  




### Download  

> $  cd ~  

> $ wget https://download.open-mpi.org/release/open-mpi/v4.0/openmpi-4.0.1.tar.gz  


> dicas:   
> baixar do site  	http://www.open-mpi.org/software/ompi/v1.6/  
>					http://www.open-mpi.org/software/ompi/  
>					* não baixar em pasta com espaços no nome Ex.: "Área de trabalho"  




### Install


> $ tar -xvf openmpi-4.0.1.tar.gz  

> $ sudo mkdir /usr/local/openmpi  

> $ cd openmpi-4.0.1  

> $ sudo ./configure --prefix /usr/local/openmpi  

> $ sudo make all install  

> $ cd ..  

> $ sudo rm -rf openmpi-4.0.1  

> $ rm openmpi-4.0.1.tar.gz  



###  Criar var ambiente:
 
Incluir PATH no arquivo .bashrc  
São duas opções: (escolha uma)  

a) $ `gedit ~/.bashrc`

ADICIONAR NO FINAL do arquivo:  
> 	LD_LIBRARY_PATH=/usr/local/openmpi/lib  
> 	export LD_LIBRARY_PATH  

> 	PATH=$PATH:/usr/local/openmpi/bin  
> 	export PATH  


b)  DIGITAR NO PROMPT

> $ echo 'export PATH=$PATH:/usr/local/openmpi/bin' >> /home/labinf/.bashrc  
> $ echo 'export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/openmpi/lib' >> /home/labinf/.bashrc
>> `troque labinf pelo seu username`  


###  Atualizar var do shell

São duas opções: (escolha uma)


a) digite:
> 	$ source ~/.bashrc


b) Fechar o terminal e abra novamente




### Compilar fontes

> $ mpicc nome_do_fonte




## Steps to run openmpi code

### Executar

> $ mpirun -np 2 ./a.out   

> onde 2 é o número de processos que serão criados   


### Executar especificando os micros na linha de comando

> $ mpirun -np 3 --host Aspire,Aspire,Aspire a.out	    
> $ mpirun -np 2 --host Aspire,Aspire a.out	  



### Executar com os micros em arquivo


> criar um arquivo com nome my-hosts e colocar Aspire Aspire Aspire (um em cada linha)

> $ mpirun -np 3 --hostfile my-hosts a.out


More info:
http://www.open-mpi.org/faq/?category=building

 


