function kron_δ(i,j)
    if i == j
        return 1
    else
        return 0
    end
end

function nbm_matrix(g::SimpleGraph)
    edgeidmap = Dict{Edge, Int}()
    aristas = ne(g)
    m = 0
    for e in edges(g)
        m += 1
        edgeidmap[e] = m
	edgeidmap[reverse(e)] = m + aristas
    end

    B = spzeros(Int64, 2*aristas, 2*aristas)


    for (e,u) in edgeidmap
        i, j = src(e), dst(e)
	eles = neighbors(g,j)
	k = j
        for l in eles
          B[edgeidmap[k=>l],u] = (kron_δ(j,k)*(1-kron_δ(i,l)))
        end
    end
    return B, edgeidmap
end
