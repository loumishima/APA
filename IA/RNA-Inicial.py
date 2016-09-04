# encoding: utf-8


import random

class Perceptron:

	def __init__(self, amostras, saidas, taxa_aprendizado=0.1, epocas=1000, limiar=-1):

		self.amostras = amostras
		self.saidas = saidas 
		self.taxa_aprendizado = taxa_aprendizado # taxa de aprendizado (entre 0 e 1)
		self.epocas = epocas # número de épocas
		self.limiar = limiar
		self.num_amostras = len(amostras) # quantidade de amostras
		self.num_amostra = len(amostras[0]) # quantidade de elementos por cada amostra
		self.pesos = [] 


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

				
				y = self.sinal(u)
				#print(y)

				
				if y != self.saidas[i]:

					
					erro_aux = self.saidas[i] - y

					#ajuste de peso
					for j in range (self.num_amostra + 1):
						self.pesos[j] = self.pesos[j] + self.taxa_aprendizado * erro_aux * self.amostras[i][j]

					erro = True 
			
			num_epocas += 1

			
			if num_epocas > self.epocas or not erro:
				break


	
	def testar(self, amostra, classe1, classe2):

		# insere o -1
		amostra.insert(0, -1)

		u = 0
		for i in range(self.num_amostra + 1):
			u += self.pesos[i] * amostra[i]

		
		y = self.sinal(u)

		
		if y == -1:
			print('%s' % classe1)
		else:
			print('%s' % classe2)


	def sinal(self, u): 
		return 1 if u >= 0 else -1


if __name__ == "__main__":


	# todas as amostras (total de 4 amostras)
	amostras = [[0, 0], [0,1], 
				[1,0],[1,1]]

	# saídas desejadas de cada amostra
	saidas = [-1, -1, -1, 1]

	# conjunto de amostras de testes
	#testes = copy.deepcopy(amostras)
	print("entrada: 0010 e 0101")
	testes = [[0,0],[0,1],[1,0],[0,1]]

	rede = Perceptron(amostras=amostras, saidas=saidas, 
						taxa_aprendizado=0.1, epocas=1000)
	rede.treinar()

	for teste in testes:
		rede.testar(teste, '0', '1')
