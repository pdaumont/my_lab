import csv
import matplotlib.pyplot as plt

with open('data.csv') as csvfile:
	reader = csv.DictReader(csvfile)
	my_dict = []
	my_dict2 = []
	for i in reader:
		my_dict.append(i)
	my_dict2 = my_dict[:]

def estimatePrice(mileage, theta0, theta1):
	estimatePrice = theta0 + (theta1 * mileage)
	return (estimatePrice)

def sumofept0(my_dict, i, theta0, theta1):
	n = 0
	sumofept0 = 0
	while n < i: 
		sumofept0 += estimatePrice(float(my_dict[n]['km']), theta0, theta1) - float(my_dict[n]['price'])
		n = n + 1
	return sumofept0

def sumofept1(my_dict, i, theta0, theta1):
	n = 0
	sumofept1 = 0
	while n < i: 
		sumofept1 += (estimatePrice(float(my_dict[n]['km']), theta0, theta1) - float(my_dict[n]['price'])) * float(my_dict[n]['km'])
		n = n + 1
	return float(sumofept1)

def computeErrorForGivenPoints(theta0, theta1, my_dict):
	totalerror = 0
	for i in range(0, len(my_dict)):
		totalerror += ((theta1 * float(my_dict[i]['km']) + theta0) - (float(my_dict[i]['price'])))**2
	totalerror = totalerror / len(my_dict)
	return totalerror

def gradient(my_dict, precision):
	learningRate = 0.01
	theta0 = 0
	theta1 = 0

	#scaling
	minimumkm = float(my_dict[0]['km'])
	maximumkm = float(my_dict[0]['km'])
	for x in range(0, len(my_dict)):
		minimumkm = min(minimumkm, float(my_dict[x]['km']))
		maximumkm = max(maximumkm, float(my_dict[x]['km']))
	for x in range(0, len(my_dict)):
		my_dict[x]['km'] = (float(my_dict[x]['km']) - minimumkm) / (maximumkm - minimumkm)
	minimump = float(my_dict[0]['price'])
	maximump = float(my_dict[0]['price'])
	for x in range(0, len(my_dict)):
		minimump = min(minimump, float(my_dict[x]['price']))
		maximump = max(maximump, float(my_dict[x]['price']))
	for x in range(0, len(my_dict)):
		my_dict[x]['price'] = (float(my_dict[x]['price']) - minimump) / (maximump - minimump)

	#gradient descent
	while computeErrorForGivenPoints(theta0, theta1, my_dict) > precision:
		tmptheta0 = learningRate *  1 / len(my_dict) * sumofept0(my_dict, len(my_dict), theta0, theta1)
		tmptheta1 = learningRate *  1 / len(my_dict) * sumofept1(my_dict, len(my_dict), theta0, theta1)
		theta0 = theta0 - tmptheta0
		theta1 = theta1 - tmptheta1
	
	#creating output file
	fichier = open('result.txt', 'w')
	fichier.write(str(theta0))
	fichier.write('\n')
	fichier.write(str(theta1))
	fichier.write('\n')
	fichier.write(str(maximumkm))
	fichier.write('\n')
	fichier.write(str(minimumkm))
	fichier.write('\n')
	fichier.write(str(maximump))
	fichier.write('\n')
	fichier.write(str(minimump))
	fichier.close

	#drawing points
	plt.figure(1)
	listekm = []
	listeprice = []
	for i in range(0, len(my_dict2)):
		listekm.append(my_dict2[i]['km'])
		listeprice.append(my_dict2[i]['price'])
	plt.plot(listekm, listeprice, 'ro')
	plt.axis([-0.1, 1.1, -0.1, 1.1])
	plt.title('nuage de points')
	plt.plot([-0.1, 1.1], [theta0, theta0 + theta1 * 1.1])
	plt.show()


precision = raw_input("souhaitez vous parametrer la precision? (y/n)")
if (precision == 'y'):
	precision = raw_input("entrer un nombre (precision maximale = 0.0206992, en dessous ne converge pas)")
	precision = float(precision) 
	gradient(my_dict, precision)
else:
	gradient(my_dict, 0.0206992)






