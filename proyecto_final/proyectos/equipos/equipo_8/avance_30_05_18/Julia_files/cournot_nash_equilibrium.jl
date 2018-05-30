function fill_matrix_Q(n,beta)
	# Creamos y llenamos la matriz Q.
	Q = zeros(Int,n,n);
	for i in 1:size(Q)[1]
		for j in 1:size(Q)[2]
			if i == j
				Q[i,j] = 2*beta
			else
				Q[i,j] = beta
			end
		end
	end
	return Q;
end

function gd(n, lr, alpha, beta, gamma)
	#=
	Esta función permite calcular el equilibrio de Nash-Cournot del
	juego de Cournot por medio del método de descenso en gradiente.
	El equilibrio consiste en las cantidades x que los jugadores
	escogen como su mejor respuesta a las estrategiasd de los otros
	jugadores.

	Como se plantea en el documento escrito, el problema de Cournot
	es equivalente a solucionar el problema cuadrático convexo:

	min_X (1/2)X'QX + (gamma - alpha)'

	donde X es el vector de x_i's que queremos encontrar,
	Q es una matriz simétrica positiva definida y, por lo
	tanto, el problema tiene una solución óptima, que es
	el equilibrio de Nash-Cournot.
	=#

	cur_X = rand(n);
	#lr = 0.05;
	#precision = 0.00000001;
	#previous_step_size = 1 / precision;

	# Esta es la derivada del problema cuadrático:
	df = (X) -> transpose(X)*Q + transpose(gamma - alpha);

	# Creamos y llenamos la matriz Q.
	Q = fill_matrix_Q(n, beta);

	# Aquí es donde se lleva a cabo el descenso en gradiente:
	epochs = 0;
	max_iters = 100000;
	while epochs < max_iters
    #while previous_step_size > precision
		prev_X = cur_X;
		cur_X = cur_X -(lr * transpose(df(prev_X)));
		#previous_step_size = abs(cur_X .- prev_X);
		epochs += 1
        if cur_X - prev_X == zeros(n)
            break
        end

        # if mod(epochs,10000) == 0
        #     println(cur_X)
		# 	println("")
        #     println(cur_X - prev_X)
        # end
    end
    return cur_X, epochs
end

function run_cournot(n, lr, alpha, beta, gamma)
	X, epochs = gd(n, lr, alpha, beta, gamma)

	# Se imprimen los resultados:
	println("El equilibrio de Nash-Cournot es $X.")
	println("El equilibrio se alcanzó en $epochs iteraciones.")
end

# Ejemplo para correr el programa:
run_cournot(1,0.05,50,2,[2 for i in 1:1])
