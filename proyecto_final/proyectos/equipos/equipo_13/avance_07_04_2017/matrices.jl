function kron_δ(i,j)
    if i == j
        return 1
    else
        return 0
    end
end

function inv_degree(g,i)
    1/degree(g,i)
end

function NB_matrix(g::SimpleGraph)
	A = full(adjacency_matrix(g))
    ceros = zeros(A)
    D = zeros(A)
    menos = -1 * eye(A)
    for n in 1:nv(g)
        D[n,n] = degree(g,n)-1
    end
    sparse(hcat(vcat(ceros,menos),vcat(D,A)))
end

function mapa(g::SimpleGraph)
    edgeidmap = Dict{Edge, Int}()
    aristas = ne(g)
    m = 0
    for e in edges(g)
        m += 1
        edgeidmap[e] = m
        edgeidmap[reverse(e)] = m + aristas
    end
    edgeidmap, m, aristas
end

function flux_matrix(g::SimpleGraph)

    edgeidmap, m, aristas = mapa(g)

    B = zeros(Float64, 2*aristas, 2*aristas)

    for (e,u) in edgeidmap
        i, j = src(e), dst(e)
        eles = neighbors(g,j)
        k = j
        for l in eles
          B[edgeidmap[k=>l],u] = (kron_δ(j,k)*(1-kron_δ(i,l)))*(1/(degree(g,j)))
        end
    end
    return B, edgeidmap
end

function reluctant_matrix(g::SimpleGraph)

    edgeidmap, m, aristas = mapa(g)

    B = zeros(Float64, 2*aristas, 2*aristas)

    for (e,u) in edgeidmap
        i, j = src(e), dst(e)
        eles = neighbors(g,j)
        k = j
        for l in eles
          B[edgeidmap[k=>l],u] = (kron_δ(j,k)*(1-kron_δ(l,i)))+(kron_δ(j,k)*kron_δ(l,i)*inv_degree(g,j))
        end
    end
    return B, edgeidmap
end

function normalized_reluctant(g::SimpleGraph)

    edgeidmap, m, aristas = mapa(g)

    B = zeros(Float64, 2*aristas, 2*aristas)


    for (e,u) in edgeidmap
        i, j = src(e), dst(e)
        eles = neighbors(g,j)
        k = j
        for l in eles
          B[edgeidmap[k=>l],u] = ((kron_δ(i,l)*(1-kron_δ(j,k)))+(kron_δ(i,l)*kron_δ(j,k)*inv_degree(g,j)))*(1/((degree(g,i)-1)+inv_degree(g,j)))
        end
    end
    return B, edgeidmap
end
