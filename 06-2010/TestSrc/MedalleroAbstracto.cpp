#include "MedalleroAbstracto.h"

void CMedalleroAbstracto::mergeSort(CPareja< CPais, CMedallas > v[], int num) {
	CPareja< CPais, CMedallas > * aux = new CPareja< CPais, CMedallas >[num];
	mergeSortAux(v, aux, 0, num-1);
	delete [] aux;
}

void CMedalleroAbstracto::mergeSortAux(CPareja< CPais, CMedallas > v[], CPareja< CPais, CMedallas > aux[],int ini, int fin) {
	if (ini < fin) {
		int med = (ini + fin) / 2;
		mergeSortAux(v, aux, ini, med);
		mergeSortAux(v, aux, med+1, fin);
		
		int i = ini;
		int j = med+1;
		int k = ini;
	
		while ((i <= med) && (j<=fin)) {
			//Mezclamos:
			if (v[i].v2() < v[j].v2()) {
				aux[k] = v[i];
				i++;
				k++;
			} else {
				aux[k] = v[j];
				j++;
				k++;
			}
		}
		
		//Por si queda algo lo metemos tambien:
		for (i;i<=med;i++) {
				aux[k] = v[i];
				k++;
		}
		
		for (j;j<=fin;j++) {
				aux[k] = v[j];
				k++;
		}

		for (int i= ini;i<=fin;i++) {
			v[i] = aux[i];
		}
	}
}
