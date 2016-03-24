def estimatePrice(mileage, theta0, theta1):
	estimatedPrice = theta0 + (theta1 * mileage)
	return (estimatedPrice)

mileage = input("quel est le kilometrage ? ")
theta0 = 0
theta1 = 0
try: 
	fichier = open('result.txt', 'r')
	theta0 = fichier.readline()
	theta1 = fichier.readline()
	maxkm = fichier.readline()
	minkm = fichier.readline()
	maxp = fichier.readline()
	minp = fichier.readline()
	theta0 = float(theta0)
	theta1 = float(theta1)
	maxkm = float(maxkm)
	minkm = float(minkm)
	maxp = float(maxp)
	minp = float(minp)
	mileage = (mileage - minkm) / (maxkm - minkm)
	estimatedprice = estimatePrice(mileage, theta0,theta1)
	estimatedprice = estimatedprice * (maxp - minp) + minp
	print ("le prix estime est de ", estimatedprice)
	fichier.close()
except IOError:
	estimatedprice = estimatePrice(mileage, theta0,theta1)
	print ("Le prix estime est de ", estimatedprice)