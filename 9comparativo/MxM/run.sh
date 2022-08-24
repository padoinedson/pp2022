#!/bin/bash


		file_out=resultados.txt

		echo "INICIANDO " >> $file_out
		date >> $file_out


		hwloc-bind socket:0.pu:0-1 ./o >> $file_out


		echo "FINALIZANDO " >> $file_out
		date >> $file_out


