/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Composant2.cpp
 * 
 * Created on 18 mars 2019, 17:40
 */

#include "Composant2.h"
#include <string>

using namespace std;




vector <Bloc> getBlocs() { vector <Bloc> x; return testi::bloc;}



int Wallet::getNbBlocMAx(vector<Bloc> blocs)
{
	int num = 0;

	for(Bloc b : blocs){

            if(num < b.num)  num = b.num;
			
	}

	return num;
}

vector <UTXO>  Wallet::getUTXO(Bloc b) {
    
        vector <UTXO> list;

        for(UTXO u: b.tx1.UTXOs ) list.push_back(u);

        return list;
    
}



float Wallet::getMontant(unsigned char publicKey[]) {
    
    
        vector <Bloc> blocs = getBlocs();
        
        float sum = 0;
        for (Bloc b : blocs) {
            
                vector <UTXO> list= getUTXO(b);
                for( UTXO u : list) {
                    
                    if(u.dest == publicKey) {
                        sum += u.montant;                      
                    }   
                    
                    
                }
                            
        }
           
    return sum;               
}



TX Wallet::createTransaction(unsigned char E_PrKey[], unsigned char E_PbKey[], unsigned char D_PbKey[KEY_SIZE], float montant) {
    
    
    
    if(Wallet::getMontant(E_PbKey) < montant ) TX() ;
    
    Bloc bloc;
    int numBloc = getNbBlocMAx(getBlocs());
    TXI txi ;
    UTXO utxo;
    

    txi.nBloc =  numBloc;
    txi.nTx = 1;
    txi.nUtxo = 2;
        pub_copy(utxo.dest,D_PbKey);

   utxo.montant = montant;
   utxo.montant = montant;

   TX transaction ;
   
   transaction.TXIs.push_back(txi);
   transaction.UTXOs.push_back(utxo);

   
   
   return transaction;
   



void pub_copy(unsigned char txt[],unsigned char D_PbKey[]) {
    
    int i=0;
    while(txt[i]!='\0') {
        D_PbKey[i]=txt[i];
        i++;
    }
}


