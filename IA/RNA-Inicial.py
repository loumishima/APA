# encoding: utf-8

import random, copy

class Perceptron:

    def __init__(self, amostras, saidas, taxa_aprendizado=0.1, epocas=1000, limiar=-1):

        self.amostras = amostras # todas as amostras
        self.saidas = saidas # saídas respectivas de cada amostra
        self.taxa_aprendizado = taxa_aprendizado # taxa de aprendizado (entre 0 e 1)
        self.epocas = epocas # número de épocas
        self.limiar = limiar # limiar
        self.num_amostras = len(amostras) # quantidade de amostras
        self.num_amostra = len(amostras[0]) # quantidade de elementos por cada amostra
        self.pesos = [] # vetor dos pesos


    def treinar(self):

        for amostra in self.amostras:
            amostra.insert(0, -1)

        for i in range(self.num_amostra):
            self.pesos.append(random.random())

        self.pesos.insert(0, self.limiar)

        num_epocas = 0 
        
        while True:

            erro = False 

            for i in range(self.num_amostras):
                
                u = 0
                '''
                    realiza o somatório, o limite (self.num_amostra + 1) 
                    é porque foi inserido o -1 em cada amostra
                '''
                for j in range(self.num_amostra + 1):
                    u += self.pesos[j] * self.amostras[i][j]

                y = self.degrau(u)


                if y != self.saidas[i]:

                    
                    erro_aux = self.saidas[i] - y

                   
                    for j in range (self.num_amostra + 1):
                        self.pesos[j] = self.pesos[j] + self.taxa_aprendizado * erro_aux * self.amostras[i][j]

                    erro = True 
            
            num_epocas += 1 

            
            if num_epocas > self.epocas or not erro:
                                for i in enumerate(self.pesos):
                                    print(i)
                                break


    def testar(self, amostra, classe1, classe2):

        
        amostra.insert(0, -1)

        '''
            utiliza-se o vetor de pesos ajustado
            durante o treinamento da rede
        '''
        u = 0
        for i in range(self.num_amostra + 1):
            u += self.pesos[i] * amostra[i]

       
        y = self.degrau(u)

       
        if y == 0:
            print('A amostra pertence a classe %s' % classe1)
        else:
            print('A amostra pertence a classe %s' % classe2)


    def degrau(self, u):
        return 1 if u >= 0 else 0


if __name__ == "__main__":


    print('\0 ou 1?\n')

    
    amostras = [[0, 0], [0,1], 
                [1,0], [1,1]]

    #para AND use essa saida
    saidas = [0, 0, 0, 1]
    
    #para OR use a saida
    #saidas = [0, 1, 1, 1]
    # conjunto de amostras de testes
    testes = copy.deepcopy(amostras)

  
    rede = Perceptron(amostras=amostras, saidas=saidas, 
                        taxa_aprendizado=0.1, epocas=1000)

    # treina a rede
    rede.treinar()

    for teste in testes:
        rede.testar(teste, '0', '1')
