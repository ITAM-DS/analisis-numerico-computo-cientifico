import numpy as np


def normal_loglikelihood(params,data):
    mu = params[0]
    sigma = params[1]
    x = data
    n=len(data)
    
    loglikelihood=-(n/2)*np.log(2*np.pi)-(n/2)*np.log(sigma**2)-(1/(2*sigma**2))*np.sum((x-mu)**2)
    
    return -1*loglikelihood

def gradient_normal_loglike(params,data):
    mu = params[0]
    sigma = params[1]
    x=data
    n=len(data)
    dmu= (1/(sigma**2))*np.sum(x-mu)
    dsigma=-(n/2)*((2*sigma)/sigma**2)+(1/sigma**3)*np.sum((x-mu)**2)
    return -1*np.array([dmu,dsigma])


def gradient_descent(x,gradient,data,tol=.0001,maxiter=10000,step_size=.0001):
    x_old=x+10
    i=0
    points=list()
    while ((np.linalg.norm(x-x_old)>=tol)):
        if i==1000:
            break
        points.append(x)
        x_old=x
        x=x-step_size*gradient(x,data)
        i+=1
    return x


mean_analytic_normal=lambda x: sum(x)/len(x)

def std_analytic_normal(data, ddof=0):
     n = len(data)
     mean = sum(data) / n
     return np.sqrt(sum((x - mean) ** 2 for x in data) / (n - ddof))

def newton_raphson_model(modelo, tolerancia=1e-3, maxiter=1000, display=True):

    i = 0
    error = 100  # Initial error value

    # Print header of output
    if display:
        header = f'{"Iteration_k":<13}{"Log-likelihood":<16}{"θ":<60}'
        print(header)
        print("-" * len(header))

    while np.any(error > tolerancia) and i < maxiter:
        H, G = modelo.H(), modelo.G()
        β_new = modelo.β - (np.linalg.inv(H) @ G)
        error = β_new - modelo.β
        modelo.β = β_new

        # Print iterations
        if display:
            β_list = [f'{t:.3}' for t in list(modelo.β.flatten())]
            update = f'{i:<13}{modelo.logL():<16.8}{β_list}'
            print(update)

        i += 1

    print(f'Number of iterations: {i}')
    print(f'β_hat = {modelo.β.flatten()}')

    return modelo.β.flatten()
    
    
class Poisson:

    def __init__(self, y, X, β):
        self.X = X
        self.n, self.k = X.shape
        self.y = y.reshape(self.n,1)
        self.β = β.reshape(self.k,1)

    def μ(self):
        return np.exp(self.X @ self.β)

    def logL(self):
        y = self.y
        μ = self.μ()
        return np.sum(y * np.log(μ) - μ - np.log(factorial(y)))

    def G(self):
        y = self.y
        μ = self.μ()
        return X.T @ (y - μ)

    def H(self):
        X = self.X
        μ = self.μ()
        return -(X.T @ (μ * X))