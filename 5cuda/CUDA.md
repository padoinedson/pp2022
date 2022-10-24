# Programação Paralela
## NVIDIA CUDA




### CUDA C++ Programming Guide  

https://docs.nvidia.com/cuda/cuda-c-programming-guide/index.html


### CUDA C++ Best Practices Guide  

https://docs.nvidia.com/cuda/cuda-c-best-practices-guide/index.html


### CUDA Toolkit Documentation. NVIDIA DEVELOPER   

https://docs.nvidia.com/cuda/



## Fundamentals of Accelerated Computing C/C++  
### Accelerating Applications with CUDA C/C++  


video 1:
https://docs.google.com/presentation/d/e/2PACX-1vTdUbQjoEYAtcPCMX4ZVLa9gE0rbO3ODClJqgtzRaXoFgVmTJrOkXGDAYmA0BsuTEaokTASv84JsKLm/embed

video 2:
https://docs.google.com/presentation/d/e/2PACX-1vSMSXhghs_7I9MYbRGZEpGAdefCfJjDh8JivFF12Hn2kEBkJ4GDDk1vEvOcn4S31O8WS4METGyPYOTm/embed 

video 3:
https://docs.google.com/presentation/d/e/2PACX-1vSVS21bI-cje3Cqtxke-LHcvxk1ZxvZF-F35bgHSKfvNsvkGklCeqwlXHCDPJey5meZ1vTVYMqiF0UV/embed 

video 4:
https://docs.google.com/presentation/d/e/2PACX-1vSfi8LAinJ1RqTzlB2vRsAcDzCCk9gZov5rQODN5rtRMPt57UizCVv5LSVZ5WLxGtrsMm7FIkLb0wMR/embed

video 5:
https://docs.google.com/presentation/d/e/2PACX-1vTn2HX1FyUO94g5TxgBm0C7pu-_5UXPwYtMkhGLnqgs0-2Y1g8CE3YCuZuob25wrrXz0x8cT9_XxyBl/embed

video 6:
https://docs.google.com/presentation/d/e/2PACX-1vTSfcPagyv7ObRnhygFnKrvDIDa-wUuc3yR-qs7xd4gQxProMOqXzNqe8y9vz711cLIbPp1qYJc7R3l/embed

video 7:
https://docs.google.com/presentation/d/e/2PACX-1vQTzaK1iaFkxgYxaxR5QgHCVx1ZqhpX2F3q9UU6sGKCYaNIq6CGAo8W_qyzg2qwpeiZoHd7NCug7OTj/embed

video 8:
https://docs.google.com/presentation/d/e/2PACX-1vS0-BCGiWUb82r1RH-4cSRmZjN2vjebqoodlHIN1fvtt1iDh8X8W9WOSlLVxcsY747WVIebw13cDYBO/embed

video 9:
https://docs.google.com/presentation/d/e/2PACX-1vRVgzpDzp5fWAu-Zpuyr09rmIqE4FTFESjajhfZSnY7yVvPgZUDxECAPSdLko5DZNTGEN7uA79Hfovd/embed

video 10:
https://docs.google.com/presentation/d/e/2PACX-1vQdHDR62S4hhvq02CZreC_Hvb9y89_IRIKtCQQ-eMItim744eRHOK6Gead5P_EaPj66Z3_NS0hlTRuh/embed


### Compile a program font 

> $ nvcc fonte.cu -o exe 


### Compile and run a program font

> $ nvcc fonte.cu -o exe -run


### versão do driver 
> $ cat /proc/driver/nvidia/version


### versão do nvcc
> $ nvcc -V


### load da gpu 
> $ nvidia-smi


### settings da gpu 
> $ nvidia-settings


### exemplos da NVIDIA
> $ cd /usr/local/cuda-10.1/samples









## NVIDIA GPU Cloud (NGC)
https://www.nvidia.com/pt-br/gpu-cloud/


### NGC Catálogo/opções
https://ngc.nvidia.com/catalog

Query:hpc
https://ngc.nvidia.com/catalog?orderBy=scoreDESC&pageNumber=0&query=hpc&quickFilter=&filters=



### docker pull
> $ docker pull nvcr.io/nvidia/nvhpc:21.3-devel-cuda_multi-ubuntu20.04


### docker run
> $ sudo docker run -it nvcr.io/nvidia/nvhpc:21.3-devel-cuda_multi-ubuntu20.04 /bin/bash













## NVIDIA Container Toolkit



This is a quick-start for users who just want to get going.


Use the nvidia AMI on AWS ( 10 minutes): 
https://github.com/NVIDIA/nvidia-docker/wiki/Deploy-on-Amazon-EC2



Get started with nvidia-docker (5 minutes): 
https://github.com/NVIDIA/nvidia-docker



Get started with the CUDA development image (5 minutes): 
"docker pull nvidia/cuda:9.1-devel"
https://hub.docker.com/r/nvidia/cuda/ 





## DOWNLOADS

https://developer.nvidia.com/downloads



## CUDA Toolkit 11.4 Update 2 Downloads

https://developer.nvidia.com/cuda-downloads?target_os=Linux&target_arch=x86_64&Distribution=Ubuntu




# install driver GPU    



## CUDA Toolkit 11.5 Downloads

> https://developer.nvidia.com/cuda-downloads?target_os=Linux&target_arch=x86_64&Distribution=Ubuntu&target_version=20.04&target_type=deb_local  

steps:  


> wget https://developer.download.nvidia.com/compute/cuda/repos/ubuntu2004/x86_64/cuda-ubuntu2004.pin  
> sudo mv cuda-ubuntu2004.pin /etc/apt/preferences.d/cuda-repository-pin-600  
> wget https://developer.download.nvidia.com/compute/cuda/11.5.0/local_installers/cuda-repo-ubuntu2004-11-5-local_11.5.0-495.29.05-1_amd64.deb  
> sudo dpkg -i cuda-repo-ubuntu2004-11-5-local_11.5.0-495.29.05-1_amd64.deb  
> sudo apt-key add /var/cuda-repo-ubuntu2004-11-5-local/7fa2af80.pub  
> sudo apt-get update  
> sudo apt-get -y install cuda  



## CUDA Toolkit 10.1 Downloads  



> wget https://developer.download.nvidia.com/compute/cuda/repos/ubuntu1804/x86_64/cuda-ubuntu1804.pin  
> sudo mv cuda-ubuntu1804.pin /etc/apt/preferences.d/cuda-repository-pin-600  
> wget http://developer.download.nvidia.com/compute/cuda/10.1/Prod/local_installers/cuda-repo-ubuntu1804-10-1-local-10.1.243-418.87.00_1.0-1_amd64.deb  
> sudo dpkg -i cuda-repo-ubuntu1804-10-1-local-10.1.243-418.87.00_1.0-1_amd64.deb  
> sudo apt-key add /var/cuda-repo-10-1-local-10.1.243-418.87.00/7fa2af80.pub  
> sudo apt-get update  
> sudo apt-get -y install cuda  



## configurar/adicionar no bashrc

> $ nano `~/.bashrc`  
	`export PATH=$PATH:/usr/local/cuda-10.1/bin  `  
    `export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/cuda-10.1/lib  `  


## atualizar driver
> $ sudo apt-get remove nvidia-driver-418  
> $ sudo ubuntu-drivers autoinstall  
> $ sudo reboot  


